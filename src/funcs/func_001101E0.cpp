/* sym: ?func_00011C90@Object_0010FD30@@UAEXXZ = 0x001101E0 */
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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

struct Entry_001101E0 {
    int state;
    char unknown_04[0x40];
};

// The class whose table is at 0x1D2580 (constructor 0x10FD30): overrides slot 1 of Node.
struct Object_0010FD30 : Node {
    virtual void func_00011C90();

    char unknown_44[0x10];
    int count;
    char unknown_58[0x40];
    int current;
    char unknown_9c[8];
    Entry_001101E0 entries[5];
    char unknown_1f8[0x18];
    int phase;
    unsigned int timer;

    void func_0010FF20();
    void func_0010FFD0(int index);
};

// Slot 1, by the phase at +0x210: 0 starts at entry 0 and goes on as 1; 1 moves to the next entry every 5 frames
// (raising each entry's state as it is reached), and after the last of +0x54 entries sets the current entry's state
// to 2, runs func_0010FF20 and enters phase 2; 2 runs func_0010FFD0 for each entry and enters phase 3 once all are in
// state 3; 4 runs func_00011BE0 and func_00011C20 on the node.
void Object_0010FD30::func_00011C90()
{
    switch (phase) {
    case 0:
        timer = 0;
        current = 0;
        entries[current].state++;
        phase = 1;
    case 1:
        if (++timer >= 5) {
            timer = 0;
            current++;
            if (current >= count - 1) {
                entries[current].state++;
                for (int i = 0; i < count; i++) {
                    entries[current].state = 2;
                }
                func_0010FF20();
                phase = 2;
            } else {
                entries[current].state++;
            }
        }
        break;
    case 2: {
        int done = 0;
        for (int i = 0; i < count; i++) {
            func_0010FFD0(i);
            if (entries[i].state == 3) {
                done++;
            }
        }
        if (done >= count) {
            phase = 3;
        }
        break;
    }
    case 3:
        break;
    case 4:
        func_00011BE0(this);
        func_00011C20(child);
        break;
    }
}
