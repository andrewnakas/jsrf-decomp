struct Matrix_001BA950 {
    float m[4][4];
};

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
    virtual void __stdcall slot58();
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
    virtual void __stdcall slot71(int value);
    virtual void __stdcall slot72();
    virtual void __stdcall slot73();
    virtual void __stdcall slot74();
    virtual void __stdcall slot75();
    virtual void __stdcall slot76();
    virtual void __stdcall slot77();
    virtual void __stdcall slot78();
    virtual void __stdcall slot79();
    virtual void __stdcall slot80();
    virtual void __stdcall slot81(int first, int second);
    virtual void __stdcall slot82();
    virtual void __stdcall slot83(int first, int second);
    virtual void __stdcall slot84();
};

extern Device_00251D6C *data_00251D6C;
extern int data_001FA1CC;
extern int data_00251D58;

// What the handlers are given: the matrices at +0x20.
struct Owner_00049A80 {
    char unknown_00[0x20];
    Matrix_001BA950 *matrices;
};

struct Object_00047470 {
    virtual ~Object_00047470();

    char unknown_04[0x20];
    unsigned int flags;

    void func_00047BE0(Matrix_001BA950 *matrices, int kind);
    void func_00047C30(Matrix_001BA950 *matrices);
    void func_00049A80(Owner_00049A80 *owner);
};

// Handler 2 of the table at 0x1F97D0 (run by func_00047820): clears the flag at 0x1FA1CC (device slot 71 with 0),
// runs handler 3 of 0x1FA1B0 on the frames (func_00047BE0), with flag 0x10 also func_00047C30, sets device slot 83
// (0, 0) and (1, 1) and texture stage 1 of the state at 0x251D58 to -1.
void Object_00047470::func_00049A80(Owner_00049A80 *owner)
{
    if (data_001FA1CC) {
        data_001FA1CC = 0;
        data_00251D6C->slot71(0);
    }
    func_00047BE0(owner->matrices, 3);
    if (flags & 0x10)
        func_00047C30(owner->matrices);
    data_00251D6C->slot83(0, 0);
    data_00251D6C->slot83(1, 1);
    if (data_00251D58 != -1) {
        data_00251D58 = -1;
        data_00251D6C->slot81(1, -1);
    }
}
