// One step of the object's sequence (24 bytes each; the list at 0x40).
struct Step_000D8A40 {
    char unknown_00[0x10];
    unsigned int repeats;
    char unknown_14[0x4];
};

struct Object_000D8A40 {
    char unknown_000[0x8];
    int state;
    char unknown_00c[0x34];
    Step_000D8A40 *steps;
    int step;
    char unknown_048[0x8];
    unsigned int count;
    char unknown_054[0x8c];
    int next;
    char unknown_0e4[0x4];
    int phase;

    void func_000D8440();
    void func_000D9220();
    void func_000D96D0();
};

// A handler of the table at 0x217378: in phase 2 counts one more pass (0x50) and stays in state 2 until the count
// reaches the current step's repeats; then goes to state 1 with 0 at 0xe0 and runs func_000D8440 and func_000D9220.
void Object_000D8A40::func_000D96D0()
{
    if (phase == 2) {
        if (++count < steps[step].repeats) {
            state = 2;
        } else {
            state = 1;
            next = 0;
            func_000D8440();
            func_000D9220();
        }
    }
}
