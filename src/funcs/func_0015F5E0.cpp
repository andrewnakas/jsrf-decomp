struct Keys {
    int unknown_00;
    int count;
    unsigned int data;
    unsigned int stride;
    unsigned int current;
    unsigned int next;
};

// The base of the classes whose tables are at 0x1E17BC (constructor 0x15F1C0) and 0x1E17E0 (constructor 0x15F280): keys at +0x44.
struct Object_001E17BC {
    virtual unsigned int __stdcall func_0015F5E0();  // slot 4

    char unknown_04[0x40];
    Keys *keys;
};

// The index of the key at +0x14 of the keys.
unsigned int __stdcall Object_001E17BC::func_0015F5E0()
{
    return (keys->next - keys->data) / keys->stride;
}
