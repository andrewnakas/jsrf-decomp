void func_001BA9C0();
void func_001BAA50();

struct Surface_000476F0;

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
    char unknown_08[0x8];
    int mode;
};

extern void (Object_00047470::*data_001F97B4[])(int, int);

// Slot 5 of the tables at 0x1CA490, 0x1CAA8C and 0x1CC12C: with an interface at +0x4, runs the handler of the mode
// at +0x10 from the table at 0x1F97B4 between func_001BA9C0 and func_001BAA50.
void Object_00047470::func_00047690(int first, int second)
{
    if (surface) {
        func_001BA9C0();
        (this->*data_001F97B4[mode])(first, second);
        func_001BAA50();
    }
}
