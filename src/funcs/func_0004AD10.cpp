void func_00106F40(unsigned int id, int value);

struct Game {
    void *func_000128C0(int id);
    void func_00012730(int argument);
};

extern Game *data_0022FCE0;

struct Stage_00056540 {
    char unknown_00[0x14];
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

    void func_0004AD10();
};

// State handler 16 of the table at 0x1F9888: if object +0xc after the stage's +0x14 exists and so does the object
// whose id it keeps at +0x8d8, func_00106F40 (that one's +0x23c, 4); then func_00012730 (1) of the game and state 0x11.
void Object_0004ABA0::func_0004AD10()
{
    Other_0004AFC0 *other = (Other_0004AFC0 *)data_0022FCE0->func_000128C0(stage->unknown_14 + 0xc);
    if (other) {
        Owner_0004AD10 *owner = (Owner_0004AD10 *)data_0022FCE0->func_000128C0(other->unknown_8d8);
        if (owner)
            func_00106F40(owner->unknown_23c, 4);
    }
    data_0022FCE0->func_00012730(1);
    state = 0x11;
}
