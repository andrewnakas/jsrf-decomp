struct Game {
    int func_000127E0(int id);
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000667D0 {
    void func_000666F0(int first, int second);
};

extern Object_000667D0 *data_00251F24;

struct Object_0007C250 {
    char unknown_00[0x48];
    int state;

    void func_0007C450();
};

// State handler 16 of the table at 0x20D2B8: while object 0x12af does not exist, state 0xa and func_000666F0 (0, 1) of
// the object at 0x251F24 when func_000127E0 of the game gives 0 for 0x1b1 and 1 for 0x1cc; otherwise state 0x11.
void Object_0007C250::func_0007C450()
{
    if (!data_0022FCE0->func_000128C0(0x12af)) {
        if (!data_0022FCE0->func_000127E0(0x1b1) && data_0022FCE0->func_000127E0(0x1cc) == 1) {
            state = 0xa;
            data_00251F24->func_000666F0(0, 1);
            return;
        }
        state = 0x11;
    }
}
