struct Surface_00136720 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7(int value);
};

// The Direct3D device.
struct Device_00251D6C {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8();
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12();
    virtual void __stdcall slot13();
    virtual void __stdcall slot14();
    virtual void __stdcall slot15();
    virtual void __stdcall slot16();
    virtual void __stdcall slot17();
    virtual void __stdcall slot18();
    virtual void __stdcall slot19();
    virtual void __stdcall slot20();
    virtual void __stdcall slot21();
    virtual void __stdcall slot22();
    virtual void __stdcall slot23();
    virtual void __stdcall slot24();
    virtual void __stdcall slot25();
    virtual void __stdcall slot26();
    virtual void __stdcall slot27();
    virtual void __stdcall slot28();
    virtual void __stdcall slot29();
    virtual void __stdcall slot30();
    virtual void __stdcall slot31();
    virtual void __stdcall slot32();
    virtual void __stdcall slot33();
    virtual void __stdcall slot34();
    virtual void __stdcall slot35();
    virtual void __stdcall slot36();
    virtual void __stdcall slot37();
    virtual void __stdcall slot38();
    virtual void __stdcall slot39();
    virtual void __stdcall slot40();
    virtual void __stdcall slot41();
    virtual void __stdcall slot42();
    virtual void __stdcall slot43();
    virtual void __stdcall slot44();
    virtual void __stdcall slot45();
    virtual void __stdcall slot46();
    virtual void __stdcall slot47();
    virtual void __stdcall slot48();
    virtual void __stdcall slot49();
    virtual void __stdcall slot50();
    virtual void __stdcall slot51();
    virtual void __stdcall slot52();
    virtual void __stdcall slot53();
    virtual void __stdcall slot54();
    virtual void __stdcall slot55();
    virtual void __stdcall slot56();
    virtual void __stdcall slot57();
    virtual void __stdcall slot58(int first, int second, int texture, int format, Surface_00136720 **surface);
    virtual void __stdcall slot59();
    virtual void __stdcall slot60();
    virtual void __stdcall slot61();
    virtual void __stdcall slot62();
    virtual void __stdcall slot63();
    virtual void __stdcall slot64();
    virtual void __stdcall slot65();
    virtual void __stdcall slot66();
    virtual void __stdcall slot67();
    virtual void __stdcall slot68();
    virtual void __stdcall slot69();
    virtual void __stdcall slot70();
    virtual void __stdcall slot71();
    virtual void __stdcall slot72();
    virtual void __stdcall slot73();
    virtual void __stdcall slot74();
    virtual void __stdcall slot75();
    virtual void __stdcall slot76();
    virtual void __stdcall slot77();
    virtual void __stdcall slot78();
    virtual void __stdcall slot79();
    virtual void __stdcall slot80();
    virtual void __stdcall slot81();
    virtual void __stdcall slot82();
    virtual void __stdcall slot83();
    virtual void __stdcall slot84();
    virtual void __stdcall slot85(int state, int value);
};

struct Object_0006E130 {
    int func_0006E130(int id);
    int func_0006E360(int id);
};

extern Device_00251D6C *data_00251D6C;
extern Object_0006E130 data_00252790;
extern int data_0022C94C[5];
extern int data_0025EB98[][5];
extern void *data_0025ECA8[][5];

struct Object_00134880 {
    void func_00136720();
};

// Four times over the five ids at data_0022C94C: loads each (func_0006E360 of data_00252790) into the next of the 20
// words at data_0025EB98 between device slot 85 calls (0, 0) and (0, 1), creates its surface with device slot 58
// into data_0025ECA8 and calls the surface's slot 7 with 0.
// Never reads this.
void Object_00134880::func_00136720()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            data_00251D6C->slot85(0, 0);
            data_0025EB98[i][j] = data_00252790.func_0006E360(data_0022C94C[j]);
            data_00251D6C->slot85(0, 1);
            data_00251D6C->slot58(0, 0, data_00252790.func_0006E130(data_0025EB98[i][j]), 2,
                                  (Surface_00136720 **)&data_0025ECA8[i][j]);
            ((Surface_00136720 *)data_0025ECA8[i][j])->slot7(0);
        }
    }
}
