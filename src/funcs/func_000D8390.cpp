struct Node {
    virtual ~Node();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(int argument);

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

struct Owner_000D8390 : Node {
    char unknown_40[0x64];
    unsigned int flags_a4;
};

struct Object_000D8A40 {
    char unknown_000[0x4];
    Owner_000D8390 *owner;
    char unknown_008[0x8];
    int ticks;
    char unknown_014[0x78];
    unsigned int blinks;
    float shown;
    float fade;
    char unknown_098[0x48];
    int next;

    void func_000D8390();
};

// A handler of the table at 0x217378: with 12 at 0xe0, fades the value at 0x94 out by 1/180 a frame (to no less
// than 0) and every fourth frame shows it at 0x90 on odd blinks (0 on even ones); after 45 blinks kills the owner
// node and everything below it and sets the owner's flag 0x20.
void Object_000D8A40::func_000D8390()
{
    if (next == 12) {
        if (fade > 0.0f) {
            fade -= 1.0f / 180.0f;
            if (fade < 0.0f) {
                fade = 0.0f;
            }
        }
        if (++ticks >= 4) {
            ticks = 0;
            if (blinks & 1) {
                shown = fade;
            } else {
                shown = 0.0f;
            }
            if (++blinks >= 45) {
                Owner_000D8390 *node = owner;
                if (node) {
                    node->func_00011BE0(node);
                    node->func_00011C20(node->child);
                }
                owner->flags_a4 |= 0x20;
            }
        }
    }
}
