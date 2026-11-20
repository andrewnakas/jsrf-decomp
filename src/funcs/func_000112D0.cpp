// The node's depth is compared as a float (0x110fc) and its bits are turned into the sort key (0x1110c).
union FloatBits {
    float value;
    int bits;
};

struct Node {
    virtual ~Node();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(int argument);
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(int argument);
    virtual void slot7();
    virtual void slot8();
    virtual void slot9(int argument);
    virtual void slot10();
    virtual void slot11();
    virtual void slot12(int argument);
    virtual void slot13();
    virtual void slot14();
    virtual void slot15(int argument);

    unsigned int flags;
    int id;
    unsigned int mask;
    FloatBits depth;
    int sortKey;
    float offset[3];
    Node *parent;
    Node *child;
    Node *previous;
    Node *next;
    Node *listNext;
    Node **listLink;
    Node ***listTail;
    Node *sortedNext;

    void func_000112D0(unsigned int include, int argument, int sortedArgument, unsigned int required, unsigned int maskBits,
                       unsigned int exclude, unsigned int twice);
};

struct Game {
    void func_000129D0();
    Node *func_000129F0();
    void func_00012A00(Node *node);
    void func_000131A0();
};

extern Game *data_0022FCE0;

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);

// Calls slot 6 on the nodes of a list (linked through +0x34) that pass the flag and mask tests, each between
// func_001BA9C0 and func_001BAA50. When `include` has one of the bits 0x1110 the nodes are first collected with a
// key made from their depth, sorted by the game, and slot 6 is called again in that order. Nodes with a `twice`
// flag get one more call after func_001BAAA0 on their offset.
void Node::func_000112D0(unsigned int include, int argument, int sortedArgument, unsigned int required, unsigned int maskBits,
                         unsigned int exclude, unsigned int twice)
{
    Node *node;
    if (include & 0x1110) {
        data_0022FCE0->func_000129D0();
        for (node = this; node; node = node->listNext) {
            if ((node->flags & include) && (node->mask & maskBits) && (node->flags & required) == required) {
                func_001BA9C0();
                if (!(node->flags & exclude)) {
                    node->slot6(argument);
                    if (node->depth.value >= 0.0f) {
                        node->sortKey = node->depth.bits | 0x80000000;
                    } else {
                        node->sortKey = -node->depth.bits;
                    }
                    data_0022FCE0->func_00012A00(node);
                }
                func_001BAA50();
            }
        }
        data_0022FCE0->func_000131A0();
        for (node = data_0022FCE0->func_000129F0(); node; node = node->sortedNext) {
            func_001BA9C0();
            if (node->flags & twice) {
                func_001BA9C0();
                func_001BAAA0(node->offset);
                node->slot6(sortedArgument);
                func_001BAA50();
            }
            node->slot6(sortedArgument);
            func_001BAA50();
        }
    } else {
        for (node = this; node; node = node->listNext) {
            if ((node->flags & include) && (node->mask & maskBits) && (node->flags & required) == required) {
                func_001BA9C0();
                if (!(node->flags & exclude)) {
                    if (node->flags & twice) {
                        func_001BA9C0();
                        func_001BAAA0(node->offset);
                        node->slot6(argument);
                        func_001BAA50();
                    }
                    node->slot6(argument);
                }
                func_001BAA50();
            }
        }
    }
}
