struct Node {
    virtual ~Node();

    unsigned int flags;
    char unknown_08[0x3c];
};

struct Object_000C60C0;

// The object the factories of the table at 0x215D68 serve (func_000C0B30 makes it): a Node whose chain of links
// starts at 0xd0.
struct Desc_000E5380 : Node {
    char unknown_44[0x8c];
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

// Slot 0: keeps the index and the object it serves, and puts the link after the previous one (or first in the
// object's chain at 0xd0).
void Object_000C60C0::func_000C6090(Object_000C60C0 *previous, Desc_000E5380 *owner, int index)
{
    this->index = index;
    this->owner = owner;
    next = 0;
    this->previous = previous;
    if (previous) {
        previous->next = this;
    } else {
        owner->first = this;
    }
}
