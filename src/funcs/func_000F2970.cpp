struct Game {
    void *func_000128C0(int id);
};

struct Vector3;

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

struct Object_00047470 {
    void func_00047970(void *data, int argument);
};

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

extern Game *data_0022FCE0;

struct Object_000C5B50 {
    void func_000C5B50(int *handle);
};

// The base of the small state machines (tables 0x1CDDB8, 0x1CDDCC, 0x1CF02C and 0x1CF040): slots 0 and 1 are
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
    void func_000F2970(int index, int closing);

    int state;
    char unknown_0c[0xc];
    int busy[4];
    char unknown_28[0x10];
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

// Opens (closing 0) or closes blend `index` of the first state machine with the motion of its key index + 2. Opening
// (unless it is open, state 2) restarts a closed one's time, takes three effects 0x4f, 0x50 and 0x51 from object
// 0xe8 (func_000651E0), poses the part again (func_00047970) and updates (func_000F25E0); closing an open one
// starts its time at the motion's frame count less one; state 1 opening, 3 closing.
void Object_000F2AA0::func_000F2970(int index, int closing)
{
    if (!closing) {
        if (busy[index] == 2) {
            return;
        }
        machine->blends[index] = machine->keys[index + 2];
        if (busy[index] == 0) {
            machine->times[index] = 0.0f;
        }
        busy[index] = 1;
        Object_000607B0 *target = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (target) {
            ids[index][0] = target->func_000651E0(0x4f, 0, 0);
            ids[index][1] = target->func_000651E0(0x50, 0, 0);
            ids[index][2] = target->func_000651E0(0x51, 0, 0);
        }
        machine->part->func_00047970(machine->motion, 0);
        func_000F25E0();
    } else {
        if (busy[index] == 0) {
            return;
        }
        machine->blends[index] = machine->keys[index + 2];
        if (busy[index] == 2) {
            machine->times[index] = machine->blends[index][1] - 1.0f;
        }
        busy[index] = 3;
    }
}
