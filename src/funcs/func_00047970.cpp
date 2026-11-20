struct Matrix_001BA950 {
    float m[4][4];
};

void __fastcall func_001BA950(Matrix_001BA950 *matrix);
void func_0005F0F0(void *object, void *frames, void *data, float frame, int mode);

// The base of the tables at 0x1CA490, 0x1CAA8C and 0x1CC12C: its frames (+0x8) and one matrix per frame (+0x20).
struct Object_00047470 {
    virtual ~Object_00047470();

    void *surface;
    void *frames;
    char unknown_0c[0x4];
    int mode;
    char unknown_14[0x8];
    unsigned int count;
    Matrix_001BA950 *matrices;

    void func_00047970(void *data, int argument);
};

// With data: poses the frames from it (func_0005F0F0, mode 2). Without: fills the first matrix (func_001BA950) and
// copies it to every other frame's matrix.
void Object_00047470::func_00047970(void *data, int argument)
{
    if (data) {
        func_0005F0F0(this, frames, data, *(float *)&argument, 2);
        return;
    }
    func_001BA950(matrices);
    for (unsigned int i = 1; i < count; i++) {
        matrices[i] = matrices[0];
    }
}
