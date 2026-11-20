
struct Game {
    int func_000127E0(int id);
};

struct Object_00039BE0 {
    void func_00039C80(int value);
    void func_00039C90(int value);
};

extern Object_00039BE0 data_001EFFB0;

struct Object_0003E750 {
    void func_0003E930();
};

extern Object_0003E750 data_002314B0;
extern int data_00251F20;

struct Object_0004ABA0;

int func_00078B50(Object_0004ABA0 *object, int value);

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
    char unknown_0000[0x50];
    int unknown_50;
    char unknown_0054[0x4];
    int unknown_58;
    unsigned int state;
    char unknown_0060[0x254];
    int unknown_2b4;
    char unknown_02b8[0xd80];
    int unknown_1038;
    int unknown_103c;
    Stage_0005BAD0 *stage;

    void func_00056990(int first, int second);
    void func_0005BA60();
    void func_0005BB90();
};

// State handler 109 of the table at 0x1F9888: runs func_00056990 with the stage's +0x17c and +0x180 and func_0005BA60;
// when func_00078B50 (open; declared `int (Object_0004ABA0 *, int)`) accepts this object and +0x58: hands +0x50 and
// setting 0x198 to data_001EFFB0 (func_00039C80, func_00039C90), runs data_002314B0's func_0003E930, keeps +0x103c in
// data_00251F20 and goes to state 0x6e; otherwise state 0xf.
void Object_0004ABA0::func_0005BB90()
{
    func_00056990(stage->first, stage->second);
    func_0005BA60();
    if (func_00078B50(this, unknown_58)) {
        data_001EFFB0.func_00039C80(unknown_50);
        data_001EFFB0.func_00039C90(data_0022FCE0->func_000127E0(0x198));
        data_002314B0.func_0003E930();
        data_00251F20 = unknown_103c;
        state = 0x6e;
    } else {
        state = 0xf;
    }
}
