struct Interface_001205D0 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

struct Object_00120420 {
    void func_001205D0();
};

extern Interface_001205D0 *data_00258BC0[5];

// Calls slot 2 of each of the five entries of data_00258BC0 that is set, and clears it. Never reads this.
void Object_00120420::func_001205D0()
{
    for (int i = 0; i < 5; i++) {
        if (data_00258BC0[i]) {
            data_00258BC0[i]->slot2();
            data_00258BC0[i] = 0;
        }
    }
}
