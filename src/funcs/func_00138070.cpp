struct Interface_001380C0 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

struct Interface_00251D74 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5();
    virtual long __stdcall slot6();
    virtual long __stdcall slot7();
    virtual long __stdcall slot8();
    virtual long __stdcall slot9(int first, int second, Interface_001380C0 **result);
};

struct Object_001380C0 {
    char unknown_000[0x2cc];
    Interface_001380C0 *entries[58];
    int count;

    void func_00138070();
};

extern Interface_00251D74 *data_00251D74;

// Unless done already, has slot 9 of data_00251D74 fill the 58 interfaces at +0x2cc, and notes it at +0x3b4.
void Object_001380C0::func_00138070()
{
    if (!count) {
        for (int i = 0; i < 58; i++) {
            data_00251D74->slot9(1, 0, &entries[i]);
        }
        count = 1;
    }
}
