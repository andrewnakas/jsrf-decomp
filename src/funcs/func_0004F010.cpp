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

    void func_0004F010();
};

// A state handler (table 0x1FA008, slot 2): passes game values 2 and 4 to func_0004E930, then goes to state 3.
void Object_0004EF90::func_0004F010()
{
    func_0004E930(data_0022FCE0->func_000127E0(2), data_0022FCE0->func_000127E0(4), 0);
    data_00251F24->func_000666F0(0, 1);
    next = 3;
}
