/* sym: ?func_00047820@Object_00069F00@@UAEXH@Z = 0x0006A100 */
void func_001BA9C0();
void func_001BAA50();

struct Matrix_001BA950;
struct Surface_000476F0;
struct Device_00251D6C;

extern Device_00251D6C *data_00251D6C;

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
    char unknown_08[0x18];
    Matrix_001BA950 *matrices;
    unsigned int flags;
};

// The class whose table is at 0x1CC12C (constructor 0x69A30, destructor 0x69F00), built on Object_00047470.
struct Object_00069F00 : Object_00047470 {
    virtual ~Object_00069F00();
    virtual void func_00047820(int argument);

    char unknown_28[0x58];
    int odd;

    void func_00069D70(int unused, Object_00047470 *source);
    void func_00069DC0(int unused, Object_00047470 *source);
    void func_00069E10(int unused, Matrix_001BA950 *matrices);
};

// Slot 6 of the table at 0x1CC12C: with a surface, draws from another model (the `int` argument) between
// func_001BA9C0 and func_001BAA50: with flag 2 from its matrices (func_00069E10), otherwise with func_00069D70 and
// func_00069DC0 in turn (+0x80).
void Object_00069F00::func_00047820(int argument)
{
    if (surface) {
        func_001BA9C0();
        Object_00047470 *model = (Object_00047470 *)argument;
        if (flags & 2) {
            func_00069E10((int)data_00251D6C, model->matrices);
        } else if (odd) {
            func_00069D70((int)data_00251D6C, model);
            odd = 0;
        } else {
            func_00069DC0((int)data_00251D6C, model);
            odd = 1;
        }
        func_001BAA50();
    }
}
