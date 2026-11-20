/* sym: ??0Object_00106390@@QAE@PAUNode@@HIHHI@Z = 0x001067A0 */
struct Game {
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

struct Node {
    virtual ~Node();

    unsigned int flags;
    int id;
    char unknown_0c[0x34];
};

// The child of Node with the table at 0x1D1FD8 (0x9c bytes).
struct Object_00106390 {
    Object_00106390(Node *owner, int id, unsigned int flags, int ownerId, int first, unsigned int mask);
    virtual ~Object_00106390();

    char unknown_04[0x98];
};

// One of the sixteen children at 0xa4 (0x10 bytes): its kind, id and value.
struct Slot_00107C00 {
    int kind;
    int id;
    int value;
    int unknown_0c;
};

// The objects with ids 0x115e to 0x1162 (table 0x1D2020).
struct Object_00107FE0 : Node {
    char unknown_040[0x64];
    Slot_00107C00 slots[16];

    void func_00107C00(int value, int first, int kind);
};

// Unless a child of that kind and value is already there (searching the sixteen slots at 0xa4 from the last), puts
// one in the lowest free slot: an Object_00106390 under this object with the first free id in [0x11AE, 0x11BE],
// flags 0x100, this object's id, `first`, and the mask 0xc0000000 for kind 1.
void Object_00107FE0::func_00107C00(int value, int first, int kind)
{
    int free = -1;
    int found = 0;
    unsigned int mask = 0;
    for (int i = 15; i >= 0; i--) {
        if (slots[i].kind == kind && slots[i].value == value && slots[i].id != -1) {
            found = 1;
            break;
        }
        if (slots[i].id == -1) {
            free = i;
        }
    }
    switch (kind) {
    case 1:
        mask = 0xc0000000;
    }
    if (!found && free != -1) {
        slots[free].kind = kind;
        slots[free].id = data_0022FCE0->func_000128E0(0x11ae, 0x11be);
        new Object_00106390(this, slots[free].id, 0x100, id, first, mask);
        slots[free].value = value;
    }
}
