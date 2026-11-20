int func_0004EC30(int *value);
void func_000F7920(float value);
void func_000FEB30(unsigned int value, int argument);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
extern int data_00251F20;

struct Object_00039BE0 {
    void func_00039D80(int *values, unsigned int count);
};

extern Object_00039BE0 data_001EFFB0;

struct Object_0006CE00 {
    void func_0006CBA0();
};

struct Object_000A63C0 {
    void func_000A6190();
};

struct Stage_00056540 {
    char unknown_00[8];
    int *values;
    unsigned int count;
    char unknown_10[8];
    int unknown_18;
};

// What +0x1040 points at: a word at +0x8.
struct Setting_00052950 {
    char unknown_00[8];
    unsigned int unknown_08;
};

struct Object_0004ABA0 {
    char unknown_0000[0x5c];
    int state;
    char unknown_0060[0x254];
    int unknown_2b4;
    char unknown_02b8[0xd00];
    Stage_00056540 *stage;
    char unknown_0fbc[4];
    int unknown_fc0;
    char unknown_0fc4[0x74];
    int unknown_1038;
    char unknown_103c[4];
    Setting_00052950 *picks;
    int *ids;

    void func_0004C960();
    void func_0004D880();
    void func_00052950();
};

// A state handler of Object_0004ABA0: when func_0004EC30 gives a value and +0x1038 is clear, keeps it at 0x251F20
// and goes to state 0x20. Otherwise, unless object 0x1dde exists, hands the stage's values to func_00039D80 of
// 0x1EFFB0, goes to the state at +0x2b4, runs func_0006CBA0 of the object with the id of the stage's +0x18 and
// func_000A6190 of object 0xc (each if it exists), func_0004C960, func_000FEB30 with the complement and the word at
// +0x8 of +0x1040, func_0004D880, sets +0xfc0 and calls func_000F7920(0).
void Object_0004ABA0::func_00052950()
{
    int value;
    if (func_0004EC30(&value) && !unknown_1038) {
        data_00251F20 = value;
        state = 0x20;
        return;
    }
    if (data_0022FCE0->func_000128C0(0x1dde)) {
        return;
    }
    data_001EFFB0.func_00039D80(stage->values, stage->count);
    state = unknown_2b4;
    Object_0006CE00 *object = (Object_0006CE00 *)data_0022FCE0->func_000128C0(ids[stage->unknown_18]);
    if (object) {
        object->func_0006CBA0();
    }
    Object_000A63C0 *other = (Object_000A63C0 *)data_0022FCE0->func_000128C0(0xc);
    if (other) {
        other->func_000A6190();
    }
    func_0004C960();
    func_000FEB30(~picks->unknown_08, 0);
    func_000FEB30(picks->unknown_08, 1);
    func_0004D880();
    unknown_fc0 = 1;
    func_000F7920(0.0f);
}
