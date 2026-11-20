
struct Game {
    void func_000126D0(int value);
    void func_000127C0(int id, int value);
    int func_000127E0(int id);
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

    void func_00056990(int first, int second);
    void func_0005BA60();
    void func_0005BC20();
};

// State handler 110 of the table at 0x1F9888: runs func_00056990 with the stage's +0x17c and +0x180 and func_0005BA60;
// then, with setting 0x1a1: state 0x6f with setting 0x1ae; else state 0x63 with setting 0x19c (setting 0x199 to
// 0x38); else the game's func_000126D0 (0) and state 0x6b with setting 0x19b, 0xf without.
void Object_0004ABA0::func_0005BC20()
{
    func_00056990(stage->first, stage->second);
    func_0005BA60();
    if (data_0022FCE0->func_000127E0(0x1a1)) {
        if (data_0022FCE0->func_000127E0(0x1ae)) {
            state = 0x6f;
            return;
        }
        if (data_0022FCE0->func_000127E0(0x19c)) {
            data_0022FCE0->func_000127C0(0x199, 0x38);
            state = 0x63;
            return;
        }
        if (data_0022FCE0->func_000127E0(0x19b)) {
            data_0022FCE0->func_000126D0(0);
            state = 0x6b;
        } else {
            data_0022FCE0->func_000126D0(0);
            state = 0xf;
        }
    }
}
