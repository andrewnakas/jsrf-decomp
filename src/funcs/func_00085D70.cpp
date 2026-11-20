struct Vector3 {
    float x;
    float y;
    float z;
};

// A player (object 4 and on): its position at +0xca4.
struct Object_000A1C50 {
    char unknown_0000[0xca4];
    Vector3 position;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// A record of the tables at 0x20D960, 0x20D974 and 0x20D988.
struct Motion_00085F80 {
    float speed;
    float lift;
    float fall;
    int unknown_0c;
    float unknown_10;
};

extern Motion_00085F80 data_0020D960;

float __fastcall func_0014C460(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
float __fastcall func_0014C530(const Vector3 *a, const Vector3 *b);

// Object 0x50 (table 0x1CD0C0).
struct Object_00086060 {
    char unknown_000[0x48];
    Vector3 start;
    char unknown_054[0x18];
    Vector3 direction;
    char unknown_078[0xc];
    float speed;
    float lift;
    char unknown_08c[8];
    int countdown;
    int target;
    unsigned int flags;
    char unknown_0a0[4];
    Motion_00085F80 *motion;

    void func_00085D70();
};

// Handler 1 of the table at 0x20D9C8: sets flags 0xd, takes the speed of the old motion, a countdown of 10 and the
// motion at 0x20D960. With flag 2 the direction becomes the flat way from the player with the id at +0x98 to the
// start (straight along z when there is no way or no player); the lift is the motion's lift, scaled by the player's
// distance over 150 while nearer than that.
void Object_00086060::func_00085D70()
{
    flags |= 0xd;
    speed = motion->speed;
    countdown = 10;
    motion = &data_0020D960;
    Object_000A1C50 *player = (Object_000A1C50 *)data_0022FCE0->func_000128C0(target);
    float scale = 1.0f;
    if (player) {
        if (flags & 2) {
            Vector3 way;
            func_0014C4C0(&way, &player->position, &start);
            way.y = 0.0f;
            if (func_0014C460(&way, &way) > 0.0f) {
                direction = way;
            } else {
                direction.x = 0.0f;
                direction.z = 1.0f;
            }
        }
        flags &= ~2;
        float distance = func_0014C530(&player->position, &start);
        if (distance < 150.0f) {
            scale = distance * 0.0066666668f;
        } else {
            scale = 1.0f;
        }
    } else if (flags & 2) {
        direction.x = 0.0f;
        direction.z = 1.0f;
    }
    lift = scale * motion->lift;
}
