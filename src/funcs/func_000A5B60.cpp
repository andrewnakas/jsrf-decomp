struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);
float __fastcall func_0014CB60(const Vector3 *from, const Vector3 *to);

// The camera's collision model (only its address is used here).
struct Model_00018260 {
    char unknown_00[0x24];
};

// What func_00018260 reports (16 bytes, cleared first).
struct Hit_00018260 {
    float unknown_00[4];
};

struct Hits_000C4C60;

// A contact func_000194B0 picks: the points to move to at 0x2c (no face found) and 0x50 (a face found).
struct Contact_000C4A90 {
    char unknown_00[0x2c];
    Vector3 edge;
    char unknown_38[0x18];
    Vector3 face;
};

struct Object_00016200 {
    int func_00018260(Model_00018260 *model, Vector3 *from, Vector3 *to, Hit_00018260 *hit, int mask, int flags);
    int func_000194B0(Hits_000C4C60 *hits, Contact_000C4A90 **nearest);
};

extern Object_00016200 data_0022FCE8;

struct Node {
    Node *func_00011BD0();
};

// The camera's parent (the player): position 0xca4, speed 0xcd4, floor height 0xdfc, a reset request at 0xe5c.
struct Player_000A5B60 {
    char unknown_000[0xca4];
    Vector3 position;
    char unknown_cb0[0x24];
    float speed;
    char unknown_cd8[0x124];
    float floor;
    char unknown_e00[0x5c];
    int reset;
};

struct Object_000A4D80 {
    char unknown_000[0xbc];
    Model_00018260 model;
    int blocked;
    float lift;
    float distance;
    char unknown_0ec[0x7c];
    unsigned int airTime;
    char unknown_16c[0x78];
    Vector3 target;
    Vector3 anchor;
    int roll;
    int turn;
    int route;
    int mode;
    Vector3 position;
    Vector3 focus;
    int roll_224;
    int unknown_228;
    unsigned int fov_22c;
    char unknown_230[4];
    int unknown_234;
    int started;

    void func_000A32B0(Vector3 *first, Vector3 *second);
    void func_000A3360(Vector3 *eye, Vector3 *focus);
    void func_000A35E0(Vector3 *out, Vector3 *center);
    void func_000A3890(Vector3 *out, Vector3 *center);
    void func_000A5390(Vector3 *eye, Vector3 *focus);
    void func_000A5620(Vector3 *eye, Vector3 *focus);
    void func_000A5B60();
};

// The camera's frame for the modes of data_002155AC that run it (func_000A6100): the eye and focus of the mode
// (func_000A35E0 for 5, func_000A3890 for 4, func_000A5390 for 9, func_000A5620 for 13, else func_000A3360). In mode 3
// on the floor the lift at 0xe4 rises by 0.5 (to 30) while the point 30 ahead of the player toward the focus is
// blocked and falls by 0.5 (to 0) once the floor is lower; elsewhere it follows the player being 5 under the floor.
// On a reset (0xe5c, not in mode 13) both start again (func_000A32B0). The focus and the target then move a fifth
// of the way, the eye is lifted and kept out of walls (func_00018260, func_000194B0), and the distance and angles
// are kept at 0xe8, 0x224 and 0x22c.
void Object_000A4D80::func_000A5B60()
{
    Player_000A5B60 *player = (Player_000A5B60 *)((Node *)this)->func_00011BD0();
    Vector3 eye;
    Vector3 center;
    switch (mode) {
    case 5:
        func_000A35E0(&eye, &center);
        break;
    case 4:
        func_000A3890(&eye, &center);
        break;
    case 9:
        func_000A5390(&eye, &center);
        break;
    case 13:
        func_000A5620(&eye, &center);
        break;
    default:
        func_000A3360(&eye, &center);
        break;
    }
    Hit_00018260 hit;
    if (player->position.y == player->floor && mode == 3) {
        Vector3 direction;
        direction.x = anchor.x - target.x;
        direction.y = 0.0f;
        direction.z = anchor.z - target.z;
        func_0014C410(&direction, &direction);
        Vector3 ahead;
        ahead.x = direction.x * 30.0f + player->position.x;
        ahead.y = player->position.y - 5.0f;
        ahead.z = direction.z * 30.0f + player->position.z;
        if (player->speed >= 0.9259259f) {
            airTime = 0;
        }
        if (data_0022FCE8.func_00018260(&model, &anchor, &ahead, &hit, 0x33b7, -1)) {
            if (player->floor > player->position.y) {
                lift += 0.5f;
                if (lift > 30.0f) {
                    lift = 30.0f;
                }
            } else {
                lift -= 0.5f;
                if (lift < 0.0f) {
                    lift = 0.0f;
                }
            }
            airTime = 0;
        } else {
            airTime++;
            if (airTime > 60) {
                lift += 0.5f;
                if (lift > 30.0f) {
                    lift = 30.0f;
                }
            }
        }
    } else {
        if (player->floor - 5.0f > player->position.y) {
            lift += 0.5f;
            if (lift > 30.0f) {
                lift = 30.0f;
            }
        } else {
            lift -= 0.5f;
            if (lift < 0.0f) {
                lift = 0.0f;
            }
        }
    }
    if (player->reset && mode != 13) {
        func_000A32B0(&target, &anchor);
        position = target;
        focus = anchor;
        eye = target;
        center = anchor;
        if (!started) {
            unknown_234 = unknown_228;
            started = 1;
        }
        player->reset = 0;
    }
    Vector3 *to = &anchor;
    to->x += (center.x - to->x) * 0.2f;
    to->y += (center.y - to->y) * 0.2f;
    to->z += (center.z - to->z) * 0.2f;
    focus = anchor;
    Vector3 *from = &target;
    Vector3 previous = *from;
    from->x += (eye.x - from->x) * 0.2f;
    from->y += (eye.y - from->y) * 0.2f;
    from->z += (eye.z - from->z) * 0.2f;
    Vector3 *at = &position;
    position = target;
    position.y += lift;
    Contact_000C4A90 *contact;
    if (blocked) {
        if (data_0022FCE8.func_00018260(&model, &focus, at, &hit, 0x33b7, -1)) {
            if (data_0022FCE8.func_000194B0((Hits_000C4C60 *)&hit, &contact)) {
                *at = contact->face;
            } else {
                *at = contact->edge;
            }
        } else {
            blocked = 0;
        }
    } else if (data_0022FCE8.func_00018260(&model, &previous, from, &hit, 0x33b7, -1)
               && data_0022FCE8.func_00018260(&model, &focus, at, &hit, 0x33b7, -1)) {
        blocked = 1;
        if (data_0022FCE8.func_000194B0((Hits_000C4C60 *)&hit, &contact)) {
            if (contact) {
                *at = contact->face;
            }
        } else if (contact) {
            *at = contact->edge;
        }
    }
    distance = func_0014CB60(from, to);
    roll_224 = roll;
    fov_22c = turn;
}
