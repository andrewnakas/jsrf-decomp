struct Object_00047470;

extern int data_0021B1F4[];

// The first state machine (table 0x1CF02C): its posed part at 0x78, the motions of its keys at 0x84 (from the
// third on) blended in at 0x88 with the times at 0xb4, its motion at 0xa8.
struct Object_000F1820 {
    char unknown_000[0x78];
    Object_00047470 *part;
    char unknown_07c[8];
    short **keys;
    short *blends[8];
    void *motion;
    char unknown_0ac[8];
    float times[8];
};

struct Object_000C5B50 {
    void func_000C5B50(int *handle);
};

// The base of the small state machines (tables 0x1CDDB8, 0x1CDDCC and 0x1CF040): slots 0 and 1 are
// pure, slots 2 and 3 take an argument and do nothing, slot 4 is the destructor.
struct Object_000C4070 {
    virtual void func_000C3D90() = 0;
    virtual void func_00011C90() = 0;
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000C4070() {}

    Object_000C5B50 *owner;
};

// The state machine whose table is at 0x1CF040 (made by func_000F1FC0 with the one at 0x1CF02C, which it keeps at
// 0x80; destructor func_000F2770): the handles at 0x70 to 0xa8 belong to the owner (func_000C5B50).
struct Object_000F2AA0 : Object_000C4070 {
    Object_000F2AA0(Object_000C5B50 *owner);
    virtual void func_000C3D90();
    virtual void func_00011C90();
    virtual ~Object_000F2AA0();

    void func_000F25E0();
    void func_000F2420(int index, int create);
    void func_000F2970(int index, int closing);
    void func_000F31C0();

    int state;
    int timer;
    char unknown_10[8];
    int busy[4];
    char unknown_28[8];
    unsigned int count;
    char unknown_34[4];
    int ids[4][3];
    int first;
    int second;
    int handles_70[4];
    Object_000F1820 *machine;
    int handles_84[4];
    int handles_94[4];
    int handle_a4;
    int handle_a8;
};

// A handler of the table at 0x21B0F0 (entry at 0x21B108): while the timer at 0xc runs, func_000F2420 for both
// indexes (0x68, 0x6c) with 0 from 90 on; when it ends, closes both blends (func_000F2970 written out), moves both
// indexes on through data_0021B1F4 and, for the first two rounds (count at 0x30), opens them again in state 3;
// state 7 after the third.
void Object_000F2AA0::func_000F31C0()
{
    if (--timer <= 0) {
        int firstIndex = first;
        if (busy[firstIndex] != 0) {
            machine->blends[firstIndex] = machine->keys[firstIndex + 2];
            if (busy[firstIndex] == 2) {
                machine->times[firstIndex] = machine->blends[firstIndex][1] - 1.0f;
            }
            busy[firstIndex] = 3;
        }
        int secondIndex = second;
        if (busy[secondIndex] != 0) {
            machine->blends[secondIndex] = machine->keys[secondIndex + 2];
            if (busy[secondIndex] == 2) {
                machine->times[secondIndex] = machine->blends[secondIndex][1] - 1.0f;
            }
            busy[secondIndex] = 3;
        }
        first = data_0021B1F4[first];
        second = data_0021B1F4[second];
        if (++count < 3) {
            state = 3;
            func_000F2970(first, 0);
            func_000F2970(second, 0);
        } else {
            state = 7;
        }
    } else if (timer >= 0x5a) {
        func_000F2420(first, 0);
        func_000F2420(second, 0);
    }
}
