struct Keys {
    int unknown_00;
    int count;
    char *data;
    int stride;
    char *current;
    char *next;
};

void __fastcall func_0015F3F0(Keys *keys, void *out, float time);

// A class whose table is at 0x1E1798 (9 slots, constructor 0x15F190): its keys are at +0x44.
struct Object_001E1798 {
    virtual void __stdcall func_0015F4C0(void *out, float time);  // slot 7

    char unknown_04[0x40];
    Keys *keys;
};

void __stdcall Object_001E1798::func_0015F4C0(void *out, float time)
{
    func_0015F3F0(keys, out, time);
}
