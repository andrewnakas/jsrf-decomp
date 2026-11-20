/* sym: ??0Object_000E5380@@QAE@XZ = 0x000E5380 */
/* sym: ??0Object_000E45D0@@QAE@PAUNode@@HIPAUInit_000E45D0@@@Z = 0x000E45D0 */
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

// One placement (0x20 bytes).
struct Init_000E45D0 {
    char unknown_00[0x20];
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
    Init_000E45D0 *entries;
};

// The behaviour func_000E5380 builds (0x3c bytes); 0x4 holds the object it serves.
struct Object_000E5380 {
    Object_000E5380();
    virtual ~Object_000E5380();

    Desc_000E5380 *desc;
    char unknown_08[0x34];
};

// The link of a chain: func_000C6090 puts it after the previous one (or first in the owner's 0xd0) with its index.
struct Object_000C60C0 {
    virtual void func_000C6090(Object_000C60C0 *previous, Desc_000E5380 *owner, int index);
};

int func_000E3720(int event, Vector3 *position);

// The Node child func_000E45D0 builds (0x22c bytes), a link of the chain at 0x44.
struct Object_000E45D0 : Node, Object_000C60C0 {
    Object_000E45D0(Node *owner, int id, unsigned int flags, Init_000E45D0 *init);

    char unknown_048[0x1e4];
};

// One of the factories of the table at 0x215D68: the object gets an Object_000E5380 as its behaviour, the flags
// 0x400 and func_000E3720 as its event handler; then each placement of the description makes an Object_000E45D0 under
// it (first free id in [0x12B2, 0x13B2], flags 0x1100), chained after the previous one.
void func_000E4E10(Desc_000E5380 *desc, Params_000E5380 *params)
{
    Init_000E45D0 *entry = params->entries;
    Object_000C60C0 *previous = 0;
    Object_000E5380 *behaviour = new Object_000E5380;
    desc->behaviour = behaviour;
    behaviour->desc = desc;
    desc->flags = 0x400;
    desc->handler = func_000E3720;
    for (unsigned int i = 0; i < params->count; i++, entry++) {
        Object_000E45D0 *child =
            new Object_000E45D0(desc, data_0022FCE0->func_000128E0(0x12b2, 0x13b2), 0x1100, entry);
        child->func_000C6090(previous, desc, i);
        previous = child;
    }
}
