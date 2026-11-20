/* sym: ?func_00011C90_1@Object_000BF340@@UAEXXZ = 0x000BFA20 */
struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C90_5();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C90_9();
    virtual void func_00011C80_4(int argument);

    unsigned int flags;
    int id;
    unsigned int mask;
    float depth;
    int sortKey;
    char unknown_18[0xc];
    Node *parent;
    Node *child;
    Node *previous;
    Node *next;
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

struct Vector3 {
    float x;
    float y;
    float z;
};

// What data_0022FCE8 found touching an item: free while the first word is 0; a motion at 8 and a direction at 0x2c.
struct Touch_000B94B0 {
    int busy;
    char unknown_04[4];
    Vector3 motion;
    char unknown_14[0x18];
    Vector3 direction;
    Touch_000B94B0 *next;
};

// What func_000B99E0 tells of the first touch in state 0 or 1 (0x30 bytes).
struct Info_000B99E0 {
    char unknown_00[0xc];
    int heading;
    Vector3 motion;
    float speed;
    Vector3 direction;
    float cross;
};

// One of the faces of the shape at 0x198 (0x108 bytes): its kind at 0x24.
struct Face_000BFA20 {
    char unknown_00[0x24];
    unsigned char kind;
    char unknown_25[0xe3];
};

// The part of the collision item func_0001B5C0 tests: its faces and two counts, at +0x4 and +0x14.
struct Shape_000EC910 {
    Face_000BFA20 *faces;
    unsigned int first;
    char unknown_08[0xc];
    unsigned int second;
    char unknown_18[0xc];
};

struct Sphere_000EC910;

// A contact func_000194B0 picks: how far to push out of a face at 0x3c, of an edge at 0x60.
struct Contact_000C4A90 {
    char unknown_00[0x3c];
    Vector3 push;
    char unknown_48[0x18];
    Vector3 edgePush;
};

struct Hits_000C4C60 {
    Contact_000C4A90 *contacts;
    unsigned int count;
    Contact_000C4A90 *others;
    unsigned int otherCount;
};

struct Object_00016200 {
    int func_0001B5C0(Shape_000EC910 *shape, Sphere_000EC910 *sphere, int radius, int *hit, int mask, int limit);
    int func_000194B0(Hits_000C4C60 *hits, Contact_000C4A90 **nearest);
};

extern Object_00016200 data_0022FCE8;

int func_000B99E0(Touch_000B94B0 **touches, Info_000B99E0 *info);
void __fastcall func_0014CCF0(Vector3 *out, const Vector3 *in, int angle);
float func_0014C7F0(float value);
int func_000BA800(int bank, int kind, int sound, void *position, int handle);

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CDBA0; constructor
// func_000BF0C0).
struct Object_000BF340 : Node {
    virtual void func_00011C90_1();

    char unknown_040[4];
    unsigned int flags_44;
    char unknown_048[4];
    unsigned int state;
    int seen;
    int posed;
    int set;
    char unknown_05c[0x30];
    int sound;
    char unknown_090[4];
    float lift;
    float push;
    char unknown_09c[0x24];
    void *active;
    void *first;
    char unknown_0c8[0x18];
    Vector3 position;
    char unknown_0ec[0x18];
    Vector3 center;
    Vector3 previous;
    Vector3 velocity;
    int radius;
    char unknown_12c[0x6c];
    Shape_000EC910 shape;
    Hits_000C4C60 hits;
    char unknown_1cc[0xc];
    Touch_000B94B0 *touches;
};

// Slot 2. State 1, when seen and posed: a touch moving faster than 0.5 (func_000B99E0) launches it, sideways from
// the touch's motion (turned a quarter toward its side, func_0014CCF0) scaled by the entry's push and the speed, and
// up by 1.5 less the side (times the entry's lift when fast); state 3, the first motion, the entry's sound. States 3
// and 4 push it out of the world (bit 0 or 1 of a touched face's kind means state 1 again) or, untouched, nudge it by
// a touch (a fifth as much; the lift only in state 3). The last centre follows; 0x50 and 0x54 are cleared.
void Object_000BF340::func_00011C90_1()
{
    switch (state) {
    case 1:
        if (seen && posed) {
            Vector3 side;
            Info_000B99E0 info;
            if (func_000B99E0(&touches, &info) == 1 && info.speed > 0.5f) {
                if (info.cross < 0.0f) {
                    func_0014CCF0(&side, &info.motion, 0x4000);
                } else {
                    func_0014CCF0(&side, &info.motion, -0x4000);
                }
                velocity.x = (side.x * push) * info.speed;
                float up = 1.5f - func_0014C7F0(info.cross);
                if (info.speed > 0.5f) {
                    velocity.y = func_0014C7F0(up * lift * info.speed);
                } else {
                    velocity.y = func_0014C7F0(up * info.speed);
                }
                velocity.z = (side.z * push) * info.speed;
                state = 3;
                if (flags_44 & 0x20000000) {
                    flags_44 &= ~0x20000000;
                    active = first;
                }
                if (sound != -1) {
                    func_000BA800(set, 0, sound, &position, -1);
                }
            }
        }
        break;
    case 3:
    case 4:
        if ((shape.first > 0 || shape.second > 0) &&
            data_0022FCE8.func_0001B5C0(&shape, (Sphere_000EC910 *)&center, radius, (int *)&hits, 0xffff, -1)) {
            Contact_000C4A90 *nearest;
            if (data_0022FCE8.func_000194B0(&hits, &nearest)) {
                position.x += nearest->edgePush.x;
                position.y += nearest->edgePush.y;
                position.z += nearest->edgePush.z;
            } else {
                position.x += nearest->push.x;
                position.y += nearest->push.y;
                position.z += nearest->push.z;
            }
            for (unsigned int i = 0; i < shape.first; i++) {
                if (shape.faces[i].kind & 3) {
                    state = 1;
                }
            }
        } else {
            Vector3 side;
            Info_000B99E0 info;
            if (func_000B99E0(&touches, &info) == 1) {
                if (info.cross < 0.0f) {
                    func_0014CCF0(&side, &info.motion, 0x4000);
                } else {
                    func_0014CCF0(&side, &info.motion, -0x4000);
                }
                velocity.x += (side.x * push) * info.speed * 0.2f;
                if (state == 3) {
                    velocity.y += func_0014C7F0(info.speed * lift * 0.01f);
                }
                velocity.z += (side.z * push) * info.speed * 0.2f;
                if (sound != -1) {
                    func_000BA800(set, 0, sound, &position, -1);
                }
            }
        }
        previous = center;
        break;
    }
    seen = 0;
    posed = 0;
}
