extern "C" void *memset(void *destination, int value, unsigned int size);
void *__stdcall func_00145A2F(void *address, unsigned long size, unsigned long type, unsigned long protect);

// An entry of the 0x70-byte table at data_00264E70.
struct Entry {
    unsigned long unknown_00;
    unsigned long index;
    unsigned long state;
    char unknown_0C[0x64];
};

extern Entry *data_00264E70;
extern unsigned int data_00264E74;
extern Entry **data_00264E6C;

// The Direct3D device wrapper (table 0x1E0F00); data_002650D8 points at the one in use.
struct Object_001E0F00 {
    long func_00154EE0(void *resource);
};

extern Object_001E0F00 *data_002650D8;

// A class whose table is at 0x1E12F8 (12 slots; created by 0x1536E0).
struct Object_001E12F8 {
    virtual long __stdcall func_00153300(const void *iid, void **object);  // slot 0

    long __stdcall func_00153340(unsigned int count);
};

// Sets up the table of count entries at data_00264E70 with the list of count pointers after it (data_00264E6C),
// all cleared (func_00145A2F), and puts the object on the device's list. CO_E_ALREADYINITIALIZED when the list
// exists, E_INVALIDARG for no entries, E_OUTOFMEMORY when the allocation fails.
long __stdcall Object_001E12F8::func_00153340(unsigned int count)
{
    if (!data_00264E6C) {
        if (count) {
            unsigned int size = count * (sizeof(Entry) + sizeof(Entry *));
            Entry *table = (Entry *)func_00145A2F(0, size, 0x3000, 4);
            if (table) {
                memset(table, 0, size);
                data_00264E74 = count;
                data_00264E70 = table;
                data_00264E6C = (Entry **)(table + count);
                data_002650D8->func_00154EE0(this);
                return 0;
            }
            return 0x8007000e;
        }
        return 0x80070057;
    }
    return 0x800401f1;
}
