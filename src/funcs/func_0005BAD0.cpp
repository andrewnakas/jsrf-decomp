int func_0004EBC0(int *value);
int func_0004EC30(int *value);

struct Game {
    int func_000127E0(int id);
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Stage_0005BAD0 {
    char unknown_000[0x8];
    unsigned int flags;
    char unknown_00c[0x170];
    int first;
    int second;
};

// Object 9.
struct Object_0004ABA0 {
    char unknown_0000[0x5c];
    unsigned int state;
    char unknown_0060[0x254];
    int unknown_2b4;
    char unknown_02b8[0xd80];
    int unknown_1038;
    int unknown_103c;
    Stage_0005BAD0 *stage;

    void func_00054750();
    void func_00056990(int first, int second);
    int func_00057DE0();
    void func_00057F90(int value);
    void func_0005BA60();
    void func_0005BAD0();
};

// State handler 15 of the table at 0x1F9888: with setting 0x19b, state 0x6b. Otherwise runs func_00056990 with the
// stage's +0x17c and +0x180 and func_0005BA60; when func_00057DE0 finds something, sets +0x2b4 to 0xf and hands it
// to func_00057F90. Else state 0x6d when func_0004EC30 or func_0004EBC0 accept +0x103c, the stage has one of flags
// 27-29, +0x1038 is clear and object 0x1167 is gone; then func_00054750. (func_00056990, func_0005BA60,
// func_00057DE0 and func_00054750 are open; declared from their calls and returns.)
void Object_0004ABA0::func_0005BAD0()
{
    if (data_0022FCE0->func_000127E0(0x19b)) {
        state = 0x6b;
        return;
    }
    func_00056990(stage->first, stage->second);
    func_0005BA60();
    int found = func_00057DE0();
    if (found >= 0) {
        unknown_2b4 = 0xf;
        func_00057F90(found);
        return;
    }
    if ((func_0004EC30(&unknown_103c) || func_0004EBC0(&unknown_103c)) && (stage->flags & 0x38000000) &&
        !unknown_1038 && !data_0022FCE0->func_000128C0(0x1167))
        state = 0x6d;
    func_00054750();
}
