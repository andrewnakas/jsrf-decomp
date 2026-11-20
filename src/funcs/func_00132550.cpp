struct Interface_00132580 {
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
    virtual long __stdcall slot9(int first, int second, Interface_00132580 **result);
};

struct Object_00120420 {
    void func_00132550();
};

extern Interface_00251D74 *data_00251D74;
extern Interface_00132580 *data_0025C300[5];

// Has slot 9 of data_00251D74 fill each of the five entries of data_0025C300. Never reads this.
void Object_00120420::func_00132550()
{
    for (int i = 0; i < 5; i++) {
        data_00251D74->slot9(1, 0, &data_0025C300[i]);
    }
}
