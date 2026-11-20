/* sym: ?func_00011C90@Object_000FEDB0@@UAEXXZ = 0x000FECC0 */
struct Game {
    void *func_000128C0(int id);
    int func_000127E0(int index);
};

struct Entry_00251DE8 {
    unsigned char flags;
    char unknown_01[0x3f];
};

struct Node {
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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

// The camera node (constructor func_00012170).
struct Object_00012170 : Node {
    char unknown_040[0x58];
};

// An entry of the list at 0xa4.
struct Entry_000FEDB0 {
    int first;
    int id;
    int value;
    int unknown_c;
};

// Object 0x1163 (constructor func_000FF230, destructor func_000FEC60).
struct Object_000FEDB0 : Object_00012170 {
    virtual void func_00011C90();

    int finished;
    int done;
    unsigned int count;
    Entry_000FEDB0 entries[8];
    char unknown_124[0x20];
    unsigned int flags_144;
};

extern Game *data_0022FCE0;
extern Entry_00251DE8 data_00251DE8[];

int func_0006F190();

// Slot 1: once the entries are done (0x9c), func_0006F190 holds and bit 31 at 0x144 is clear, the first of the
// four pads with func_000127E0(0x1bc + i) above 0 and bit 0 or 2 set finishes it: sets 0x98, clears 0x9c and the
// count, takes out the node of every entry and resets the entries.
void Object_000FEDB0::func_00011C90()
{
    if (done && func_0006F190() && (flags_144 & 0x80000000) == 0) {
        for (unsigned int i = 0; i < 4; i++) {
            if (data_0022FCE0->func_000127E0(i + 0x1bc) > 0 && (data_00251DE8[i].flags & 5)) {
                done = 0;
                finished = 1;
                count = 0;
                for (int j = 0; j < 8; j++) {
                    if (data_0022FCE0->func_000128C0(entries[j].id)) {
                        Node *node = (Node *)data_0022FCE0->func_000128C0(entries[j].id);
                        if (node) {
                            node->func_00011BE0(node);
                            node->func_00011C20(node->child);
                        }
                    }
                    entries[j].first = -1;
                    entries[j].id = -1;
                    entries[j].value = 0;
                }
                return;
            }
        }
    }
}
