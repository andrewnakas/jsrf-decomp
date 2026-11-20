// An entry of the table at 0x264E70 (0x70 bytes).
struct Entry {
    unsigned long unknown_00;
    unsigned long index;
    unsigned long state;
    char unknown_0C[0x64];
};

extern Entry **data_00264E6C;
extern Entry *data_00264E70;
extern unsigned int data_00264E74;

// A class whose table is at 0x1E12F8 (12 slots).
struct Object_001E12F8 {
    virtual long __stdcall func_001531E0();  // slot 9
};

// Lists at 0x264E6C (ended by 0) the entries of the table at 0x264E70 that are in use and in state 1, and returns
// how many there are.
long __stdcall Object_001E12F8::func_001531E0()
{
    Entry **list = data_00264E6C;

    for (unsigned int i = 0; i < data_00264E74; i++) {
        Entry *entry = &data_00264E70[i];
        if (entry->unknown_00 && entry->state == 1)
            *list++ = entry;
    }
    *list = 0;
    return list - data_00264E6C;
}
