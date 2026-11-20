/* sym: ??0Object_000F55E0@@QAE@PAUNode@@HIPAUInit_000F55E0@@@Z = 0x000F5E70 */
struct Vector3;

struct Game {
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

struct Node {
    virtual ~Node();

    unsigned int flags;
    char unknown_08[0x3c];
};

// One placement (0x1c bytes).
struct Init_000F55E0 {
    char unknown_00[0x1c];
};

// The object the factories of the table at 0x215D68 serve (func_000C0B30 makes it): a Node with its event handler at
// 0xe8.
struct Desc_000E5380 : Node {
    char unknown_44[0xa4];
    int (*handler)(int event, Vector3 *position);
};

// The description func_000C0B30 hands the factory: a count at 0xc and the placements at 0x10.
struct Params_000E5380 {
    int kind;
    char unknown_04[8];
    unsigned int count;
    Init_000F55E0 *entries;
};

// The link of a chain: func_000C6090 puts it after the previous one (or first in the owner's 0xd0) with its index.
struct Object_000C60C0 {
    virtual void func_000C6090(Object_000C60C0 *previous, Desc_000E5380 *owner, int index);
};

int func_000F4C80(int event, Vector3 *position);

// The child of Node whose table is at 0x1CF220 (0x200 bytes), a link of the chain at 0x44.
struct Object_000F55E0 : Node, Object_000C60C0 {
    Object_000F55E0(Node *owner, int id, unsigned int flags, Init_000F55E0 *init);

    char unknown_048[0x1b8];
};

// One of the factories of the table at 0x215D68: each placement of the description makes an Object_000F55E0 under the
// object (first free id in [0x12B2, 0x13B2], flags 0x100), chained after the previous one; then func_000F4C80 becomes
// the object's event handler.
void func_000F6930(Desc_000E5380 *desc, Params_000E5380 *params)
{
    Init_000F55E0 *entry = params->entries;
    Object_000C60C0 *previous = 0;
    for (unsigned int i = 0; i < params->count; i++, entry++) {
        Object_000F55E0 *child = new Object_000F55E0(desc, data_0022FCE0->func_000128E0(0x12b2, 0x13b2), 0x100, entry);
        child->func_000C6090(previous, desc, i);
        previous = child;
    }
    desc->handler = func_000F4C80;
}
