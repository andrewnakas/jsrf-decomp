struct Keys {
    int unknown_00;
    int count;
    unsigned int data;
    unsigned int stride;
};

// A class whose table is at 0x1E1798 (9 slots, constructor 0x15F190): its keys are at +0x44.
struct Object_001E1798 {
    virtual void __stdcall func_0015F450(unsigned int data, unsigned int stride, int count);  // slot 6

    char unknown_04[0x40];
    Keys *keys;
};

// Gives the keys their data, stride and count (kept as count - 1). The linker folded it: it is also slot 6 of the
// tables at 0x1E17BC and 0x1E17E0.
void __stdcall Object_001E1798::func_0015F450(unsigned int data, unsigned int stride, int count)
{
    keys->data = data;
    keys->stride = stride;
    keys->count = count - 1;
}
