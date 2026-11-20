struct Game {
    void func_000127C0(int index, int value);
    int func_000127E0(int index);
    void *func_000128C0(int index);
};

extern Game *data_0022FCE0;

void func_0004E930(int first, int second, int third);

struct Object_000667D0 {
    void func_000666F0(int first, int second);
};

extern Object_000667D0 *data_00251F24;

struct Object_0004EF90 {
    char unknown_00[0x44];
    int next;

    void func_0004EFA0();
};

// A state handler (table 0x1FA008, slot 0): passes game values 2 and 3 to func_0004E930 and goes to state 1 by way of
// func_000666F0, (1, 0) when game value 0x1cb is set and (0, 1) otherwise.
void Object_0004EF90::func_0004EFA0()
{
    func_0004E930(data_0022FCE0->func_000127E0(2), data_0022FCE0->func_000127E0(3), 0);
    if (data_0022FCE0->func_000127E0(0x1cb)) {
        data_00251F24->func_000666F0(1, 0);
        next = 1;
    } else {
        data_00251F24->func_000666F0(0, 1);
        next = 1;
    }
}
