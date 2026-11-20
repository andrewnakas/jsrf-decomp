/* sym: ?func_00011C90@Object_0004FC40@@UAEXXZ = 0x00058480 */
int func_00025680();
int func_000256A0(unsigned int index, int argument);
int func_000256C0(unsigned int index, int argument);

struct Game {
    void func_000127C0(int index, int value);
};

extern Game *data_0022FCE0;

// The list at 0x1FA05C.
struct Object_0004D8C0 {
    void func_0004D8C0(int first, int second);
};

extern Object_0004D8C0 data_001FA05C;

struct Node {
    virtual ~Node();
    virtual void func_00011C90();

    char unknown_04[0x40];
};

// Object 0x12ac (table 0x1CAB98, destructor 0x4FBC0): the loading steps at +0x858.
struct Object_0004FC40 : Node {
    virtual void func_00011C90();

    char unknown_044[0x814];
    int step;
    unsigned int current;
    unsigned int next;
    int kept[9];
    unsigned int keptCount;

    unsigned int func_0004FC40();
    int func_0004FE50(unsigned int start);
    unsigned int func_0004FF00(unsigned int start);
    void func_00050010(unsigned int index);
    void func_00055820(unsigned int index);
};

// Slot 1: steps the loading of the ids around the current one (+0x858): 0 follows the game's value 0x1ac (func_0004FC40)
// and, when it moved and func_0004FE50 finds nothing to keep, sets the game's 0x1ad and goes to 1; 1 gathers the ids
// to keep (func_00050010, func_0004FF00) and goes to 2; 2 starts loading the next kept id as kind 2 (3 when it
// started) or, when all are done, clears 0x1ad and goes back to 0; 3 waits for that id and records it in the list at
// 0x1FA05C before going on with the next.
void Object_0004FC40::func_00011C90()
{
    switch (step) {
    case 0: {
        unsigned int index = func_0004FC40();
        if (current != index) {
            current = index;
            func_00055820(index);
            if (!func_0004FE50(current)) {
                step = 1;
                data_0022FCE0->func_000127C0(0x1ad, 1);
            }
        }
        break;
    }
    case 1:
        func_00050010(current);
        keptCount = func_0004FF00(current);
        next = 0;
        step = 2;
        break;
    case 2:
        if (next < keptCount) {
            if (!func_00025680() && func_000256A0(2, kept[next])) {
                step = 3;
            }
        } else {
            data_0022FCE0->func_000127C0(0x1ad, 0);
            step = 0;
        }
        break;
    case 3:
        if (func_000256C0(2, kept[next])) {
            data_001FA05C.func_0004D8C0(2, kept[next]);
            next++;
            step = 2;
        }
        break;
    }
}
