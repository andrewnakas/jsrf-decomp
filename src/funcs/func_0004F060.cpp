struct Game {
    void func_000127C0(int index, int value);
    int func_000127E0(int index);
    void *func_000128C0(int index);
};

extern Game *data_0022FCE0;

struct Object_000667D0 {
    void func_000666F0(int first, int second);
};

extern Object_000667D0 *data_00251F24;

struct Object_0004EF90 {
    char unknown_00[0x44];
    int next;

    void func_0004F060();
};

// A state handler (table 0x1FA008, slot 4): while object 9 does not exist, goes to state 5 by way of func_000666F0,
// (1, 0) when game value 10 is set and (0, 1) otherwise.
void Object_0004EF90::func_0004F060()
{
    if (data_0022FCE0->func_000128C0(9) == 0) {
        if (data_0022FCE0->func_000127E0(10)) {
            data_00251F24->func_000666F0(1, 0);
            next = 5;
        } else {
            data_00251F24->func_000666F0(0, 1);
            next = 5;
        }
    }
}
