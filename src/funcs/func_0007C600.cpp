int func_00025680();
int func_000256A0(unsigned int index, int argument);
int func_000256C0(unsigned int index, int argument);
void func_00024620(unsigned int mode, float rate);

struct Game {
    void func_000127C0(int first, int second);
    int func_000127E0(int id);
};

extern Game *data_0022FCE0;

struct Object_000667D0 {
    void func_000666F0(int first, int second);
};

extern Object_000667D0 *data_00251F24;

struct Object_0007C250 {
    char unknown_00[0x48];
    int state;

    void func_0007C600();
};

// State handler 20 of the table at 0x20D2B8. With the game's entry 0x1a8 at 1: once need 0x12 (1) is neither ready
// nor held back (func_000256C0, func_00025680), starts it (func_000256A0), goes to state 0x15, fades at 1/60
// (func_00024620) and calls func_000666F0(0, 1) of 0x251F24. Otherwise with entry 0x1a7 set: state 0x2c, entry 0
// to 0x14 and entry 0x1a7 cleared. Otherwise starts need 0x12 (0) the same way (without the state) and, once it is
// ready, starts need 0xa (0), goes to state 0x15 and fades at 1/60.
void Object_0007C250::func_0007C600()
{
    switch (data_0022FCE0->func_000127E0(0x1a8)) {
    case 1:
        if (!func_000256C0(0x12, 1) && !func_00025680()) {
            func_000256A0(0x12, 1);
            state = 0x15;
            func_00024620(0, 0.016666668f);
            data_00251F24->func_000666F0(0, 1);
        }
        break;
    default:
        if (!data_0022FCE0->func_000127E0(0x1a7)) {
            if (!func_000256C0(0x12, 0) && !func_00025680()) {
                func_000256A0(0x12, 0);
                func_00024620(0, 0.016666668f);
                data_00251F24->func_000666F0(0, 1);
            }
            if (func_000256C0(0x12, 0)) {
                func_000256A0(0xa, 0);
                state = 0x15;
                func_00024620(0, 0.016666668f);
            }
        } else {
            state = 0x2c;
            data_0022FCE0->func_000127C0(0, 0x14);
            data_0022FCE0->func_000127C0(0x1a7, 0);
        }
        break;
    }
}
