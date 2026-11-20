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

// The child of Node whose table is at 0x1D1D00; slot 1 runs the handlers of data_0021FF88 by the mode at 0x60.
struct Object_00100770 {
    char unknown_00[0x44];
    unsigned int state;
    int value_48;
    char unknown_4c[4];
    Motion_0005F060 *motion;
    float time;
    char unknown_58[0x34];
    int shown;
    int owner;

    void func_00100AB0();
};

// Entry 1 of data_0021FF88, by the state at 0x44 and the owner (id at 0x90): 0 takes func_00107AB0 of the owner and
// starts at time 0; 1 waits for the owner's flag 0x40000000 (then shown, state 2); 2 plays the motion at 0x50 to its
// last frame (state 3); 3 waits for the flag to clear (state 5); 5 runs the time back by 2 to 0 (then not shown,
// state 1).
void Object_00100770::func_00100AB0()
{
    Object_00107FE0 *object = (Object_00107FE0 *)data_0022FCE0->func_000128C0(owner);
    switch (state) {
    case 0:
        value_48 = object->func_00107AB0();
        time = 0.0f;
        state = 1;
    case 1:
        if (object->flags & 0x40000000) {
            shown = 1;
            state = 2;
        }
        break;
    case 2: {
        time += 1.0f;
        float end = motion->frames - 1.0f;
        if (time > end) {
            time = end;
            state = 3;
        }
        if (!(object->flags & 0x40000000)) {
            state = 5;
        }
        break;
    }
    case 3:
        if (!(object->flags & 0x40000000)) {
            state = 5;
        }
        break;
    case 5:
        time -= 2.0f;
        if (time <= 0.0f) {
            time = 0.0f;
            shown = 0;
            state = 1;
        }
        if (object->flags & 0x40000000) {
            shown = 1;
            state = 2;
        }
        break;
    }
}
