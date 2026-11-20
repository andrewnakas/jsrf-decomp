struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Object 0x12b1.
struct Object_000C0690 {
    void func_000C0690(int amount);
};

struct Node {
    virtual ~Node();

    unsigned int flags;
    char unknown_08[0x3c];
};

struct Object_000C60C0;

// The object the factories of the table at 0x215D68 serve (func_000C0B30 makes it): a Node whose chain of links
// starts at 0xd0 and counts its links at 0x98.
struct Desc_000E5380 : Node {
    char unknown_44[0x54];
    int count;
    char unknown_9c[8];
    unsigned int flags_a4;
    char unknown_a8[0x28];
    Object_000C60C0 *first;
};

// The link of a chain (the second base, at 0x44, of the objects the factories build; table 0x1CE1B8): its index at
// 0x50, the object it serves at 0x6c and its neighbours at 0x70 and 0x74.
struct Object_000C60C0 {
    virtual void func_000C6090(Object_000C60C0 *previous, Desc_000E5380 *owner, int index);
    virtual void func_000C60C0();

    char unknown_04[0x4c];
    int index;
    char unknown_54[0x18];
    Desc_000E5380 *owner;
    Object_000C60C0 *previous;
    Object_000C60C0 *next;
};

// Slot 1: takes the link out of the chain (or the object's first at 0xd0), adds 1 to object 0x12b1 (func_000C0690)
// and counts the object's links down; at 0 the object gets flags 0x2020 at 0xa4.
void Object_000C60C0::func_000C60C0()
{
    if (previous) {
        previous->next = next;
        if (next) {
            next->previous = previous;
        }
    } else {
        owner->first = next;
        if (next) {
            next->previous = 0;
        }
    }
    Object_000C0690 *total = (Object_000C0690 *)data_0022FCE0->func_000128C0(0x12b1);
    if (total) {
        total->func_000C0690(1);
    }
    owner->count--;
    if (owner->count <= 0) {
        owner->flags_a4 |= 0x2020;
        owner->count = 0;
    }
}
