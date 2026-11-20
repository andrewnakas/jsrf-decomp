struct Interface_00136690 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

struct Object_00134880 {
    void func_00136690();
};

extern Interface_00136690 *data_0025E360[4][5];
extern Interface_00136690 *data_0025EBE8[4][5];
extern Interface_00136690 *data_0025EC98[4];
extern Interface_00136690 *data_0025ECF8;
extern Interface_00136690 *data_0025EB90;

// Releases (slot 2) and clears the interfaces of the two 4 x 5 tables, the table of four and two more. Never reads
// this.
void Object_00134880::func_00136690()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (data_0025E360[i][j]) {
                data_0025E360[i][j]->slot2();
                data_0025E360[i][j] = 0;
            }
            if (data_0025EBE8[i][j]) {
                data_0025EBE8[i][j]->slot2();
                data_0025EBE8[i][j] = 0;
            }
        }
        if (data_0025EC98[i]) {
            data_0025EC98[i]->slot2();
            data_0025EC98[i] = 0;
        }
    }
    if (data_0025ECF8) {
        data_0025ECF8->slot2();
        data_0025ECF8 = 0;
    }
    if (data_0025EB90) {
        data_0025EB90->slot2();
        data_0025EB90 = 0;
    }
}
