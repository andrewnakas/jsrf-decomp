struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_0007C250 {
    char unknown_00[0x48];
    int state;

    void func_0007C250();
};

void Object_0007C250::func_0007C250()
{
    if (!data_0022FCE0->func_000128C0(8)) {
        state = 13;
    }
}
