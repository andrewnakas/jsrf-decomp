struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Motion_0005F060 {
    short unknown_00;
    short frames;
};

// The player: its kind at 0xfc0.
struct Player_001008E0 {
    char unknown_000[0xfc0];
    int kind;
};

// The screen: its player at 0x24.
struct Screen_001008E0 {
    char unknown_00[0x24];
    Player_001008E0 *player;
};

void *func_00025700(unsigned int index, int first, int second, int third);

// The objects with ids 0x115e to 0x1162 (table 0x1D2020); flags at 0x16b0, the id of their screen at 0x16b8.
struct Object_00107FE0 {
    char unknown_0000[0x16b0];
    unsigned int flags;
    char unknown_16b4[4];
    int screenId;

    int func_00107AB0();
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

    void func_001008E0();

    __forceinline void pick(Object_00107FE0 *object)
    {
        Player_001008E0 *player = ((Screen_001008E0 *)data_0022FCE0->func_000128C0(object->screenId))->player;
        if (player) {
            int kind = player->kind;
            if (kind == 5) {
                kind = 2;
            }
            motion = (Motion_0005F060 *)func_00025700(0xa, 0, 2, kind);
        }
    }
};

// Entry 0 of data_0021FF88, by the state at 0x44 and the owner (id at 0x90): 0 takes func_00107AB0 of the owner and
// starts at time 0; 1 waits for bit 31 of the owner's flags (then the motion of the player's kind, 5 as 2, from sprite
// set (0xa, 0, 2), shown, state 2); 2 plays it to its end (state 3); 2 and 3 take the motion again and go to state 5
// without the bit; 5 runs the time back by 2 to 0 (then not shown, state 1) and waits as 1 does.
void Object_00100770::func_001008E0()
{
    Object_00107FE0 *object = (Object_00107FE0 *)data_0022FCE0->func_000128C0(owner);
    switch (state) {
    case 0:
        value_48 = object->func_00107AB0();
        time = 0.0f;
        state = 1;
    case 1:
        if (object->flags & 0x80000000) {
            pick(object);
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
        if (!(object->flags & 0x80000000)) {
            state = 5;
        }
        pick(object);
        break;
    }
    case 3:
        pick(object);
        if (!(object->flags & 0x80000000)) {
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
        if (object->flags & 0x80000000) {
            pick(object);
            shown = 1;
            state = 2;
        }
        break;
    }
}
