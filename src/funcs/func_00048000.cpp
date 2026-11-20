struct Matrix_001BA950 {
    float m[4][4];
};

void func_001BA9C0();
void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);
void func_001BAA50();

// The effect of a kind (+0x2e8 of 0x251D7C, 0x24 bytes per kind): slot 5 sets its constants.
struct Effect_00048000 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5(int index, const float *values, int count);
};

struct Kind_00048000 {
    Effect_00048000 *effect;
    char unknown_04[0x20];
};

struct Context_00251D7C {
    virtual ~Context_00251D7C();

    char unknown_004[0x2e4];
    Kind_00048000 kinds[1];
};

extern Context_00251D7C *data_00251D7C;

struct Object_00047470 {
    virtual ~Object_00047470();

    char unknown_04[0x14];
    int kind;
    unsigned int count;
    Matrix_001BA950 *matrices;

    void func_00048000();
};

// Sets up the effect of the kind at +0x18: constants (1024, 1, 0, 0.5) at 0, then 6 and 7, and for each of the
// matrices at +0x20 (after func_001BA8F0 on it) 11, 15, 19 and so on, between func_001BA9C0 and func_001BAA50.
void Object_00047470::func_00048000()
{
    float constants[4] = {1024.0f, 1.0f, 0.0f, 0.5f};
    Effect_00048000 *effect = data_00251D7C->kinds[kind].effect;
    effect->slot5(0, constants, 1);
    effect->slot5(6, 0, 0x30);
    effect->slot5(7, 0, 3);
    func_001BA9C0();
    for (unsigned int i = 0; i < count; i++) {
        func_001BA8F0(&matrices[i]);
        effect->slot5(11 + i * 4, 0, 2);
    }
    func_001BAA50();
}
