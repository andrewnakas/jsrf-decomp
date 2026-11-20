struct Interface_002589F4 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5();
    virtual long __stdcall slot6();
    virtual long __stdcall slot7();
};

struct Object_00039BE0 {
    void func_0003A4C0(int *first, int *second);
};

struct Object_00118CB0 {
    char unknown_0000[0x69c];
    int updates;
    char unknown_06a0[0x3814];
    int value_3eb4;
    int value_3eb8;
    char unknown_3ebc[0x5c];
    unsigned int count;

    void func_00118410();
    void func_001185B0();
};

extern Interface_002589F4 *data_002589F4;
extern Object_00039BE0 data_001EFFB0;

// Clears +0x3eb4 and calls slot 7 of data_002589F4; when entries are loaded, takes the second value
// func_0003A4C0 of data_001EFFB0 gives, runs func_00118410 and counts the update.
void Object_00118CB0::func_001185B0()
{
    value_3eb4 = 0;
    data_002589F4->slot7();
    if (count) {
        int first;
        int second;
        data_001EFFB0.func_0003A4C0(&first, &second);
        value_3eb8 = second;
        func_00118410();
        updates++;
    }
}
