extern int data_00265154;

// A class whose table is at 0x1E1798 (9 slots, constructor 0x15F190).
struct Object_001E1798 {
    virtual long __stdcall func_0015F580(const void *iid, void **object);  // slot 0
    void __stdcall func_0015F3C0();
};

// Counts one live object less at 0x265154 (func_0015F390 counts them).
void __stdcall Object_001E1798::func_0015F3C0()
{
    data_00265154--;
}
