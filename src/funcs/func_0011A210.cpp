/* sym: ??1Object_0011A210@@UAE@XZ = 0x0011A210 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_0011A210@@UAEXXZ = 0x0011A2C0 */
/* sym: ?func_00011C80@Object_0011A210@@UAEXH@Z = 0x0011A490 */
/* sym: ?func_00011C90_4@Object_0011A210@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_2@Object_0011A210@@UAEXH@Z = 0x000B3DE0 */
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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The class whose table is at 0x1D7C20: overrides slots 1, 3 of Node; slots 7, 9 hold folded thunks.
struct Object_0011A210 : Node {
    virtual ~Object_0011A210();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);

    char unknown_044[0x40];
    int ids[5];
};

// Detaches each of the five objects whose ids are at +0x84 that still exists (func_00011BE0, func_00011C20).
Object_0011A210::~Object_0011A210()
{
    for (int i = 0; i < 5; i++) {
        if (data_0022FCE0->func_000128C0(ids[i])) {
            Node *node = (Node *)data_0022FCE0->func_000128C0(ids[i]);
            if (node) {
                node->func_00011BE0(node);
                node->func_00011C20(node->child);
            }
        }
    }
}
