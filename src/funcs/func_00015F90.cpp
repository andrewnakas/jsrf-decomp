struct Matrix_001BA950 {
    float m[4][4];
};

void func_001BA9C0();
void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);
void __fastcall func_001BAA50();

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

extern float data_001EB9A8[];

struct Model_00015F90;

// The model +0x38 points at: its kind (+0x18), matrix count (+0x1c) and matrices (+0x20); slot 6 ends the drawing.
// Slot 6 is given the model on the stack with the model also in ecx: declared as a member taking the model, which
// gives retail's registers (a __stdcall declaration loads the model into edi).
struct Model_00015F90 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(Model_00015F90 *model);

    char unknown_04[0x14];
    int kind;
    unsigned int count;
    Matrix_001BA950 *matrices;
};

// The class whose table at 0x1C454C holds only its scalar deleting destructor 0x15D50 (constructor 0x15420).
struct Object_00015D50 {
    virtual ~Object_00015D50();

    char unknown_04[0x34];
    Model_00015F90 *owner;

    void func_00015BA0();
    void func_00015F90();
};

// Called by func_00020A90, func_00020C00 and others: sets up the effect of the model's kind (constants at 0x1EB9A8
// at 0, then 6 and 7), runs func_00015BA0, sets 11, 15, 19 and so on for each of the model's matrices (after
// func_001BA8F0 on it, between func_001BA9C0 and func_001BAA50) and ends with the model's slot 6.
void Object_00015D50::func_00015F90()
{
    Effect_00048000 *effect = data_00251D7C->kinds[owner->kind].effect;
    effect->slot5(0, data_001EB9A8, 2);
    effect->slot5(6, 0, 0x30);
    effect->slot5(7, 0, 3);
    func_00015BA0();
    for (unsigned int i = 0; i < owner->count; i++) {
        func_001BA9C0();
        func_001BA8F0(&owner->matrices[i]);
        effect->slot5(11 + i * 4, 0, 2);
        func_001BAA50();
    }
    owner->slot6(owner);
}
