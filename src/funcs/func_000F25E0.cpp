struct Game {
    void *func_000128C0(int id);
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000607B0 {
    void func_000606C0(int key, Vector3 *value);
};

struct Object_00047470 {
    void func_000480C0(unsigned int index);
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
    int func_000C5B10(int message, void *data);
    void func_000C5B40(int id, void *position);
    int func_000C5B70(int handle);
};

void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

extern unsigned int data_0021B1D0[];
extern Vector3 data_0021B1AC;
extern Vector3 data_0021B1B8;
extern Vector3 data_0021B1C4;

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
// 0x80; destructor func_000F2770).
struct Object_000F2AA0 : Object_000C4070 {
    Object_000F2AA0(Object_000C5B50 *owner);
    virtual void func_000C3D90();
    virtual void func_00011C90();
    virtual ~Object_000F2AA0();

    void func_000F25E0();

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

// For every blend of the first state machine in use, poses its part on matrix data_0021B1D0[i] and moves the three
// effects of object 0xe8 (func_000606C0) to the points data_0021B1AC, data_0021B1B8 and data_0021B1C4; the owner's
// handle i follows the last point (func_000C5B40), or is made again with message 0x3a when the owner lost it.
void Object_000F2AA0::func_000F25E0()
{
    Object_000607B0 *target = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (!target) {
        return;
    }
    Vector3 point;
    func_001BAA00();
    for (unsigned int i = 0; i < 4; i++) {
        if (machine->blends[i]) {
            machine->part->func_000480C0(data_0021B1D0[i]);
            func_001BAB20(&point, &data_0021B1AC);
            target->func_000606C0(ids[i][0], &point);
            func_001BAB20(&point, &data_0021B1B8);
            target->func_000606C0(ids[i][1], &point);
            func_001BAB20(&point, &data_0021B1C4);
            target->func_000606C0(ids[i][2], &point);
            if (owner->func_000C5B70(handles_84[i])) {
                owner->func_000C5B40(handles_84[i], &point);
            } else {
                handles_84[i] = owner->func_000C5B10(0x3a, &point);
            }
        }
    }
    func_001BAA50();
}
