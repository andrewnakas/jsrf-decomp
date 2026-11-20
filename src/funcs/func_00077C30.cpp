/* sym: ??0Object_00113700@@QAE@PAUNode@@HI@Z = 0x00113A30 */
/* sym: ??0Object_00113C40@@QAE@PAUNode@@HI@Z = 0x00114250 */
/* const: 0x10003 */
struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
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

struct Game {
    void *func_000128C0(int id);
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

// Lane 3's nodes made at 0x114250 (table 0x1D2B28, 0x194 bytes) and 0x113A30 (0x210 bytes).
struct Object_00113C40 : Node {
    Object_00113C40(Node *owner, int id, unsigned int flags);

    char unknown_44[0x150];
};

struct Object_00113700 : Node {
    Object_00113700(Node *owner, int id, unsigned int flags);

    char unknown_44[0x1cc];
};

// The menu object (table 0x1CCD18).
struct Object_000780F0 : Node {
    char unknown_044[0x80];
    int child_c4;
    int child_c8;

    void func_00077C30(int which, int show);
};

// Shows or hides one of two nodes under object 9 (ids in 0x1208-0x1288, flags 0x10003): 0 an Object_00113C40 kept at
// +0xc4, 1 an Object_00113700 kept at +0xc8. Showing does nothing while the id is set; hiding takes the node out.
void Object_000780F0::func_00077C30(int which, int show)
{
    if (show) {
        switch (which) {
        case 0:
            if (!child_c4) {
                child_c4 = data_0022FCE0->func_000128E0(0x1208, 0x1288);
                new Object_00113C40((Node *)data_0022FCE0->func_000128C0(9), child_c4, 0x10003);
            }
            break;
        case 1:
            if (!child_c8) {
                child_c8 = data_0022FCE0->func_000128E0(0x1208, 0x1288);
                new Object_00113700((Node *)data_0022FCE0->func_000128C0(9), child_c8, 0x10003);
            }
            break;
        }
    } else {
        switch (which) {
        case 0:
            if (child_c4) {
                if (data_0022FCE0->func_000128C0(child_c4)) {
                    Node *node = (Node *)data_0022FCE0->func_000128C0(child_c4);
                    if (node) {
                        node->func_00011BE0(node);
                        node->func_00011C20(node->child);
                    }
                }
                child_c4 = 0;
            }
            break;
        case 1:
            if (child_c8) {
                if (data_0022FCE0->func_000128C0(child_c8)) {
                    Node *node = (Node *)data_0022FCE0->func_000128C0(child_c8);
                    if (node) {
                        node->func_00011BE0(node);
                        node->func_00011C20(node->child);
                    }
                }
                child_c8 = 0;
            }
            break;
        }
    }
}
