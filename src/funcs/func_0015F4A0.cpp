struct Keys {
    int unknown_00;
    int count;
    char *data;
    int stride;
    char *current;
    char *next;
};

void __fastcall func_0015F3D0(Keys *keys, int index);

// A class whose table is at 0x1E1798 (9 slots, constructor 0x15F190): its keys are at +0x44.
struct Object_001E1798 {
    virtual void __stdcall func_0015F4A0(int index);  // slot 5

    char unknown_04[0x40];
    Keys *keys;
};

void __stdcall Object_001E1798::func_0015F4A0(int index)
{
    func_0015F3D0(keys, index);
}
