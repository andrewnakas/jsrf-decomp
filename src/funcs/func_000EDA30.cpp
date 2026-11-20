/* sym: ??0Object_000ED7E0@@QAE@PAUNode@@HIPAUInit_000ED7E0@@H@Z = 0x000ED7E0 */
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
struct Init_000ED7E0 {
    char unknown_00[0x1c];
};

// The object the factories of the table at 0x215D68 serve (func_000C0B30 makes it): a Node with its behaviour at
// 0xd4 and its event handler at 0xe8.
struct Desc_000E5380 : Node {
    char unknown_44[0x90];
    void *behaviour;
    char unknown_d8[0x10];
    int (*handler)(int event, Vector3 *position);
};

// The description func_000C0B30 hands the factory: a count at 0xc and the placements at 0x10.
struct Params_000E5380 {
    int kind;
    char unknown_04[8];
    unsigned int count;
    Init_000ED7E0 *entries;
};

void *func_00025700(unsigned int first, int second, int third, int fourth);

// The link of a chain: func_000C6090 puts it after the previous one (or first in the owner's 0xd0) with its index.
struct Object_000C60C0 {
    virtual void func_000C6090(Object_000C60C0 *previous, Desc_000E5380 *owner, int index);
};

// The Node child func_000ED7E0 builds (0xf0 bytes), a link of the chain at 0x44.
struct Object_000ED7E0 : Node, Object_000C60C0 {
    Object_000ED7E0(Node *owner, int id, unsigned int flags, Init_000ED7E0 *init, int index);

    char unknown_048[0xa8];
};

// Entry 22 of the factory table at 0x215D68: each placement of the description makes an Object_000ED7E0 under it
// (first free id in [0x12B2, 0x13B2], flags 0x100, with its index), chained after the previous one; then touches
// resource (5, 0x16).
void func_000EDA30(Desc_000E5380 *desc, Params_000E5380 *params)
{
    Init_000ED7E0 *entry = params->entries;
    Object_000C60C0 *previous = 0;
    for (unsigned int i = 0; i < params->count; i++, entry++) {
        Object_000ED7E0 *child =
            new Object_000ED7E0(desc, data_0022FCE0->func_000128E0(0x12b2, 0x13b2), 0x100, entry, i);
        child->func_000C6090(previous, desc, i);
        previous = child;
    }
    func_00025700(5, 0x16, 0, 0);
}
