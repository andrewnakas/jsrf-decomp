struct Game {
    void *func_000128C0(int id);
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

struct Object_00047470 {
    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

void func_001BAA00();
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void func_001BAA50();

extern unsigned int data_0021B1EC[];
extern Vector3 data_0021B1E0;

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
    int func_000C5B10(int message, void *data);
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
    void func_000F2AA0(int index, int closing);

    int state;
    char unknown_0c[0xc];
    int busy[4];
    int pairs[2];
    char unknown_30[8];
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

// Opens (closing 0) or closes pair `index` of the first state machine: blends 4 + index and 6 + index with the
// motions of its keys 10 + index and 14 + index. Opening (unless it is open, state 2) restarts a closed pair's time,
// poses the part again (func_00047970) and sends message 0x3d with the point data_0021B1E0 under node
// data_0021B1EC[index] of the part (func_000C5B10); closing an open pair starts its time at the motion's frame count
// less one; state 1 opening, 3 closing.
void Object_000F2AA0::func_000F2AA0(int index, int closing)
{
    if (!closing) {
        if (pairs[index] == 2) {
            return;
        }
        machine->blends[index + 4] = machine->keys[index + 10];
        machine->blends[index + 6] = machine->keys[index + 14];
        if (pairs[index] == 0) {
            machine->times[index + 4] = 0.0f;
        }
        pairs[index] = 1;
        machine->part->func_00047970(machine->motion, 0);
        func_001BAA00();
        machine->part->func_000480C0(data_0021B1EC[index]);
        Vector3 point;
        func_001BAB20(&point, &data_0021B1E0);
        func_001BAA50();
        owner->func_000C5B10(0x3d, &point);
    } else {
        if (pairs[index] == 0) {
            return;
        }
        machine->blends[index + 4] = machine->keys[index + 10];
        machine->blends[index + 6] = machine->keys[index + 14];
        if (pairs[index] == 2) {
            machine->times[index + 4] = machine->blends[index + 4][1] - 1.0f;
        }
        pairs[index] = 3;
    }
}
