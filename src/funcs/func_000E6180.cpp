/* sym: ?func_000CD1E0@Object_000E5FF0@@UAEXXZ = 0x000E6180 */
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

void func_001BA9C0();
void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB330(int angle);

struct Object_0003E750 {
    void func_0003F410(int key, int value);
};

extern Object_0003E750 data_002314B0;

struct Object_0006DB80 {
    void func_0006DFC0(int key, const Vector3 *position);
};

extern Object_0006DB80 data_00251F78;

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 {
    void func_000C1EA0(int key);
};

extern Object_00157F10 *data_00257CE8;

struct Object_00047470 {
    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
    char unknown_5c[0x48];
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

// The class whose table is at 0x1CED80.
struct Object_000E5FF0 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual ~Object_000E5FF0();

    void func_000E5CD0();

    Object_000C5B50 *owner;
    int state;
    char unknown_0c[8];
    Vector3 position;
    char unknown_20[0x10];
    int mode;
    char unknown_34[4];
    int angle;
    char unknown_3c[0x10];
    int key;
    char unknown_50[4];
    Object_00047470 *model;
    char unknown_58[4];
    void *data_5c;
    int value_60;
    char unknown_64[0x114];
    int effect;
};

// The handlers by state (0x8) and by mode (0x30).
extern void (Object_000E5FF0::*data_00218D90[])();
extern void (Object_000E5FF0::*data_00218DD0[])();

// Slot 0: puts the owner at the position at 0x14 and keeps its heading at 0x38, runs the handlers of the state and
// of the mode at 0x30; poses the model at 0x54 (data 0x5c, 0x60) at the position, a half turn past the owner's
// heading, and runs func_000E5CD0 in that frame; poses it again at the owner, shows the effect at 0x178 (with
// func_000C1EA0) when the owner has the flag 0x8000, else hides it, and hands the point of bone 1 to data_00251F78
// with the key at 0x4c.
void Object_000E5FF0::func_000CD1E0()
{
    owner->position = position;
    angle = owner->angles.y;
    (this->*data_00218D90[state])();
    (this->*data_00218DD0[mode])();
    func_001BAA00();
    func_001BAAA0(&position.x);
    func_001BB330(owner->angles.y + 0x8000);
    model->func_00047970(data_5c, value_60);
    func_000E5CD0();
    func_001BAA50();
    func_001BA9C0();
    func_001BAAA0(&owner->position.x);
    func_001BB330(angle + 0x8000);
    model->func_00047970(data_5c, value_60);
    if ((owner->flags & 0x8000) && effect != -1) {
        data_002314B0.func_0003F410(effect, 1);
        data_00257CE8->func_000C1EA0(effect);
    } else {
        data_002314B0.func_0003F410(effect, 0);
    }
    model->func_000480C0(1);
    Vector3 point;
    func_001BAB20(&point, 0);
    data_00251F78.func_0006DFC0(key, &point);
    func_001BAA50();
}
