/* sym: ??1Object_000B40F0@@UAE@XZ = 0x000B4490 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
void __stdcall func_0006EBE0(void *block);

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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// A device resource: slot 2 releases it.
struct Resource_000B4490 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual unsigned long __stdcall Release();
};

// Object 0xeb (constructor func_000BB1A0).
struct Object_000BAC20 {
    void func_000BAD50(int id);
};

// The class whose table is at 0x1CD8C8 (constructor func_000B4330): two buffers at 0x74 and blocks at 0x84, ten child
// ids at 0x8c counted at 0xbc, and two point objects at 0xc0 with their blocks at 0xc8.
struct Object_000B40F0 : Node {
    virtual ~Object_000B40F0();

    char unknown_44[0x30];
    Resource_000B4490 *buffers[2];
    char unknown_7c[8];
    void *blocks[2];
    int ids[10];
    char unknown_b4[8];
    int count;
    Resource_000B4490 *objects[2];
    void *points[2];

    int childId(unsigned int index)
    {
        return index < 10 ? ids[index] : 0;
    }
    __forceinline void removeChildren()
    {
        for (int i = 0; i < 10; i++) {
            if (childId(i)) {
                Node *node = (Node *)data_0022FCE0->func_000128C0(ids[i]);
                if (node) {
                    node->func_00011BE0(node);
                    node->func_00011C20(node->child);
                    ids[i] = 0;
                    count--;
                }
            }
        }
    }
};

// Takes the children out (as func_000B40F0 does), tells object 0xeb this id is gone, then releases both buffers and
// point objects and frees both blocks and point blocks.
Object_000B40F0::~Object_000B40F0()
{
    removeChildren();
    Object_000BAC20 *list = (Object_000BAC20 *)data_0022FCE0->func_000128C0(0xeb);
    if (list) {
        list->func_000BAD50(id);
    }
    for (int i = 0; i < 2; i++) {
        if (buffers[i]) {
            buffers[i]->Release();
        }
        if (blocks[i]) {
            delete blocks[i];
        }
        if (objects[i]) {
            objects[i]->Release();
            objects[i] = 0;
        }
        if (points[i]) {
            func_0006EBE0(points[i]);
            points[i] = 0;
        }
    }
}
