/* sym: ?func_000CD850@Object_000E0440@@UAEXXZ = 0x000E1780 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Motion_0005F060;

// The motions at 0xbc, two to a row.
struct Source_000E0440 {
    char unknown_00[0x14];
    Motion_0005F060 *motions[4][2];
};

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    float value_50;
    char unknown_54[4];
    float value_58;
    float value_5c;
    char unknown_60[0x3c];
    int value_9c;
    char unknown_a0[4];
    unsigned int flags;
};

struct Limits_000CC020 {
    char unknown_00[0x14];
    int value_14;
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
    char unknown_34[4];
    int column;
    int index;
    char unknown_40[0x28];
    int value_68;
};

// The class whose table is at 0x1CE804 (constructor func_000E0440).
struct Object_000E0440 : Object_000CD1E0 {
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000E0440();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0();
    virtual void func_000D7880();
    virtual int func_000CD390(Vector3 *position, float value, Vector3 *direction);

    int func_000E12C0();

    char unknown_06c[0xc];
    int row;
    char unknown_07c[0x40];
    Source_000E0440 *source;
    char unknown_0c0[4];
    Motion_0005F060 *motion;
    float time;
};

// Slot 7: once func_000E12C0 passes, starts the motion of the row at 0x78 and the column at 0x38 from the source at
// 0xbc, gives the owner flag 0x1000000 and moves to state 3.
void Object_000E0440::func_000CD850()
{
    if (func_000E12C0()) {
        motion = source->motions[row][column];
        time = 0.0f;
        owner->flags |= 0x1000000;
        state = 3;
    }
}
