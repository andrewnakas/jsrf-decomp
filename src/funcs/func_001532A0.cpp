struct Entry {
    unsigned long unknown_00;
    char *data;
};

extern Entry **data_00264E6C;
long __stdcall func_0018DDE0(void *first, unsigned long second);

// A class whose table is at 0x1E12F8 (12 slots).
struct Object_001E12F8 {
    virtual long __stdcall func_001532A0();  // slot 11
};

// Hands each entry of the list at 0x264E6C (ended by 0) to func_0018DDE0 (its data + 1, and 1), empties the list
// and returns how many entries it had.
long __stdcall Object_001E12F8::func_001532A0()
{
    Entry **entry = data_00264E6C;

    while (*entry) {
        func_0018DDE0((*entry)->data + 1, 1);
        entry++;
    }
    data_00264E6C[0] = 0;
    return entry - data_00264E6C;
}
