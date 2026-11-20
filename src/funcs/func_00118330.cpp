struct Interface_002589F4 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5();
    virtual long __stdcall slot6();
    virtual long __stdcall slot7();
    virtual long __stdcall slot8();
    virtual long __stdcall slot9();
    virtual long __stdcall slot10();
    virtual long __stdcall slot11();
    virtual long __stdcall slot12();
    virtual long __stdcall slot13(int id, unsigned int entry, unsigned long *status);
    virtual long __stdcall slot14();
    virtual long __stdcall slot15(int id, unsigned int entry, int flags);
};

struct Bank_00117EB0 {
    int id;
    unsigned int count;
    unsigned int size;
};

struct Object_00118CB0 {
    char unknown_0000[0x3f18];
    unsigned int count;
    Bank_00117EB0 *banks[256];

    int func_00118330(int id, int index);
};

extern Interface_002589F4 *data_002589F4;

// Finds the first free entry of the bank with an id from the given index on (stepping by the bank's count, slot 13
// of data_002589F4 reporting each), and returns that entry with the id in the high word; -1 for an unknown bank or
// an index past the bank.
int Object_00118CB0::func_00118330(int id, int index)
{
    int bank = -1;
    for (unsigned int i = 0; i < count; i++) {
        if (banks[i]->id == id) {
            bank = i;
            break;
        }
    }
    if (bank < 0) {
        return -1;
    }
    Bank_00117EB0 *entry = banks[bank];
    if (entry->size * entry->count <= index) {
        return -1;
    }
    int slot = 0;
    for (int j = 0; j < (int)banks[bank]->size; j++) {
        unsigned long status;
        data_002589F4->slot13(id, banks[bank]->count * j + index + 1, &status);
        if (!(status & 0x80000001)) {
            slot = j;
            break;
        }
    }
    return (entry->count * slot + index) | (id << 16);
}
