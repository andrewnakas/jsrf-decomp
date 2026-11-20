struct Table_300 {
    unsigned long words[0xc0];
};

// A class whose table is at 0x1E1270 (8 slots).
struct Object_001E1270 {
    virtual void __stdcall func_00151DB0();  // slot 4

    Table_300 current;
    Table_300 saved;
};

// Copies the 0x300 bytes at +0x304 back to +4.
void __stdcall Object_001E1270::func_00151DB0()
{
    current = saved;
}
