struct Matrix_001BA950 {
    float m[4][4];
};

void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);

// A frame of the list at +0x8 (0x6c bytes): a word tested first, a position at +0x14.
struct Frame_000479D0 {
    int unknown_00;
    char unknown_04[0x10];
    float position[3];
    char unknown_20[0x4c];
};

struct Object_00047470;

extern void (*data_001FA1B0[])(Object_00047470 *object, Frame_000479D0 *frame);

struct Object_00047470 {
    virtual ~Object_00047470();

    void *surface;
    Frame_000479D0 *frames;
    char unknown_0c[0x10];
    unsigned int count;

    void func_00047BE0(Matrix_001BA950 *matrices, int kind);
};

// For each frame whose first word is set, loads its matrix from `matrices` (func_001BA8F0) and runs handler `kind`
// of the table at 0x1FA1B0 on it.
void Object_00047470::func_00047BE0(Matrix_001BA950 *matrices, int kind)
{
    Frame_000479D0 *frame = frames;
    for (unsigned int i = 0; i < count; i++, matrices++, frame++) {
        if (frame->unknown_00) {
            func_001BA8F0(matrices);
            data_001FA1B0[kind](this, frame);
        }
    }
}
