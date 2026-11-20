struct Guid;

// What slot 4 fills in: three words, the addresses of three tables of the object and a fourth word.
struct Info {
    unsigned long first;
    unsigned long second;
    unsigned long third;
    char *table1;
    char *table2;
    char *table3;
    unsigned long fourth;
};

// The class whose table is at 0x1E2008.
struct Object_001E2008 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual long __stdcall func_00165670(Info *info);

    char unknown_04[0xc];
    unsigned long first;
    char table1[0x100];
    char table2[0x400];
    char table3[0x400];
    unsigned long second;
    unsigned long third;
    char unknown_91c[0x2c];
    unsigned long fourth;
};

// Slot 4: fills in the words at +0x10, +0x914, +0x918 and +0x948 and the addresses of the tables at +0x14, +0x114 and
// +0x514. E_INVALIDARG for a null pointer.
long __stdcall Object_001E2008::func_00165670(Info *info)
{
    if (info) {
        info->first = first;
        info->second = second;
        info->third = third;
        info->table1 = table1;
        info->table2 = table2;
        info->table3 = table3;
        info->fourth = fourth;
        return 0;
    }
    return 0x80070057;
}
