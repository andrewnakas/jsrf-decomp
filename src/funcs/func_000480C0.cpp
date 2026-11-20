struct Matrix_001BA950 {
    float m[4][4];
};

void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);
void __fastcall func_001BAAA0(float *vector);

// A frame of the list at +0x8 (0x6c bytes): a word tested first, a position at +0x14.
struct Frame_000479D0 {
    int unknown_00;
    char unknown_04[0x10];
    float position[3];
    char unknown_20[0x4c];
};

struct Object_00047470 {
    virtual ~Object_00047470();

    void *surface;
    Frame_000479D0 *frames;
    char unknown_0c[0x10];
    unsigned int count;
    Matrix_001BA950 *matrices;
    unsigned int flags;

    void func_000480C0(unsigned int index);
};

// Unless flag 4 is set, loads matrix number `index` (func_001BA8F0) and moves it to the position of frame `index`
// (func_001BAAA0).
void Object_00047470::func_000480C0(unsigned int index)
{
    if (!(flags & 4) && index < count) {
        func_001BA8F0(&matrices[index]);
        func_001BAAA0(frames[index].position);
    }
}
