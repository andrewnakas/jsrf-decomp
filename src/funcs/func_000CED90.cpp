/* sym: ?func_000CD1E0@Object_000CE9D0@@UAEXXZ = 0x000CED90 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_00047470 {
    void func_00047970(void *motion, int frame);
    void func_000480C0(unsigned int flags);
};

// The models of a behaviour: the body first.
struct Models_000CED90 {
    Object_00047470 *body;
};

struct Object_000C1440 {
};

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 : Object_000C1440 {
    void func_000C1EA0(int handle);
};

extern Object_00157F10 *data_00257CE8;

// The camera object at data_00257CE4: a height at 0x80.
struct Object_000C1270 {
    char unknown_00[0x80];
    float height;
};

extern Object_000C1270 *data_00257CE4;

// The object a behaviour serves: flags at 0xa4, its position at 0x44, its turn at 0x54.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    int unknown_50;
    int angle;
    char unknown_58[0x4c];
    unsigned int flags;

    int func_000C5B10(int kind, void *data);
};

struct Record_00015D10 {
    Vector3 center;
    float radius;
};

struct Object_00015D50 {
    virtual ~Object_00015D50();

    void func_00015520();
    void func_00015D10(const Record_00015D10 *record);
};

struct Object_0003E750 {
    void func_0003F410(int handle, int on);
};

extern Object_0003E750 data_002314B0;

// The same object as seen by func_000D0A80.
struct Object_000D0680 {
    void func_000D0A80();
};

// Two points in the body's frame.
extern Vector3 data_002166AC;
extern Vector3 data_002166A0;

void func_001BAA00();
void func_001BA9C0();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB330(int angle);
void func_001BB2B0(float scale);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAA50();

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual ~Object_000CC600() {}
};

// The behaviour func_000CE9D0 builds (0x140 bytes, table 0x1CE3A0); 0x4 holds the object it serves.
struct Object_000CE9D0 : Object_000CC600 {
    virtual void func_000CD1E0();

    Object_000C5B50 *owner;
    unsigned int state;
    char unknown_0c[0x24];
    Vector3 position;
    int angle;
    char unknown_40[4];
    unsigned int kind;
    int timer;
    char unknown_4c[0xc];
    Models_000CED90 *models;
    char unknown_5c[4];
    Object_00015D50 *first;
    Object_00015D50 *second;
    char unknown_68[0x10];
    void *frame;
    char unknown_7c[0x94];
    int effect;

    void func_000CE5A0();
};

// The state handlers, by the state at 0x8.
extern void (Object_000CE9D0::*data_002165F0[])();

// Slot 0 (the frame): flags the owner 0x1000000 (and starts its effect 8) while it is more than 15 below the camera's
// height, else clears it; copies the owner's position and turn, runs the handler for the state, counts 0x48 down and
// runs func_000D0A80. On a matrix at the owner turned by its angle plus 0x8000 and scaled by 2 the body is posed at
// 0x78, the collision parts 0x60 (part 10) and 0x64 (spheres 3.16 and 3.48 round data_002166AC and data_002166A0 in
// parts 1 and 2, then part 9) are updated. Unless the owner's flag 0x8000000 is set, func_000CE5A0 runs and the sound
// at 0x110 is switched on from kind 2 on (part 8, func_000C1EA0) or off.
void Object_000CE9D0::func_000CD1E0()
{
    if (owner->position.y - 15.0f < data_00257CE4->height) {
        if (!(owner->flags & 0x1000000)) {
            owner->func_000C5B10(8, &owner->position);
            owner->flags |= 0x1000000;
        }
    } else {
        owner->flags &= ~0x1000000;
    }
    position = owner->position;
    angle = owner->angle;
    (this->*data_002165F0[state])();
    timer--;
    ((Object_000D0680 *)this)->func_000D0A80();
    func_001BAA00();
    func_001BAAA0(&owner->position.x);
    func_001BB330(owner->angle + 0x8000);
    func_001BB2B0(2.0f);
    Object_00047470 *body = models->body;
    body->func_00047970(frame, 0);
    func_001BA9C0();
    body->func_000480C0(10);
    first->func_00015520();
    body->func_000480C0(1);
    Record_00015D10 sphere;
    func_001BAB20(&sphere.center, &data_002166AC);
    sphere.radius = 3.1603f;
    second->func_00015D10(&sphere);
    body->func_000480C0(2);
    func_001BAB20(&sphere.center, &data_002166A0);
    sphere.radius = 3.4805f;
    second->func_00015D10(&sphere);
    body->func_000480C0(9);
    second->func_00015520();
    func_001BAA50();
    if (!(owner->flags & 0x8000000)) {
        func_000CE5A0();
        if (effect != -1) {
            if (kind >= 2) {
                body->func_000480C0(8);
                data_002314B0.func_0003F410(effect, 1);
                data_00257CE8->func_000C1EA0(effect);
            } else {
                data_002314B0.func_0003F410(effect, 0);
            }
        }
    }
    func_001BAA50();
}
