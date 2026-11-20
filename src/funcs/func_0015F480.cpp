struct Keys {
    int unknown_00;
    int count;
    unsigned int data;
    unsigned int stride;
    unsigned int current;
    unsigned int next;
};

// A class whose table is at 0x1E1798 (9 slots, constructor 0x15F190): its keys are at +0x44.
struct Object_001E1798 {
    virtual unsigned int __stdcall func_0015F480();  // slot 4

    char unknown_04[0x40];
    Keys *keys;
};

// The index of the key at +0x10 of the keys.
unsigned int __stdcall Object_001E1798::func_0015F480()
{
    return (keys->current - keys->data) / keys->stride;
}
