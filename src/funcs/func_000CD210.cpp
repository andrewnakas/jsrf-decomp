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

struct Object_000C1440 {
    int func_000C1450(int current, int target, int step);
};

// The object at data_00257CE8 (func_00157F10 is the engine's); it also answers func_000C1450.
struct Object_00157F10 : Object_000C1440 {
    void func_000C1F20(Angles_000C1300 *angles, Vector3 *direction, int step);
};

extern Object_00157F10 *data_00257CE8;

struct Object_00046670 {
    float func_000466C0(Vector3 *position, int index);
};

extern Object_00046670 data_001F93C8;

// The owner at 0x4: a position at 0x44, angles at 0x50, speed at 0x5c and flags at 0xa4.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
    float speed;
    int value_60;
    char unknown_64[0x40];
    unsigned int flags;
};

// A point of the path at 0x70.
struct Point_000CD440 {
    Vector3 position;
    char unknown_0c[8];
    int value_14;
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

    Object_000C5B50 *owner;
    int state;
    char unknown_0c[8];
    Vector3 position;
    char unknown_20[0xc];
    float value_2c;
    char unknown_30[4];
    int step;
    int value_38;
    unsigned int index;
    char unknown_40[0x10];
    int value_50;
    int value_54;
    char unknown_58[0xc];
    int value_64;
    char unknown_68[8];
    Point_000CD440 *points;
};

// Slot 5: starts the path. Index, step and 0x38 become 1, 0x50 and 0x54 take the words at 0x14 of the first and the
// current point; the owner stops (0x5c and 0x60 cleared), gains flags 0x420000 and, like the position at 0x14, is
// put on the first point; its angles turn toward the second point (func_000C1F20, step 0x8000). Then 0x64 is
// cleared, the state becomes 1 and 0x2c takes the owner's ground height (func_000466C0 of data_001F93C8).
void Object_000CD1E0::func_000CD210()
{
    index = 1;
    step = 1;
    value_38 = 1;
    value_50 = points->value_14;
    owner->value_60 = 0;
    owner->speed = 0.0f;
    owner->flags |= 0x420000;
    value_54 = points[index].value_14;
    position = points->position;
    owner->position = points->position;
    Vector3 target = points[1].position;
    Vector3 offset;
    offset.x = target.x - position.x;
    offset.y = target.y - position.y;
    offset.z = target.z - position.z;
    data_00257CE8->func_000C1F20(&owner->angles, &offset, 0x8000);
    value_64 = 0;
    state = 1;
    value_2c = data_001F93C8.func_000466C0(&owner->position, -1);
}
