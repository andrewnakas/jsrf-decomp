int func_00025680();
int func_000256A0(unsigned int index, int argument);
int func_000256C0(unsigned int index, int argument);
void func_00025740(unsigned int index, int argument);
void func_0004EAF0();

struct Game {
    void func_000127C0(int first, int second);
    int func_000127E0(int id);
};

extern Game *data_0022FCE0;

// The list at 0x1FA05C.
struct Object_0004D8C0 {
    void func_0004DAA0();
};

extern Object_0004D8C0 data_001FA05C;

struct Object_00039BE0 {
    void func_00039C70();
    void func_0003AED0();
};

extern Object_00039BE0 data_001EFFB0;

struct Object_00047110 {
    int func_00047110(void *buffer);
};

extern Object_00047110 data_001F97A8;

struct Object_000667D0 {
    void func_000666F0(int first, int second);
};

extern Object_000667D0 *data_00251F24;

struct Object_0007C250 {
    char unknown_00[0x48];
    int state;

    void func_0007C290();
};

// State handler 14 of the table at 0x20D2B8. With the game's entry 0x19a set empties the list at 0x1FA05C and stops
// needs 0x19 and 0x1a; clears entries 0xd to 0x10 (-1), runs func_0004EAF0 and sets entries 0 (0x1c), 0x1ac (-1) and
// 0xb (0). Then by entry 0x1cc: 0 runs func_0003AED0 and func_00039C70 of 0x1EFFB0, sets entries 2 and 3 to 1, 0xd
// to 0x10 to -1 and 0xd to 6 and goes to state 0x11; 2 goes to state 0x11 unless func_00047110 of 0x1F97A8 says so;
// then (and for 1) goes to state 0xf once need 0xa (0) is ready, or starts it when nothing is held back
// (func_00025680), goes to state 0xf and calls func_000666F0(1, 0) of 0x251F24.
void Object_0007C250::func_0007C290()
{
    int mode = data_0022FCE0->func_000127E0(0x1cc);
    if (data_0022FCE0->func_000127E0(0x19a)) {
        data_001FA05C.func_0004DAA0();
        func_00025740(0x19, 0);
        func_00025740(0x1a, 0);
    }
    for (unsigned int i = 0; i < 4; i++) {
        data_0022FCE0->func_000127C0(i + 0xd, -1);
    }
    func_0004EAF0();
    data_0022FCE0->func_000127C0(0, 0x1c);
    data_0022FCE0->func_000127C0(0x1ac, -1);
    data_0022FCE0->func_000127C0(0xb, 0);
    switch (mode) {
    case 0:
        data_001EFFB0.func_0003AED0();
        data_001EFFB0.func_00039C70();
        data_0022FCE0->func_000127C0(2, 1);
        data_0022FCE0->func_000127C0(3, 1);
        for (unsigned int i = 0; i < 4; i++) {
            data_0022FCE0->func_000127C0(i + 0xd, -1);
        }
        data_0022FCE0->func_000127C0(0xd, 6);
        state = 0x11;
        return;
    case 2:
        if (!data_001F97A8.func_00047110(0)) {
            state = 0x11;
            return;
        }
    case 1:
        if (func_000256C0(0xa, 0)) {
            state = 0xf;
            return;
        }
        if (!func_00025680()) {
            func_000256A0(0xa, 0);
            state = 0xf;
            data_00251F24->func_000666F0(1, 0);
        }
        return;
    }
}
