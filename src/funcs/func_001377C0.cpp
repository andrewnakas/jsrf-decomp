/* sym: ??1Object_001377C0@@UAE@XZ = 0x001377C0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_001377C0@@UAEXXZ = 0x00137950 */
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
    char unknown_34[0x60];
};

// The class whose table is at 0x1DEA20: overrides slot 1 of Node.
struct Game {
    void func_000127C0(int index, int value);
    int func_000127E0(int index);
};

extern Game *data_0022FCE0;

struct Object_001377C0 : Node {
    virtual ~Object_001377C0();
    virtual void func_00011C90();
};

// In modes 5 and 6 (game value 0x1ba), packs the non-negative game values 13 to 16 to the front, filling the rest
// with -1.
Object_001377C0::~Object_001377C0()
{
    unsigned int mode = data_0022FCE0->func_000127E0(0x1ba);
    if (mode >= 5 && mode <= 6) {
        int values[4];
        int i;
        for (i = 0; i < 4; i++) {
            values[i] = data_0022FCE0->func_000127E0(i + 0xd);
            data_0022FCE0->func_000127C0(i + 0xd, -1);
        }
        int next;
        for (i = 0, next = 0xd; i < 4; i++) {
            if (values[i] >= 0) {
                data_0022FCE0->func_000127C0(next, values[i]);
                next++;
            }
        }
    }
}
