struct Interface_00136690 {
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
    virtual long __stdcall slot9(int first, int second, Interface_00136690 **result);
};

struct Object_00134880 {
    void func_001365F0();
};

extern Interface_00251D74 *data_00251D74;
extern Interface_00136690 *data_0025E360[4][5];
extern Interface_00136690 *data_0025EBE8[4][5];
extern Interface_00136690 *data_0025EC98[4];
extern Interface_00136690 *data_0025ECF8;
extern Interface_00136690 *data_0025EB90;

// Has slot 9 of data_00251D74 fill the interfaces func_00136690 releases. Never reads this.
void Object_00134880::func_001365F0()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            data_00251D74->slot9(1, 0, &data_0025E360[i][j]);
            data_00251D74->slot9(1, 0, &data_0025EBE8[i][j]);
        }
        data_00251D74->slot9(1, 0, &data_0025EC98[i]);
    }
    data_00251D74->slot9(1, 0, &data_0025ECF8);
    data_00251D74->slot9(1, 0, &data_0025EB90);
}
