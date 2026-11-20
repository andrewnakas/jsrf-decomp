struct Interface_00132580 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

extern Interface_00132580 *data_0025C300[5];

void func_00132580()
{
    for (int i = 0; i < 5; i++) {
        if (data_0025C300[i]) {
            data_0025C300[i]->slot2();
            data_0025C300[i] = 0;
        }
    }
}
