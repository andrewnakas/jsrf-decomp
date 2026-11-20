struct Cell_001209E0 {
    int id;
    char unknown_04[0x2c];
};

struct Pose_001209E0 {
    char unknown_00[8];
    int angle;
    int kind;
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
    virtual void __stdcall slot30(const void *settings);
    virtual void __stdcall slot31(unsigned int value, float first, float second);
};

struct Object_00120420 {
    char unknown_0000[0x1088];
    Pose_001209E0 poses[4];
    char unknown_10c8[0x21b0];
    Cell_001209E0 cells[4][15];

    void func_001209E0(int index);
    void func_00123460(Cell_001209E0 *cell, Pose_001209E0 *pose);
};

extern Device_00251D6C *data_00251D6C;
void func_001BA9C0();
void func_001BAA00();
void func_001BAA50();
void __fastcall func_001BB380(int angle);

// Member of object 0x1de2's class: draws the cells of a player (func_00123460 for each of its 15 cells with an
// id, render state 0x18e3 set to 1 and 20000 after each) turned by the player's angle in degrees.
void Object_00120420::func_001209E0(int index)
{
    func_001BAA00();
    func_001BB380((int)(poses[index].angle * 182.04445f));
    for (int i = 0; i < 15; i++) {
        if (cells[index][i].id >= 0) {
            func_001BA9C0();
            func_00123460(&cells[index][i], &poses[index]);
            data_00251D6C->slot31(0x18e3, 1.0f, 20000.0f);
            func_001BAA50();
        }
    }
    func_001BAA50();
}
