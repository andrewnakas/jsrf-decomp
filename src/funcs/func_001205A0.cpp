struct Interface_001205D0 {
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
    virtual long __stdcall slot9(int first, int second, Interface_001205D0 **result);
};

struct Object_00120420 {
    void func_001205A0();
};

extern Interface_00251D74 *data_00251D74;
extern Interface_001205D0 *data_00258BC0[5];

// Has slot 9 of data_00251D74 fill each of the five entries of data_00258BC0, clearing an entry when it fails.
// Never reads this.
void Object_00120420::func_001205A0()
{
    for (int i = 0; i < 5; i++) {
        if (data_00251D74->slot9(1, 0, &data_00258BC0[i]) < 0) {
            data_00258BC0[i] = 0;
        }
    }
}
