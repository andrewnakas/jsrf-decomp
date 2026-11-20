/* sym: ??0Object_000ECB50@@QAE@PAUNode@@HIPAUInit_000ECB50@@@Z = 0x000ECB50 */
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

// One placement (4 bytes).
struct Init_000ECB50 {
    int unknown_00;
};

// The object the factories of the table at 0x215D68 serve (func_000C0B30 makes it): a Node with its event handler
// at 0xe8.
struct Desc_000ECB50 : Node {
    char unknown_44[0x90];
    void *behaviour;
    char unknown_d8[0x10];
    int (*handler)(int event, Vector3 *position);
};

// The description func_000C0B30 hands the factory: a count at 0xc and the placements at 0x10.
struct Params_000ECB50 {
    int kind;
    char unknown_04[8];
    unsigned int count;
    Init_000ECB50 *entries;
};

// The link of a chain: func_000C6090 puts it after the previous one (or first in the owner's 0xd0) with its index.
struct Object_000C60C0 {
    virtual void func_000C6090(Object_000C60C0 *previous, Desc_000ECB50 *owner, int index);
};

int func_000EB750(int event, Vector3 *position);

// The Node child func_000ECB50 builds (0x378 bytes), a link of the chain at 0x44.
struct Object_000ECB50 : Node, Object_000C60C0 {
    Object_000ECB50(Node *owner, int id, unsigned int flags, Init_000ECB50 *init);

    char unknown_048[0x330];
};

// One of the factories of the table at 0x215D68: each placement of the description makes an Object_000ECB50 under the
// object (first free id in [0x12B2, 0x13B2], flags 0x9004), chained after the previous one; the object's event
// handler becomes func_000EB750 with each.
void func_000ECF50(Desc_000ECB50 *desc, Params_000ECB50 *params)
{
    Init_000ECB50 *entry = params->entries;
    Object_000C60C0 *previous = 0;
    for (unsigned int i = 0; i < params->count; i++, entry++) {
        Object_000ECB50 *child =
            new Object_000ECB50(desc, data_0022FCE0->func_000128E0(0x12b2, 0x13b2), 0x9004, entry);
        child->func_000C6090(previous, desc, i);
        desc->handler = func_000EB750;
        previous = child;
    }
}
