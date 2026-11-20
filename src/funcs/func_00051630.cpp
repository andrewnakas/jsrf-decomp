/* sym: ??1Object_0004ABA0@@UAE@XZ = 0x00051630 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
void func_00026080();
void func_00060C90();
void func_001177C0();

struct Game {
    int func_000127E0(int index);
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_0006A960 {
    void func_0006A960(int value);
};

extern Object_0006A960 data_0020C6C0;

struct Object_0004D8C0 {
    void func_0004D900(int index, int value);
};

extern Object_0004D8C0 data_001FA05C;

// The object 0x12b1.
struct Object_000C0A90 {
    void func_000C0AC0();
};

// Object 10.
struct Other_00051630 {
    char unknown_0000[0x48];
    int kind;
    char unknown_004c[0xc];
    int area;
    int state;
    char unknown_0060[0xfec];
    int stage;
};

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();

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

// Object 9 (table 0x1CAAB0).
struct Object_0004ABA0 : Node {
    virtual ~Object_0004ABA0();

    char unknown_0044[0x14];
    int area;
    char unknown_005c[0x1dc];
    int pending;
    char unknown_023c[0xdb4];
    int unknown_ff0;
    char unknown_0ff4[0x58];
    int stage;

    void func_0004CEB0();
};

// Runs func_00026080 while +0x238 is set, func_0004CEB0, func_0006A960 (0) of 0x20C6C0, func_000C0AC0 of object
// 0x12b1, func_00060C90 and func_001177C0. Unless game value 11 is set, passes its stage (+0x104c) and area (+0x58)
// to func_0004D900 of 0x1FA05C as values 3, 0 and 0x1d: when object 10 exists only those that differ from its own
// (and moves object 10 of kind 1 to state 3); otherwise all of them (the stage only while +0xff0 is clear).
Object_0004ABA0::~Object_0004ABA0()
{
    if (pending) {
        func_00026080();
    }
    func_0004CEB0();
    data_0020C6C0.func_0006A960(0);
    Object_000C0A90 *object = (Object_000C0A90 *)data_0022FCE0->func_000128C0(0x12b1);
    if (object) {
        object->func_000C0AC0();
    }
    func_00060C90();
    func_001177C0();
    if (data_0022FCE0->func_000127E0(0xb) == 0) {
        Other_00051630 *other = (Other_00051630 *)data_0022FCE0->func_000128C0(10);
        if (other) {
            if (other->stage != stage) {
                data_001FA05C.func_0004D900(3, stage);
            }
            if (other->area != area) {
                data_001FA05C.func_0004D900(0, area);
                data_001FA05C.func_0004D900(0x1d, area);
            }
            if (other->kind == 1) {
                other->state = 3;
            }
        } else {
            if (unknown_ff0 == 0) {
                data_001FA05C.func_0004D900(3, stage);
            }
            data_001FA05C.func_0004D900(0, area);
            data_001FA05C.func_0004D900(0x1d, area);
        }
    }
}
