struct Matrix_001BA950 {
    float m[4][4];
};

void __fastcall func_001BA950(Matrix_001BA950 *matrix);

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
};

extern Device_00251D6C *data_00251D6C;
extern int data_001FA1CC;

// What +0x520 of 0x251D7C points at: slot 3 begins (negative on failure), slot 5 sets, slot 4 ends.
struct Effect_000497E0 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual int __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5(int first, int second, int third);
};

struct Context_00251D7C {
    virtual ~Context_00251D7C();

    char unknown_004[0x51c];
    Effect_000497E0 *effect;
};

extern Context_00251D7C *data_00251D7C;

// What the handlers are given: the matrices at +0x20.
struct Owner_00049A80 {
    char unknown_00[0x20];
    Matrix_001BA950 *matrices;
};

struct Object_00047470 {
    virtual ~Object_00047470();

    char unknown_04[0x18];
    unsigned int count;
    Matrix_001BA950 *matrices;
    unsigned int flags;

    void func_00047BE0(Matrix_001BA950 *matrices, int kind);
    void func_00047C30(Matrix_001BA950 *matrices);
    void func_000497E0(Owner_00049A80 *owner);
};

// Handler 0 of the table at 0x1F97D0 (run by func_00047820): sets the flag at 0x1FA1CC (device slot 71 with 1) and
// runs handler 1 of 0x1FA1B0 on the frames (func_00047BE0); with flag 0x40 instead, inside the effect at +0x520 of
// 0x251D7C (slot 5 with 5, 0, 3), handler 5, then the current matrix (func_001BA950) into this object's first matrix
// and that over the others. With flag 0x10 also func_00047C30.
void Object_00047470::func_000497E0(Owner_00049A80 *owner)
{
    if (data_001FA1CC != 1) {
        data_001FA1CC = 1;
        data_00251D6C->slot71(1);
    }
    if (!(flags & 0x40)) {
        func_00047BE0(owner->matrices, 1);
    } else {
        Effect_000497E0 *effect = data_00251D7C->effect;
        if (effect->slot3() >= 0) {
            effect->slot5(5, 0, 3);
            func_00047BE0(owner->matrices, 5);
            func_001BA950(matrices);
            for (unsigned int i = 1; i < count; i++)
                matrices[i] = matrices[0];
            effect->slot4();
        }
    }
    if (flags & 0x10)
        func_00047C30(owner->matrices);
}
