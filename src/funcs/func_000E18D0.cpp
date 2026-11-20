struct Vector3 {
    float x;
    float y;
    float z;
};

// Three angles (x, y, z).
struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 position;
};

extern Object_000C1270 *data_00257CE4;

struct Object_000C1440 {
    int func_000C1450(int current, int target, int step);
};

// The object in data_00257CE8; it also answers func_000C1450.
struct Object_00157F10 : Object_000C1440 {
};

extern Object_00157F10 *data_00257CE8;

void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
    char unknown_5c[0x14];
    float reach;
    char unknown_74[0x30];
    unsigned int flags;
};

struct Limits_000CC020 {
    char unknown_00[0x24];
    int step;
};

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600();
};

// Shared by the classes of 0xD6350 and 0xE9380 (both called from their handlers).
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
    char unknown_0c[0x24];
    Limits_000CC020 *limits;
};

struct Object_000E0440 : Object_000CD1E0 {
    void func_000E1110();
    void func_000E18D0();
};

// Entry 5 of the handler table at 0x217DFC: with the owner's flag 0x4000000 goes to state 6; else turns the owner's
// heading toward the point at 0x7c of data_00257CE4 within its reach (slot 12, func_000CD390), levels its other
// two angles by the step at 0x24 of the limits (func_000C1450), and runs func_000E1110.
void Object_000E0440::func_000E18D0()
{
    if (!(owner->flags & 0x4000000)) {
        Angles_000C1300 angles;
        angles.x = 0;
        angles.y = owner->angles.y;
        angles.z = 0;
        Vector3 direction;
        func_0014C4C0(&direction, &owner->position, &data_00257CE4->position);
        func_000CD390((Vector3 *)&angles, owner->reach, &direction);
        owner->angles.y = angles.y;
        owner->angles.x = data_00257CE8->func_000C1450(owner->angles.x, 0, limits->step);
        owner->angles.z = data_00257CE8->func_000C1450(owner->angles.z, 0, limits->step);
        func_000E1110();
    } else {
        state = 6;
    }
}
