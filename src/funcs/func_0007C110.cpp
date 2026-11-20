struct Game {
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

    void func_0007C110();
};

// State handler 8 of the table at 0x20D2B8: once object 0x1dda is gone, moves to state 9 and runs func_000666F0 of
// the object at 0x251F24 (0, 0).
void Object_0007C250::func_0007C110()
{
    if (!data_0022FCE0->func_000128C0(0x1dda)) {
        state = 9;
        data_00251F24->func_000666F0(0, 0);
    }
}
