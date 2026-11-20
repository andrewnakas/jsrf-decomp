/* sym: ?func_00047820@Object_000416C0@@UAEXH@Z = 0x000427C0 */
void func_001BA9C0();
void __fastcall func_001BAA50();

struct Matrix_001BA950;
struct Frame_000479D0;
struct Surface_000476F0;

void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);
int func_0005BCE0(unsigned int count, Frame_000479D0 *frames);

// The base of the tables at 0x1CA490, 0x1CAA8C and 0x1CC12C.
struct Object_00047470 {
    virtual ~Object_00047470();
    virtual void slot1();
    virtual void func_00047470();
    virtual void slot3();
    virtual void func_00047540();
    virtual void func_00047690(int first, int second);
    virtual void func_00047820(int argument);

    Surface_000476F0 *surface;
    char unknown_08[0x4];
    Frame_000479D0 *frames;
    int mode;
    char unknown_14[0xc];
    Matrix_001BA950 *matrices;
    unsigned int count;

    void func_00047970(void *data, int argument);
};

// The class whose table is at 0x1CA5CC (constructor 0x416C0).
struct Object_000416C0 : Object_00047470 {
    virtual void func_00047690(int first, int second);
    virtual void func_00047820(int argument);

    void func_00041700(Matrix_001BA950 *matrices, Object_00047470 *model);
    void func_00041BF0(Matrix_001BA950 *matrices, Object_00047470 *model);
};

// Slot 6 of the table at 0x1CA5CC: as slot 5 for another model's frames: with a surface, loads that model's matrix
// and, when func_0005BCE0 accepts its own frames, draws the model with func_00041BF0 (mode 5) or func_00041700.
void Object_000416C0::func_00047820(int argument)
{
    if (surface) {
        func_001BA9C0();
        Object_00047470 *model = (Object_00047470 *)argument;
        func_001BA8F0(model->matrices);
        if (func_0005BCE0(count, frames)) {
            if (mode == 5) {
                func_00041BF0(model->matrices, model);
            } else {
                func_00041700(model->matrices, model);
            }
        }
        func_001BAA50();
    }
}
