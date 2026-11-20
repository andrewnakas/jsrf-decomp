void func_00117350(int first, int second);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Stage_00056540 {
    char unknown_00[0x14];
    int unknown_14;
    char unknown_18[8];
    int unknown_20;
};

struct Other_0004AFC0 {
    char unknown_000[0x8d4];
    int unknown_8d4;
};

struct Object_000A1C50 {
    char unknown_000[0xe50];
    int unknown_e50;
};

struct Object_0004ABA0 {
    char unknown_000[0x5c];
    int state;
    char unknown_060[0xf58];
    Stage_00056540 *stage;

    void func_0004AE00();
};

// State handler 20 of the table at 0x1F9888: when object +0xc after the stage's +0x14 exists and the player whose id
// it keeps at +0x8d4 is in mode 0x15 or 0x16 (+0xe50), func_00117350 (the stage's +0x20, 0x14) and state 0x15.
void Object_0004ABA0::func_0004AE00()
{
    Other_0004AFC0 *other = (Other_0004AFC0 *)data_0022FCE0->func_000128C0(stage->unknown_14 + 0xc);
    if (other) {
        Object_000A1C50 *player = (Object_000A1C50 *)data_0022FCE0->func_000128C0(other->unknown_8d4);
        if (player && (player->unknown_e50 == 0x15 || player->unknown_e50 == 0x16)) {
            func_00117350(stage->unknown_20, 0x14);
            state = 0x15;
        }
    }
}
