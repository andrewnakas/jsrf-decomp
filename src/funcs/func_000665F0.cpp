/* sym: ?func_00011C90_8@Object_000667D0@@UAEXXZ = 0x000665F0 */
struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C90_5();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();

    char unknown_04[0x40];
};

struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float step, int hold);
void func_00024600(int colour);
void func_00024620(unsigned int mode, float rate);

struct Game {
    void func_00012730(int value);
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The class whose table is at 0x1CB0A8 (destructor 0x663E0): overrides slot 13 here.
struct Object_000667D0 : Node {
    virtual void func_00011C90_8();

    char unknown_44[0x60];
    unsigned int flags;
    char unknown_a8[0x10];
    Motion_0005F060 *motion;
    float time;
};

// Slot 13: with flag 8 set, steps the motion (+0xb8, time +0xbc) by a half (func_0005E030) while object 0x12b0
// exists; once it is gone, clears the flag, func_00012730(0) of the game and fades to black at 1/60.
void Object_000667D0::func_00011C90_8()
{
    if (flags & 8) {
        if (data_0022FCE0->func_000128C0(0x12b0)) {
            func_0005E030(motion, &time, 0.5f, 0);
            return;
        }
        flags &= ~8;
        data_0022FCE0->func_00012730(0);
        func_00024600(0xff000000);
        func_00024620(0, 0.016666668f);
    }
}
