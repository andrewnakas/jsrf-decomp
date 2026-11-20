struct Object_00039BE0 {
    void func_00039D80(int *values, unsigned int count);
};

extern Object_00039BE0 data_001EFFB0;

struct Stage_0005BAD0 {
    char unknown_000[0x184];
    int *values;
    unsigned int count;
};

struct Pending_0005BA60 {
    char unknown_00[0x8];
    int *values;
    unsigned int count;
};

// Object 9.
struct Object_0004ABA0 {
    char unknown_0000[0xfe0];
    int delay;
    Pending_0005BA60 *pending;
    char unknown_0fe8[0x58];
    Stage_0005BAD0 *stage;

    void func_0005B570(int *values, unsigned int count);
    void func_0005BA60();
};

// Counts +0xfe0 down while +0xfe4 holds something; at zero hands its values to object 0x1EFFB0 (func_00039D80) and
// clears it. Then runs func_0005B570 with the stage's values at +0x184 / +0x188.
void Object_0004ABA0::func_0005BA60()
{
    if (pending) {
        if (delay > 0) {
            delay--;
        }
        if (delay <= 0) {
            data_001EFFB0.func_00039D80(pending->values, pending->count);
            pending = 0;
        }
    }
    func_0005B570(stage->values, stage->count);
}
