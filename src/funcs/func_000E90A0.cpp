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
    Vector3 target;
};

extern Object_000C1270 *data_00257CE4;

// The object in data_00257CE8.
struct Object_00157F10 {
    void func_000C1300(Angles_000C1300 *angles, Vector3 *point);
};

extern Object_00157F10 *data_00257CE8;

float func_0014C820(float value);

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0x50];
    Angles_000C1300 angles;
    float speed;
    char unknown_60[0x44];
    unsigned int flags;
};

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
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

    void func_000CD310(float rate);
    void func_000E90A0();

    Object_000C5B50 *owner;
    char unknown_08[0xc];
    Vector3 position;
    Vector3 direction;
};

// Measures the flat distance from the position at 0x14 to the point at 0x7c of data_00257CE4; unless the owner has
// the flag 0x80, func_000CD310(1.7593); turns the owner toward the point by slot 12 (func_000CD390), takes the
// direction at 0x20 from the owner's angles (func_000C1300) and moves the position along it by the owner's speed.
void Object_000CD1E0::func_000E90A0()
{
    Vector3 delta;
    delta.x = data_00257CE4->target.x - position.x;
    delta.y = 0.0f;
    delta.z = data_00257CE4->target.z - position.z;
    float distance = func_0014C820(delta.z * delta.z + delta.x * delta.x);
    if (!(owner->flags & 0x80)) {
        func_000CD310(1.7592592f);
    }
    func_000CD390((Vector3 *)&owner->angles, distance, &delta);
    data_00257CE8->func_000C1300(&owner->angles, &direction);
    position.x += direction.x * owner->speed;
    position.z += direction.z * owner->speed;
}
