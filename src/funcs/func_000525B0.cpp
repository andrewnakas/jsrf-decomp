void func_00106F40(unsigned int id, int value);
void func_00060C90();

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Stage_00056540 {
    char unknown_00[0x14];
    int unknown_14;
    int unknown_18;
};

struct Other_0004AFC0 {
    char unknown_000[0x8d4];
    int unknown_8d4;
    int unknown_8d8;
};

struct Owner_0004AD10 {
    char unknown_000[0x23c];
    unsigned int unknown_23c;
};

struct Object_000A1C50 {
    char unknown_000[0xfd0];
    int unknown_fd0;
};

struct Object_0004ABA0 {
    char unknown_0000[0x5c];
    int state;
    char unknown_0060[0xf58];
    Stage_00056540 *stage;
    char unknown_0fbc[0x8c];
    int unknown_1048;

    void func_0004CEB0();
    void func_0004D740();
    void func_000525B0();
};

// State handler 22 of the table at 0x1F9888: when object +0xc after the stage's +0x14 exists, +0x1048 into +0xfd0 of
// the player it keeps at +0x8d4 and func_00106F40 (+0x23c of the object it keeps at +0x8d8, the stage's +0x18), each
// if it exists; then func_0004CEB0, func_00060C90, func_0004D740 and state 0x17.
void Object_0004ABA0::func_000525B0()
{
    Other_0004AFC0 *other = (Other_0004AFC0 *)data_0022FCE0->func_000128C0(stage->unknown_14 + 0xc);
    if (other) {
        Object_000A1C50 *player = (Object_000A1C50 *)data_0022FCE0->func_000128C0(other->unknown_8d4);
        if (player)
            player->unknown_fd0 = unknown_1048;
        Owner_0004AD10 *owner = (Owner_0004AD10 *)data_0022FCE0->func_000128C0(other->unknown_8d8);
        if (owner)
            func_00106F40(owner->unknown_23c, stage->unknown_18);
    }
    func_0004CEB0();
    func_00060C90();
    func_0004D740();
    state = 0x17;
}
