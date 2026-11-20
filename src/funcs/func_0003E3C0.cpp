/* sym: ?func_00047820@Object_0003D790@@UAEXH@Z = 0x0003E3C0 */
struct Frame_000479D0;
void func_001BA9C0();
void __fastcall func_001BAA50();

struct Object_00066980 {
    float func_00066950();
};

extern Object_00066980 data_00251F28;

struct Surface_000476F0;

// The base of the tables at 0x1CA490, 0x1CAA8C and 0x1CC12C.
struct Object_00047470 {
    virtual ~Object_00047470();
    virtual void slot1();
    virtual void func_00047470(void *first, void *second, Frame_000479D0 *frame);
    virtual void slot3();
    virtual void func_00047540();
    virtual void func_00047690(int first, int second);
    virtual void func_00047820(int argument);

    Surface_000476F0 *surface;
};

// The class whose table is at 0x1CA490 (constructor 0x3D790).
struct Object_0003D790 : Object_00047470 {
    virtual void func_00047820(int argument);

    char unknown_08[0x90];
    float value;
    unsigned int count;

    void func_0003D830(int argument);
};

// Slot 6 of the table at 0x1CA490: with a surface, takes a new value from data_00251F28 (func_00066950) every third
// call, then draws (func_0003D830) between func_001BA9C0 and func_001BAA50.
void Object_0003D790::func_00047820(int argument)
{
    if (surface) {
        if (++count >= 3) {
            count = 0;
            value = data_00251F28.func_00066950();
        }
        func_001BA9C0();
        func_0003D830(argument);
        func_001BAA50();
    }
}
