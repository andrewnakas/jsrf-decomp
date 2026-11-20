/* sym: ?func_00011C90@Object_000667D0@@UAEXXZ = 0x00066440 */
struct Node {
    virtual ~Node();
    virtual void func_00011C90();

    char unknown_04[0x40];
};

// A motion: its frame count at +0x2.
struct Motion_0005F060 {
    short unknown_00;
    short frames;
};

int func_000257B0();
void func_0006F730();
int __stdcall func_00145560(void *counter);

struct Game {
    void func_000127B0(int value);
};

extern Game *data_0022FCE0;

// The timer at 0x20CC48: its counter frequency at +0x8.
struct Object_0006E910 {
    char unknown_00[0x8];
    __int64 frequency;

    void func_0006E910(__int64 *out, __int64 start, __int64 end);
};

extern Object_0006E910 data_0020CC48;

// The class whose table is at 0x1CB0A8 (destructor 0x663E0): overrides slot 1 here.
struct Object_000667D0 : Node {
    virtual void func_00011C90();

    char unknown_44[0x54];
    int pending;
    char unknown_09c[4];
    unsigned int step;
    unsigned int state;
    __int64 started;
    char unknown_b0[8];
    Motion_0005F060 *motion;
    float time;
};

// Slot 1: while +0x98 is 1, counts +0xa0 round five and moves the time on by 0.2, back to 0 past the motion's last
// frame. On every fifth call: once flag 1 is set it calls func_0006F730 when func_000257B0 gives 2 or more; until
// then it sets flag 1 when 15000000 (in func_0006E910's units) have passed since the time at +0xa8. Then the game's
// func_000127B0 with 0 on the fifth call, 2 on the others.
void Object_000667D0::func_00011C90()
{
    if (pending == 1) {
        step = (step + 1) % 5;
        time += 0.2f;
        if (time > (float)motion->frames - 1.0f) {
            time = 0.0f;
        }
        if (!step) {
            if (state & 1) {
                if ((unsigned int)func_000257B0() >= 2) {
                    func_0006F730();
                }
            } else {
                __int64 now;
                func_00145560(&now);
                data_0020CC48.func_0006E910(&now, started, now);
                if (now >= 15000000) {
                    state |= 1;
                }
            }
            data_0022FCE0->func_000127B0(0);
        } else {
            data_0022FCE0->func_000127B0(2);
        }
    }
}
