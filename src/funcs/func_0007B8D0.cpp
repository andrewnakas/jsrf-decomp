/* sym: ?func_00011C90@Object_0007AF70@@UAEXXZ = 0x0007B8D0 */
struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C90_5();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C90_9();
    virtual void func_00011C80_4(int argument);

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

/* const: 0x10003 */
struct Game {
    void *func_000128C0(int index);
    int func_000127E0(int index);
    void func_000127C0(int index, int value);
};

extern Game *data_0022FCE0;

int func_0004EA30();
int func_001167F0();
void func_00117350(int first, int second);
void func_00024620(unsigned int color, float step);
void func_0004E930(int first, int second, int third);
void func_00055530(int value);

struct Step_0007AF80;

/* sym: ??0Object_0007AF80@@QAE@PAUNode@@HIPAUStep_0007AF80@@H@Z = 0x0007B850 */
/* sym: ??0Object_000728C0@@QAE@PAUNode@@HI@Z = 0x000728E0 */
/* sym: ??0Object_0007E010@@QAE@PAUNode@@HI@Z = 0x0007E030 */

struct Object_0007AF80 : Node {
    Object_0007AF80(Node *owner, int id, unsigned int flags, Step_0007AF80 *steps, int count);
    char unknown_44[0x8c];
};

struct Object_000728C0 : Node {
    Object_000728C0(Node *owner, int id, unsigned int flags);
    char unknown_44[0x6c];
};

struct Object_0007E010 : Node {
    Object_0007E010(Node *owner, int id, unsigned int flags);
    char unknown_44[0x54];
};

// One entry of a sequence (0x1c bytes): its length in frames, four settings, the steps of its camera.
struct Entry_0007B8D0 {
    unsigned int length;
    int settings[4];
    Step_0007AF80 *steps;
    int count;
};

struct Sequence_0007B8D0 {
    unsigned int count;
    char unknown_04[0x14];
    Entry_0007B8D0 *entries;
};

// The class whose table is at 0x1CCE30: overrides slots 1 (7B8D0).
struct Object_0007AF70 : Node {
    virtual ~Object_0007AF70();
    virtual void func_00011C90();

    unsigned int index;
    unsigned int timer;
    Sequence_0007B8D0 *sequence;
    int unknown_50;
    int unknown_54;
    int unknown_58;
    int unknown_5c;
};

// Slot 1: plays a sequence of entries. While +0x58 is set it waits (for func_0004EA30, then for func_001167F0 to report
// 2). Otherwise it counts the entry's frames down (fading out 60 frames before the end of the last one); at the end
// of an entry it starts the next one (settings 1 and 0x14d to 0x150, a camera 0x7B850 on its steps and, for the
// first one, object 0x1DED or 0x1DD8); after the last one it kills object 0xb and itself.
void Object_0007AF70::func_00011C90()
{
    if (unknown_58) {
        if (unknown_54) {
            if (func_0004EA30()) {
                unknown_54 = 0;
                if (data_0022FCE0->func_000127E0(0x1cb)) {
                    func_00117350(0x1b, 0);
                } else {
                    func_00117350(0, 0);
                }
            }
        } else if (func_001167F0() == 2) {
            unknown_58 = 0;
        }
        return;
    }
    if (timer > 0) {
        timer--;
        if (timer == 0) {
            Node *node = (Node *)data_0022FCE0->func_000128C0(9);
            if (node) {
                node->func_00011BE0(node);
                node->func_00011C20(node->child);
            }
            node = (Node *)data_0022FCE0->func_000128C0(3);
            if (node) {
                node->func_00011BE0(node);
                node->func_00011C20(node->child);
            }
        } else if (index == sequence->count && timer <= 0x3c && !unknown_5c) {
            func_00024620(0xff000000, 1.0f / 60.0f);
            unknown_5c = 1;
        }
        return;
    }
    if (index < sequence->count) {
        data_0022FCE0->func_000127C0(1, 1);
        for (unsigned int i = 0; i < 4; i++) {
            data_0022FCE0->func_000127C0(i + 0x14d, sequence->entries[index].settings[i]);
        }
        timer = sequence->entries[index].length;
        if (unknown_50) {
            func_00055530(0);
        } else {
            func_0004E930(data_0022FCE0->func_000127E0(2), data_0022FCE0->func_000127E0(3), 0);
            func_00055530(1);
        }
        new Object_0007AF80(this, 3, 1, sequence->entries[index].steps, sequence->entries[index].count);
        if (unknown_50) {
            if (data_0022FCE0->func_000127E0(0x1cb)) {
                new Object_000728C0(this, 0x1ded, 0x10003);
            } else if (!data_0022FCE0->func_000127E0(9)) {
                new Object_0007E010(this, 0x1dd8, 0x10003);
            }
            unknown_50 = 0;
        }
        index++;
        return;
    }
    Node *node = (Node *)data_0022FCE0->func_000128C0(0xb);
    if (node) {
        node->func_00011BE0(node);
        node->func_00011C20(node->child);
    }
    func_00011BE0(this);
    func_00011C20(child);
}
