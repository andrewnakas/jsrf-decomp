struct Matrix_001BA950 {
    float m[4][4];
};

void func_001BA9C0();
void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);
void __fastcall func_001BAA50();

// A vertex shader effect: slot 3 begins, slot 4 ends, slot 5 sets constants.
struct Effect_00047850 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5(int index, const float *values, int count);
};

struct Context_00251D7C {
    char unknown_000[0x368];
    Effect_00047850 *effects[1];
};

extern Context_00251D7C *data_00251D7C;

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
    virtual void __stdcall slot58();
    virtual void __stdcall slot59();
    virtual void __stdcall slot60();
    virtual void __stdcall slot61();
    virtual void __stdcall slot62();
    virtual void __stdcall slot63();
    virtual void __stdcall slot64();
    virtual void __stdcall slot65();
    virtual void __stdcall slot66(int value);
};

extern Device_00251D6C *data_00251D6C;

extern float data_001F97E8[4];
extern int data_00251D40;

// The model base class (table 0x1CAA8C): its frames' textures (+0xc), effect kind (+0x18), matrices (+0x1c, +0x20),
// a constant vector at +0x28, two values at +0x38 and the drawing member at +0x64.
struct Object_00047470 {
    virtual ~Object_00047470();

    char unknown_04[8];
    int *textures;
    char unknown_10[8];
    int kind;
    unsigned int count;
    Matrix_001BA950 *matrices;
    char unknown_24[4];
    float vector[4];
    float first;
    float second;
    char unknown_40[0x24];
    void (Object_00047470::*draw)(int texture);

    void func_00047850();
};

// Draws through the effect of its kind (+0x18 into the table at +0x368 of 0x251D7C) when it begins: constants 0
// (0x1F97E8), 7, one matrix per bone from 11 on, 2 (the values at +0x3c and +0x38) and 1 (the vector at +0x28), then
// the member at +0x64 with its first texture with slot 66 of the device at 2, counting the draw in 0x251D40.
void Object_00047470::func_00047850()
{
    Effect_00047850 *effect = data_00251D7C->effects[kind];
    if (effect->slot3() >= 0) {
        effect->slot5(0, data_001F97E8, 1);
        effect->slot5(7, 0, 3);
        func_001BA9C0();
        for (unsigned int i = 0; i < count; i++) {
            func_001BA8F0(&matrices[i]);
            effect->slot5(11 + i * 4, 0, 2);
        }
        func_001BAA50();
        float values[4] = {second, first, 0.0f, 0.0f};
        effect->slot5(2, values, 1);
        effect->slot5(1, vector, 1);
        data_00251D6C->slot66(2);
        (this->*draw)(*textures);
        data_00251D40++;
        data_00251D6C->slot66(1);
        effect->slot4();
    }
}
