/* sym: ?func_00011C80@Object_000E5FF0@@UAEXH@Z = 0x000E5450 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 {
    void func_000C1690(int key);
    void func_000C1770(int key);
};

extern Object_00157F10 *data_00257CE8;

// The object a behaviour serves (the owner type of the Object_000CC600 family).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0x54];
    unsigned int flags;
};

void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB330(int angle);

// The drawn model at 0x54; slot 5 takes two values.
struct Model_000E5450 {
    virtual void func_0();
    virtual void func_1();
    virtual void func_2();
    virtual void func_3();
    virtual void func_4();
    virtual void func_5(int first, int second);

    char unknown_04[0x58];
    int value_5c;
    char unknown_60[0x14];
    int value_74;
    char unknown_78[4];
    int value_7c;
};

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// The class whose table is at 0x1CED80 (handlers at 0x218DD0, run by the state at 0x30).
struct Object_000E5FF0 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual ~Object_000E5FF0();

    Object_000C5B50 *owner;
    char unknown_08[0x24];
    int value_2c;
    char unknown_30[8];
    int angle;
    char unknown_3c[0x10];
    int key;
    float distance;
    Model_000E5450 *model;
    char unknown_58[4];
    int value_5c;
    int value_60;
    char unknown_64[0x114];
    int effect;
    int value_17c;
    int value_180;
};

// Slot 2: with argument 0, places the matrix at the owner's position turned by the angle at 0x38 plus a half turn,
// copies 0x17c, 0x180 and 0x2c into the model at 0x54 (+0x74, +0x7c, +0x5c), runs its slot 5 with 0x5c and 0x60,
// hands the key at 0x4c to func_000C1690 of data_00257CE8, and, when the owner has 0x8000 but not 0x2000 set, the
// effect at 0x178 to its func_000C1770.
void Object_000E5FF0::func_00011C80(int argument)
{
    if (argument == 0) {
        func_001BAAA0(&owner->position.x);
        func_001BB330(angle + 0x8000);
        model->value_74 = value_17c;
        model->value_7c = value_180;
        model->value_5c = value_2c;
        model->func_5(value_5c, value_60);
        data_00257CE8->func_000C1690(key);
        if (!(owner->flags & 0x2000) && (owner->flags & 0x8000)) {
            data_00257CE8->func_000C1770(effect);
        }
    }
}
