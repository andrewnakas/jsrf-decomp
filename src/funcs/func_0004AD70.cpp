int func_00106FB0(unsigned int id);

struct Game {
    void *func_000128C0(int id);
    void func_00012730(int argument);
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
    char unknown_060[0x240];
    int results[5];
    int unknown_2b4;
    char unknown_2b8[0xd00];
    Stage_00056540 *stage;

    void func_0004AD70();
};

// State handler 17 of the table at 0x1F9888: when object +0xc after the stage's +0x14 and the object whose id it keeps
// at +0x8d8 exist and func_00106FB0 gives a result of at least 0 for that one's +0x23c, keeps it at +0x2a0 (by the
// stage's +0x14), the state kept at +0x2b4, the stage's values to func_00039D80 of 0x1EFFB0, func_00012730 (0).
void Object_0004ABA0::func_0004AD70()
{
    Other_0004AFC0 *other = (Other_0004AFC0 *)data_0022FCE0->func_000128C0(stage->unknown_14 + 0xc);
    if (other) {
        Owner_0004AD10 *owner = (Owner_0004AD10 *)data_0022FCE0->func_000128C0(other->unknown_8d8);
        if (owner) {
            int result = func_00106FB0(owner->unknown_23c);
            if (result >= 0) {
                results[stage->unknown_14] = result;
                state = unknown_2b4;
                data_001EFFB0.func_00039D80(stage->values, stage->count);
                data_0022FCE0->func_00012730(0);
            }
        }
    }
}
