void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

struct Object_0003E750 {
    void func_0003F410(int key, int value);
};

extern Object_0003E750 data_002314B0;

// The object at data_00257CE8 (func_00157F10 is the engine's); it also answers func_000C1EA0.
struct Object_00157F10 {
    void func_000C1EA0(int key);
};

extern Object_00157F10 *data_00257CE8;

// The object a behaviour serves: angles at 0x50, a level at 0x70 and flags at 0xa4.
struct Desc_000D6350 {
    char unknown_00[0x50];
    int angle_x;
    int angle_y;
    int angle_z;
    char unknown_5c[0x14];
    float level;
    char unknown_74[0x30];
    unsigned int flags;
};

// The base of the behaviours the factories of the table at 0x215D68 build.
struct Object_000CD1E0 {
    virtual void func_000D77D0() = 0;

    Desc_000D6350 *desc;
};

// The behaviour func_000D6350 builds.
struct Object_000D6350 : Object_000CD1E0 {
    virtual void func_000D77D0();
    void func_000D79E0();
    void func_000D6C70();

    char unknown_008[0xc];
    float position[3];
    char unknown_020[0xa8];
    int angle;
    char unknown_0cc[0x1e0];
    int sound;
};

// Slot 8: runs func_000D79E0, takes the served object's y angle at 0xc8, pushes a matrix placed at 0x14 and turned by
// its angles (y + 0x8000, x, z), runs func_000D6C70 and pops it; a sound at 0x2ac (when the object lacks the flag 1) is
// started below level 100 (and passed to func_000C1EA0), else stopped.
void Object_000D6350::func_000D77D0()
{
    func_000D79E0();
    angle = desc->angle_y;
    func_001BAA00();
    func_001BAAA0(position);
    func_001BB330(desc->angle_y + 0x8000);
    func_001BB2E0(desc->angle_x);
    func_001BB380(desc->angle_z);
    func_000D6C70();
    if (sound != -1 && !(desc->flags & 1)) {
        if (desc->level < 100.0f) {
            data_002314B0.func_0003F410(sound, 1);
            data_00257CE8->func_000C1EA0(sound);
        } else {
            data_002314B0.func_0003F410(sound, 0);
        }
    }
    func_001BAA50();
}
