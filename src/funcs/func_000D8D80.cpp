/* sym: ?func_000CD1E0@Object_000D8A40@@UAEXXZ = 0x000D8D80 */
struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *matrix);
void __fastcall func_001BB330(int angle);

struct Object_0003E750 {
    void func_0003F410(int effect, int visible);
};

extern Object_0003E750 data_002314B0;

struct Object_00157F10 {
    void func_000C1EA0(int effect);
};

extern Object_00157F10 *data_00257CE8;

// The object a behaviour serves.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[4];
    int angle;
    char unknown_58[0x18];
    float value_70;
    char unknown_74[0x30];
    unsigned int flags;

    int func_000C5B10(int message, void *data);
    void func_000C5B40(int handle, void *data);
    void func_000C5B50(int *handle);
    int func_000C5B70(int handle);
};

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600();
};

// The class whose table is at 0x1CE63C (handlers by state at 0x217378).
struct Object_000D8A40 : Object_000CC600 {
    virtual void func_000CD1E0();

    void func_000D8690();
    void func_000D97D0();

    Object_000C5B50 *owner;
    int state;
    char unknown_00c[8];
    float matrix[7];
    Vector3 position;
    char unknown_03c[0x28];
    int angle;
    char unknown_068[0x78];
    int mode;
    char unknown_0e4[0xd4];
    int effect;
    char unknown_1bc[0x10];
    int handle;
};

extern void (Object_000D8A40::*data_00217378[])();

// Slot 0: runs the handler of the state at 0x8 and func_000D97D0, takes the owner's position and angle (0x30, 0x64),
// sets the matrix at 0x14 turned by the angle around, runs func_000D8690; shows the effect at 0x1b8 unless the owner
// has the flag 1, lit (and handed to data_00257CE8) when the owner has the flag 0x8000 below 100 at 0x70; in mode 1
// (0xe0) keeps the owner's message handle at 0x1cc at its position, else hands it back.
void Object_000D8A40::func_000CD1E0()
{
    (this->*data_00217378[state])();
    func_000D97D0();
    position = owner->position;
    angle = owner->angle;
    func_001BAA00();
    func_001BAAA0(matrix);
    func_001BB330(owner->angle + 0x8000);
    func_000D8690();
    if (effect != -1 && !(owner->flags & 1)) {
        if ((owner->flags & 0x8000) && owner->value_70 < 100.0f) {
            data_002314B0.func_0003F410(effect, 1);
            data_00257CE8->func_000C1EA0(effect);
        } else {
            data_002314B0.func_0003F410(effect, 0);
        }
    }
    func_001BAA50();
    if (mode == 1) {
        if (owner->func_000C5B70(handle)) {
            owner->func_000C5B40(handle, &owner->position);
        } else {
            handle = owner->func_000C5B10(0, &owner->position);
        }
    } else {
        owner->func_000C5B50(&handle);
    }
}
