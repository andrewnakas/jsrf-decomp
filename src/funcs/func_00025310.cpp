/* sym: ?func_00011C90@Object_000265A0@@UAEXXZ = 0x00025310 */
int __stdcall func_00145560(void *counter);
void func_0006F730();

// The timer at 0x20CC48: its counter frequency at +0x8.
struct Object_0006E910 {
    char unknown_00[0x8];
    __int64 frequency;

    void func_0006E910(__int64 *out, __int64 start, __int64 end);
};

extern Object_0006E910 data_0020CC48;

struct Node {
    virtual ~Node();
    virtual void func_00011C90();

    unsigned int flags;
    int id;
    unsigned int mask;
    float depth;
    int sortKey;
    char unknown_18[0xc];
    Node *parent;
    Node *child;
    Node *previous;
    Node *next;
    char unknown_34[0x10];
};

// Object 7 (table 0x1C4F68).
struct Object_000265A0 : Node {
    virtual ~Object_000265A0();
    virtual void func_00011C90();

    int busy;
    unsigned int action;
    int argument;
    char unknown_050[0x140];
    __int64 started;
};

extern int (Object_000265A0::*data_001EC0F0[0x21])();

// Slot 1: while an action runs (+0x44), polls it with its handler from table 0x1EC0F0; when the handler is missing or
// reports it done, the action ends; otherwise, once 15 seconds have passed since it started (+0x190), calls
// func_0006F730.
void Object_000265A0::func_00011C90()
{
    if (busy == 1 && action < 0x21) {
        if (data_001EC0F0[action] && !(this->*data_001EC0F0[action])()) {
            __int64 time;
            func_00145560(&time);
            data_0020CC48.func_0006E910(&time, started, time);
            if (time >= 15000000) {
                func_0006F730();
            }
            return;
        }
        busy = 0;
    }
}
