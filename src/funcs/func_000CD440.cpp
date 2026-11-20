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

void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
float __fastcall func_0014C6B0(const Vector3 *v);
void __fastcall func_0014C730(Vector3 *point, Vector3 *direction, float distance);

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

// Slot 10: the distance from the position at 0x14 to the current path point (func_0014C4C0, func_0014C6B0). When
// slot 12 accepts it, the index at 0x3c moves on by the step at 0x34, wrapping at either end of the count at 0x6c.
// Then the position moves along the owner's angles (func_000C1300 into 0x20) by the owner's speed
// (func_0014C730). Returns the distance.
float Object_000CD1E0::func_000CD440()
{
    Vector3 offset;
    func_0014C4C0(&offset, &points[index].position, &position);
    float distance = func_0014C6B0(&offset);
    if (func_000CD390((Vector3 *)&owner->angles, distance, &offset)) {
        index += step;
        if (index == -1)
            index = count - 1;
        else if (index >= count)
            index = 0;
    }
    data_00257CE8->func_000C1300(&owner->angles, &direction);
    func_0014C730(&position, &direction, owner->speed);
    return distance;
}
