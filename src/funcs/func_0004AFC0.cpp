struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Stage_00056540 {
    char unknown_00[0x14];
    int unknown_14;
};

struct Other_0004AFC0 {
    char unknown_000[0x8b0];
    int unknown_8b0;
    int unknown_8b4;
};

struct Object_0004ABA0 {
    char unknown_000[0x5c];
    int state;
    char unknown_060[0xf58];
    Stage_00056540 *stage;

    void func_0004AFC0();
};

// State handler 25 of the table at 0x1F9888: moves to state 0x1a once object +0xc after the stage's +0x14 is in mode
// 0 or 6 with +0x8b0 clear.
void Object_0004ABA0::func_0004AFC0()
{
    Other_0004AFC0 *other = (Other_0004AFC0 *)data_0022FCE0->func_000128C0(stage->unknown_14 + 0xc);
    if (other && (other->unknown_8b4 == 0 || other->unknown_8b4 == 6) && !other->unknown_8b0) {
        state = 0x1a;
    }
}
