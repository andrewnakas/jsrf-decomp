/* sym: ?func_00047690@Object_00040540@@UAEXHH@Z = 0x00041560 */
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

// The Direct3D device.
struct Device_00251D6C {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8();
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12();
    virtual void __stdcall slot13();
    virtual void __stdcall slot14();
    virtual void __stdcall slot15();
    virtual void __stdcall slot16();
    virtual void __stdcall slot17();
    virtual void __stdcall slot18();
    virtual void __stdcall slot19();
    virtual void __stdcall slot20();
    virtual void __stdcall slot21();
    virtual void __stdcall slot22();
    virtual void __stdcall slot23();
    virtual void __stdcall slot24();
    virtual void __stdcall slot25();
    virtual void __stdcall slot26();
    virtual void __stdcall slot27();
    virtual void __stdcall slot28();
    virtual void __stdcall slot29();
    virtual void __stdcall slot30();
    virtual void __stdcall slot31();
    virtual void __stdcall slot32();
    virtual void __stdcall slot33();
    virtual void __stdcall slot34();
    virtual void __stdcall slot35();
    virtual void __stdcall slot36();
    virtual void __stdcall slot37();
    virtual void __stdcall slot38();
    virtual void __stdcall slot39();
    virtual void __stdcall slot40();
    virtual void __stdcall slot41();
    virtual void __stdcall slot42();
    virtual void __stdcall slot43();
    virtual void __stdcall slot44();
    virtual void __stdcall slot45();
    virtual void __stdcall slot46();
    virtual void __stdcall slot47();
    virtual void __stdcall slot48();
    virtual void __stdcall slot49();
    virtual void __stdcall slot50();
    virtual void __stdcall slot51();
    virtual void __stdcall slot52();
    virtual void __stdcall slot53();
    virtual void __stdcall slot54();
    virtual void __stdcall slot55();
    virtual void __stdcall slot56();
    virtual void __stdcall slot57();
    virtual void __stdcall slot58();
    virtual void __stdcall slot59();
    virtual void __stdcall slot60();
    virtual void __stdcall slot61();
    virtual void __stdcall slot62();
    virtual void __stdcall slot63();
    virtual void __stdcall slot64();
    virtual void __stdcall slot65();
    virtual void __stdcall slot66();
    virtual void __stdcall slot67();
    virtual void __stdcall slot68(int value);
};

extern Device_00251D6C *data_00251D6C;

// The value device state 68 was last set to.
extern int data_00251D80;

// The class whose table is at 0x1CA5A8 (constructor 0x40540).
struct Object_00040540 : Object_00047470 {
    virtual void func_00047690(int first, int second);
    virtual void func_00047820(int argument);

    void func_000406D0(Matrix_001BA950 *matrices);
    void func_00040B10(Matrix_001BA950 *matrices);
};

// Slot 5 of the table at 0x1CA5A8: with a surface, poses its frames (func_00047970), loads its matrix (func_001BA8F0)
// and, when func_0005BCE0 accepts its frames, draws with func_00040B10 (mode 5) or func_000406D0 with device state 68
// set to 1 (put back afterwards), all between func_001BA9C0 and func_001BAA50.
void Object_00040540::func_00047690(int first, int second)
{
    if (surface) {
        func_001BA9C0();
        func_00047970((void *)first, second);
        func_001BA8F0(matrices);
        if (func_0005BCE0(count, frames)) {
            int state = data_00251D80;
            if (data_00251D80 != 1) {
                data_00251D80 = 1;
                data_00251D6C->slot68(1);
            }
            if (mode == 5) {
                func_00040B10(matrices);
            } else {
                func_000406D0(matrices);
            }
            if (data_00251D80 != state) {
                data_00251D80 = state;
                data_00251D6C->slot68(state);
            }
        }
        func_001BAA50();
    }
}
