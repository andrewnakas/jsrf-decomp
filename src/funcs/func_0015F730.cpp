struct Keys {
    int unknown_00;
    int count;
    char *data;
    int stride;
    char *current;
    char *next;
};

void __fastcall func_0015F630(Keys *keys, int index);

// The base of the classes whose tables are at 0x1E17BC (constructor 0x15F1C0) and 0x1E17E0 (constructor 0x15F280): keys at +0x44.
struct Object_001E17BC {
    virtual void __stdcall func_0015F730(int index);  // slot 5

    char unknown_04[0x40];
    Keys *keys;
};

void __stdcall Object_001E17BC::func_0015F730(int index)
{
    func_0015F630(keys, index);
}
