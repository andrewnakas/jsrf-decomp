struct Vector3 {
    float x;
    float y;
    float z;
};

struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

float func_0014C820(float value);

struct Object_00157F10 {
    void func_000C1300(Angles_000C1300 *angles, Vector3 *point);
};

extern Object_00157F10 *data_00257CE8;

// The owner at 0x4: angles at 0x50, speed at 0x5c.
struct Object_000C5B50 {
    char unknown_00[0x50];
    Angles_000C1300 angles;
    float speed;
};

// A point of the path at 0x70.
struct Point_000CD440 {
    Vector3 position;
    char unknown_0c[0xc];
};

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// The class whose table is at 0x1CE364; slots 8 and 9 are pure.
struct Object_000CD1E0 : Object_000CC600 {
    Object_000CD1E0();
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0() = 0;
    virtual void func_000D7880() = 0;
    virtual float func_000CD440();
    virtual float func_000CD4F0();
    virtual int func_000CD390(Vector3 *position, float value, Vector3 *direction);

    Object_000C5B50 *owner;
    char unknown_08[0xc];
    Vector3 position;
    Vector3 direction;
    char unknown_2c[8];
    int step;
    char unknown_38[4];
    unsigned int index;
    char unknown_40[0x2c];
    unsigned int count;
    Point_000CD440 *points;
};

// Slot 11: like slot 10 on the ground plane: the x/z distance to the current path point (func_0014C820 of the
// squared length), the index step when slot 12 accepts it, and a move along the owner's angles by its speed on
// x and z only. Returns the distance.
float Object_000CD1E0::func_000CD4F0()
{
    Vector3 offset;
    offset.x = points[index].position.x - position.x;
    offset.y = 0.0f;
    offset.z = points[index].position.z - position.z;
    float distance = func_0014C820(offset.z * offset.z + offset.x * offset.x);
    if (func_000CD390((Vector3 *)&owner->angles, distance, &offset)) {
        index += step;
        if (index == -1)
            index = count - 1;
        else if (index >= count)
            index = 0;
    }
    data_00257CE8->func_000C1300(&owner->angles, &direction);
    position.x += owner->speed * direction.x;
    position.z += direction.z * owner->speed;
    return distance;
}
