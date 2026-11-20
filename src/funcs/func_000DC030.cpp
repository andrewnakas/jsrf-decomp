struct Vector3 {
    float x;
    float y;
    float z;
};

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 {
    void func_000C1E60();
};

extern Object_00157F10 *data_00257CE8;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

struct Node;

void func_000C4B70(int kind);
void func_000C70A0(Node *owner, Vector3 *position, int kind);
void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    int angle_50;
    int heading;
    int angle_58;
    float value_5c;
    char unknown_60[0x3c];
    int value_9c;
    char unknown_a0[4];
    unsigned int flags;

    int func_000C5B10(int message, void *data);
    void func_000C5B50(int *handle);
};

struct Limits_000CC020 {
    char unknown_00[0x18];
    float range;
};

// A point of the path at 0x70 (24 bytes).
struct Point_000DB8F0 {
    char unknown_00[0xc];
    float value_0c;
    char unknown_10[8];
};

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600();
};

struct Object_000CD1E0 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual ~Object_000CD1E0();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0() = 0;
    virtual void func_000D7880() = 0;
    virtual float func_000CD440();
    virtual float func_000CD4F0();
    virtual int func_000CD390(Vector3 *position, float value, Vector3 *direction);

    Object_000C5B50 *owner;
    int state;
    int unknown_0c;
    int timer;
    Vector3 position;
    char unknown_20[0x10];
    Limits_000CC020 *limits;
    char unknown_34[8];
    int index;
    char unknown_40[0x28];
    int value_68;
};

// The class whose table is at 0x1CE780 (constructor func_000DB8F0).
struct Object_000DB8F0 : Object_000CD1E0 {
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000DB8F0();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0();
    virtual void func_000D7880();
    virtual int func_000CD390(Vector3 *position, float value, Vector3 *direction);

    void func_000DC030();

    char unknown_06c[4];
    Point_000DB8F0 *path;
    char unknown_074[0xe0];
    int handle_154;
    int handle_158;
};

// A handler of the table at 0x217790: kind 2 of func_000C4B70 inside a matrix placed at the owner and turned by its
// angles (the heading half a turn round), kind 2 at its position (func_000C70A0) and sound 0x32 there; then state 6,
// the timer and the owner's 0x5c cleared, the owner releases the handles at 0x154 and 0x158 that are set, gets
// message 3 with its position and func_000C1E60 runs on data_00257CE8.
void Object_000DB8F0::func_000DC030()
{
    func_001BA9C0();
    func_001BAAA0(&owner->position.x);
    func_001BB330(owner->heading + 0x8000);
    func_001BB2E0(owner->angle_50);
    func_001BB380(owner->angle_58);
    func_000C4B70(2);
    func_001BAA50();
    func_000C70A0(0, &owner->position, 2);
    Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (object) {
        object->func_000651E0(0x32, &owner->position, 0);
    }
    state = 6;
    timer = 0;
    owner->value_5c = 0.0f;
    if (handle_154) {
        owner->func_000C5B50(&handle_154);
    }
    if (handle_158) {
        owner->func_000C5B50(&handle_158);
    }
    owner->func_000C5B10(3, &owner->position);
    data_00257CE8->func_000C1E60();
}
