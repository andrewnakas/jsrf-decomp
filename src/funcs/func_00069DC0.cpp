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

struct Surface_00069DC0 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7(int value);
};

struct Object_00047470 {
    virtual ~Object_00047470();

    Surface_00069DC0 *surface;
    Frame_000479D0 *frames;
    char unknown_0c[0x10];
    unsigned int count;
    Matrix_001BA950 *matrices;
};

// The class whose table is at 0x1CC12C (constructor 0x69A30, destructor 0x69F00), built on Object_00047470.
struct Object_00069F00 : Object_00047470 {
    virtual ~Object_00069F00();

    void func_00069DC0(int unused, Object_00047470 *source);
};

// For each frame whose first word is set, loads the matching matrix of `source` (func_001BA8F0) and hands the word to
// slot 7 of the surface at +0x4 (called from slot 6 of the table, 0x6A100).
void Object_00069F00::func_00069DC0(int, Object_00047470 *source)
{
    Frame_000479D0 *frame = frames;
    for (unsigned int i = 0; i < count; frame++, i++) {
        if (frame->unknown_00) {
            func_001BA8F0(&source->matrices[i]);
            surface->slot7(frame->unknown_00);
        }
    }
}
