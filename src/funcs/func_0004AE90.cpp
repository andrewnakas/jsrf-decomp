int func_00106FB0(unsigned int id);
void func_00116840();

struct Game {
    void *func_000128C0(int id);
    void func_000127C0(int first, int second);
};

extern Game *data_0022FCE0;

struct Object_00039BE0 {
    void func_00039D80(int *values, unsigned int count);
};

extern Object_00039BE0 data_001EFFB0;

struct Stage_00056540 {
    char unknown_00[8];
    int *values;
    unsigned int count;
    char unknown_10[4];
    int unknown_14;
};

struct Other_0004AFC0 {
    char unknown_000[0x8d8];
    int unknown_8d8;
};

struct Owner_0004AD10 {
    char unknown_000[0x23c];
    unsigned int unknown_23c;
};

struct Object_0004ABA0 {
    char unknown_000[0x5c];
    int state;
    char unknown_060[0xf58];
    Stage_00056540 *stage;

    void func_0004AE90();
};

// State handler 23 of the table at 0x1F9888: when object +0xc after the stage's +0x14 and the object whose id it keeps
// at +0x8d8 exist and func_00106FB0 gives a result of at least 0 for that one's +0x23c: func_00116840, the stage's
// values to func_00039D80 of 0x1EFFB0, then for result 0 func_000127C0 (0x199, 10) of the game and state 0x63, for
// result 1 state 0x6b.
void Object_0004ABA0::func_0004AE90()
{
    Other_0004AFC0 *other = (Other_0004AFC0 *)data_0022FCE0->func_000128C0(stage->unknown_14 + 0xc);
    if (other) {
        Owner_0004AD10 *owner = (Owner_0004AD10 *)data_0022FCE0->func_000128C0(other->unknown_8d8);
        if (owner) {
            int result = func_00106FB0(owner->unknown_23c);
            if (result >= 0) {
                func_00116840();
                data_001EFFB0.func_00039D80(stage->values, stage->count);
                switch (result) {
                case 0:
                    data_0022FCE0->func_000127C0(0x199, 10);
                    state = 0x63;
                    break;
                case 1:
                    state = 0x6b;
                    break;
                }
            }
        }
    }
}
