// An entry of the table at 0x264E70 (0x70 bytes).
struct Entry {
    unsigned long unknown_00;
    unsigned long index;
    unsigned long state;
    char unknown_0C[0x64];
};

extern Entry **data_00264E6C;
long __stdcall func_0018DDE0(void *first, unsigned long second);
int func_00153180(unsigned long *state, unsigned long value);

// A class whose table is at 0x1E12F8 (12 slots).
struct Object_001E12F8 {
    virtual long __stdcall func_00153240(unsigned long value);  // slot 10
};

// Hands each listed entry (0x264E6C) to func_0018DDE0 (its index + 1) with 1 if func_00153180 accepts its state
// and the value, else 0; returns how many it accepted.
long __stdcall Object_001E12F8::func_00153240(unsigned long value)
{
    Entry **list = data_00264E6C;
    long count = 0;
    Entry *entry;

    while ((entry = *list) != 0) {
        if (func_00153180(&entry->state, value)) {
            func_0018DDE0((void *)(entry->index + 1), 1);
            count++;
        } else {
            func_0018DDE0((void *)(entry->index + 1), 0);
        }
        list++;
    }
    return count;
}
