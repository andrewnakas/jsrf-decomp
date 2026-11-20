/* sym: ?func_00011C90@Object_0003BB10@@UAEXXZ = 0x0003BBA0 */
struct Item_000162A0 {
    char unknown_00[0xc];
    Item_000162A0 *head;
    Item_000162A0 **tail;
};

struct Object_00016200 {
    void func_000162A0(Item_000162A0 *item);
};

extern Object_00016200 data_0022FCE8;

// One entry (0x5c bytes): a state at +0x18, a countdown at +0x24 and three scales.
struct Entry_0003BC80 {
    char unknown_00[0x18];
    int state;
    float time;
    int unknown_20;
    unsigned int countdown;
    float scaleX;
    float scaleY;
    float scaleZ;
    float unknown_34;
    Item_000162A0 item;
    char unknown_4c[0x10];
};

struct Node {
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

// The node class whose table is at 0x1CA3E8 (constructor 0x3B940, destructor 0x3BB10): overrides slot 1.
struct Object_0003BB10 : Node {
    virtual void func_00011C90();

    unsigned int current;
    unsigned int count;
    char unknown_4c[4];
    Entry_0003BC80 *entries;
};

// Slot 1: the entry at +0x44 goes from state 0 to 1 and, in either, hands its item to func_000162A0 of 0x22FCE8; every
// other entry in state 2 counts down from 30, its scales following the square of the time left (x from 1 to 6, y and
// z from 1 to 0.02), and goes to state 3 at the end.
void Object_0003BB10::func_00011C90()
{
    for (unsigned int i = 0; i < count; i++) {
        if (i == current) {
            switch (entries[i].state) {
            case 0:
                entries[i].state++;
            case 1:
                data_0022FCE8.func_000162A0(&entries[i].item);
                break;
            }
        } else {
            switch (entries[i].state) {
            case 2:
                if (entries[i].countdown > 0) {
                    entries[i].countdown--;
                    float left = 1.0f - entries[i].countdown * (1.0f / 30.0f);
                    float square = left * left;
                    float scale = 1.0f - 0.98f * square;
                    entries[i].scaleZ = scale;
                    entries[i].scaleX = square * 5.0f + 1.0f;
                    entries[i].scaleY = scale;
                } else {
                    entries[i].state = 3;
                }
                break;
            }
        }
    }
}
