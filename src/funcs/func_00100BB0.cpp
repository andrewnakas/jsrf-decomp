struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The objects with ids 0x115e to 0x1162 (table 0x1D2020); flags at 0x16b0.
struct Object_00107FE0 {
    char unknown_0000[0x16b0];
    unsigned int flags;

    int func_00107AB0();
};

struct Motion_0005F060 {
    short unknown_00;
    short frames;
};

void func_00077F70(int which, int set);

// The child of Node whose table is at 0x1D1D00; slot 1 runs the handlers of data_0021FF88 by the mode at 0x60.
struct Object_00100770 {
    char unknown_00[0x44];
    unsigned int state;
    int value_48;
    char unknown_4c[4];
    Motion_0005F060 *motion;
    float time;
    Motion_0005F060 *first;
    Motion_0005F060 *second;
    char unknown_60[0x2c];
    int shown;
    int owner;

    void func_00100BB0();
};

// Entry 2 of data_0021FF88, by the state at 0x44 and the owner (id at 0x90), with func_00077F70(1, n) each frame:
// 0 takes func_00107AB0 of the owner and the first motion (0x58) from time 0; 1 (off) waits for the owner's flag
// 0x20000000 (then shown, state 2); 2 (on) plays the motion to its end and goes on with the second motion (0x5c,
// state 3); 3 (on) loops it; without the flag, 2 goes to state 5 and 3 to state 5 at the end of the first motion;
// 5 (off) runs the time back by 2 to 0 (then not shown, state 1) unless the flag is back (state 2).
void Object_00100770::func_00100BB0()
{
    Object_00107FE0 *object = (Object_00107FE0 *)data_0022FCE0->func_000128C0(owner);
    switch (state) {
    case 0:
        value_48 = object->func_00107AB0();
        motion = first;
        time = 0.0f;
        state = 1;
    case 1:
        func_00077F70(1, 0);
        if (object->flags & 0x20000000) {
            shown = 1;
            state = 2;
        }
        break;
    case 2: {
        func_00077F70(1, 1);
        time += 1.0f;
        float end = motion->frames - 1.0f;
        if (time > end) {
            time = 0.0f;
            motion = second;
            state = 3;
        }
        if (!(object->flags & 0x20000000)) {
            state = 5;
        }
        break;
    }
    case 3: {
        func_00077F70(1, 1);
        time += 1.0f;
        float end = motion->frames - 1.0f;
        if (time > end) {
            time = 0.0f;
        }
        if (!(object->flags & 0x20000000)) {
            motion = first;
            time = motion->frames - 1.0f;
            state = 5;
        }
        break;
    }
    case 5:
        func_00077F70(1, 0);
        time -= 2.0f;
        if (time <= 0.0f) {
            time = 0.0f;
            shown = 0;
            state = 1;
        }
        if (object->flags & 0x20000000) {
            shown = 1;
            state = 2;
        }
        break;
    }
}
