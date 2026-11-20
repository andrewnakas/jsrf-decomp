int func_00106F70(unsigned int id);

struct Game {
    void *func_000128C0(int id);
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
    char unknown_10[0x10];
    int unknown_20;
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
    char unknown_000[0xfb8];
    Stage_00056540 *stage;

    void func_00053FB0(int value);
    void func_000567C0();
};

// State handler 91 of the table at 0x1F9888: when object 0xc and the object whose id it keeps at +0x8d8 exist and
// func_00106F70 accepts that one's +0x23c, the stage's values to func_00039D80 of 0x1EFFB0 and func_00053FB0 with the
// stage's +0x20.
void Object_0004ABA0::func_000567C0()
{
    Other_0004AFC0 *other = (Other_0004AFC0 *)data_0022FCE0->func_000128C0(0xc);
    if (other) {
        Owner_0004AD10 *owner = (Owner_0004AD10 *)data_0022FCE0->func_000128C0(other->unknown_8d8);
        if (owner && func_00106F70(owner->unknown_23c)) {
            data_001EFFB0.func_00039D80(stage->values, stage->count);
            func_00053FB0(stage->unknown_20);
        }
    }
}
