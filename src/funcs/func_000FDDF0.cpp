/* sym: ??0Object_000F7C50@@QAE@PAUNode@@HIHHHHPAM11PAXHI@Z = 0x000F7C50 */
void *__cdecl operator new(unsigned int size);

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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

struct Game {
    void *func_000128C0(int id);
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

// The text positions by kind (8 bytes each); the second word is the height.
struct Place_000FDDF0 {
    float x;
    float y;
};

extern Place_000FDDF0 data_0021FEC0[];

// The node 0xF7C50 builds (table 0x1D0770); 0xCC bytes.
struct Object_000F7C50 : Node {
    Object_000F7C50(Node *owner, int id, unsigned int flags, int first, int second, int third, int fourth,
                    float *position, float *rotation, float *scale, void *block, int value, unsigned int color);

    char unknown_40[0x8c];
};

// The child of Node whose table is at 0x1D07B0 (constructor func_000F96A0).
struct Object_000F96A0 : Node {
    char unknown_040[0x38];
    int marker;
    int kind;

    void func_000FDDF0(int show);
};

// Shows (or with 0 removes) the marker node: when showing and there is none yet, takes a free id in [0x1208, 0x1288]
// for 0x78 and makes an Object_000F7C50 (model 0x69, 0x11) at x 53 and the height of data_0021FEC0 for the kind at
// 0x7c (times -0.1, less 5); when removing, unlinks the node with that id and clears it.
void Object_000F96A0::func_000FDDF0(int show)
{
    if (show) {
        float position[3];
        position[0] = 53.0f;
        position[1] = data_0021FEC0[kind].y * -0.1f - 5.0f;
        position[2] = 0.0f;
        if (!marker) {
            marker = data_0022FCE0->func_000128E0(0x1208, 0x1288);
            new Object_000F7C50(this, marker, 0x100, 0, -1, 0x69, 0x11, position, 0, 0, 0, 0, 0);
        }
    } else {
        if (marker) {
            Node *node = (Node *)data_0022FCE0->func_000128C0(marker);
            if (node) {
                node->func_00011BE0(node);
                node->func_00011C20(node->child);
            }
        }
        marker = 0;
    }
}
