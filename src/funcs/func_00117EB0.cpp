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

    int func_00117EB0(int id, unsigned int index);
};

extern Interface_002589F4 *data_002589F4;
// Whether entry index of the bank with an id is busy: asks slot 13 of data_002589F4 for its status. 0 for an
// unknown bank or an index past the bank.
int Object_00118CB0::func_00117EB0(int id, unsigned int index)
{
    int bank = -1;
    for (unsigned int i = 0; i < count; i++) {
        if (banks[i]->id == id) {
            bank = i;
            break;
        }
    }
    if (bank < 0) {
        return 0;
    }
    if (banks[bank]->size * banks[bank]->count <= index) {
        return 0;
    }
    unsigned long status;
    data_002589F4->slot13(id, index + 1, &status);
    return (status & 0x80000001) != 0;
}
