/* sym: ?func_000CD1E0@Object_000D27F0@@UAEXXZ = 0x000D2B90 */
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

// An axis and an angle (func_001BAC70 reads the angle at 0xc).
struct Rotation_000D2B90 {
    Vector3 axis;
    int angle;
};

struct Object_0003E750 {
    void func_0003F410(int key, int value);
};

extern Object_0003E750 data_002314B0;

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 {
    void func_000C1EA0(int key);
};

extern Object_00157F10 *data_00257CE8;

void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAC70(Rotation_000D2B90 *rotation);
void __fastcall func_001BB330(int angle);

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0x50];
    Angles_000C1300 angles;
    char unknown_5c[0x14];
    float value_70;
    char unknown_74[0x30];
    unsigned int flags;
};

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// The class whose table is at 0x1CE450 (constructor func_000D27F0).
struct Object_000D27F0 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000D27F0();

    void func_000D17F0();
    void func_000D5170();

    Object_000C5B50 *owner;
    int state;
    char unknown_00c[8];
    Vector3 position;
    char unknown_020[0x2c];
    int heading;
    char unknown_050[0xe74];
    Rotation_000D2B90 rotation;
    char unknown_ed4[0x114];
    int effect_fe8;
};

// The handlers slot 0 runs by the state at 0x8.
extern void (Object_000D27F0::*data_002169E0[])();

// Slot 0: keeps the owner's heading at 0x4c, runs the handler of the state (table 0x2169E0) and func_000D5170, then
// inside a matrix placed at 0x14, turned by the rotation at 0xec4 and a half turn past the owner's heading, runs
// func_000D17F0 and, while the effect at 0xfe8 is set and the owner lacks the flag 1, shows it (with func_000C1EA0)
// when the owner has 0x8000 and less than 100 at 0x70, else hides it.
void Object_000D27F0::func_000CD1E0()
{
    heading = owner->angles.y;
    (this->*data_002169E0[state])();
    func_000D5170();
    func_001BAA00();
    func_001BAAA0(&position.x);
    func_001BAC70(&rotation);
    func_001BB330(owner->angles.y + 0x8000);
    func_000D17F0();
    if (effect_fe8 != -1 && !(owner->flags & 1)) {
        if ((owner->flags & 0x8000) && owner->value_70 < 100.0f) {
            data_002314B0.func_0003F410(effect_fe8, 1);
            data_00257CE8->func_000C1EA0(effect_fe8);
        } else {
            data_002314B0.func_0003F410(effect_fe8, 0);
        }
    }
    func_001BAA50();
}
