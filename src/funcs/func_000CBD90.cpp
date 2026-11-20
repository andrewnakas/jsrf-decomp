struct Vector3 {
    float x;
    float y;
    float z;
};

// One of the owner's items (the list at 0xd0, linked at 0x74).
struct Item_000CBD90 {
    char unknown_00[0x34];
    char point[0x18];
    unsigned int flags;
    char unknown_50[0x24];
    Item_000CBD90 *next;
};

// The object in data_00257CE8; func_00157F10 is the engine's (it returns 0).
struct Object_00157F10 {
    int func_00157F10(void *point, int value);
};

extern Object_00157F10 *data_00257CE8;

// The owner at 0x4. The objects of this family call func_000C5B50 (and func_000C59A0, func_000C5B10, ...) with
// this taken from 0x4, so the owner is that function's class.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0x54];
    unsigned int flags;
    char unknown_a8[0x28];
    Item_000CBD90 *items;

    int func_000C59A0();
    int func_000C5B10(int first, int second);
};

struct Limits_000CC020 {
    char unknown_00[0x38];
    int value_38;
};

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600();
};

// The class whose table is at 0x1CE320 (constructor func_000CC620, destructor func_000CC680).
struct Object_000CCE00 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual ~Object_000CCE00();
    virtual void func_000CBCD0();
    virtual void func_000CBD90();
    virtual void func_000CBE60();
    virtual void func_000CBF20();
    virtual void func_000CC910();
    virtual void func_000CD060();
    virtual void func_000CD140();
    virtual void func_000CD1A0();
    virtual void func_000CBF90();
    virtual void func_000CBFC0();
    virtual void func_000CCA40();
    virtual void func_000CC020();

    Object_000C5B50 *owner;
    int state;
    int unknown_0c;
    int count;
    char unknown_14[0x1c];
    Limits_000CC020 *limits;
};

// Slot 6: with the owner's flag 0x100, waits while func_00157F10 of data_00257CE8 holds any item's point at 0x34,
// then clears flag 0x100 on the owner and its items; then, when the owner's test passes (func_000C59A0), clears
// flag 1 on the owner and its items, moves to state 2 and gives the owner 8 for its position (func_000C5B10).
void Object_000CCE00::func_000CBD90()
{
    Item_000CBD90 *item;
    if (owner->flags & 0x100) {
        for (item = owner->items; item; item = item->next) {
            if (data_00257CE8->func_00157F10(item->point, limits->value_38)) {
                return;
            }
        }
        owner->flags &= ~0x100;
        for (item = owner->items; item; item = item->next) {
            item->flags &= ~0x100;
        }
    }
    if (owner->func_000C59A0()) {
        Object_000C5B50 *o = owner;
        item = o->items;
        o->flags &= ~1;
        for (; item; item = item->next) {
            item->flags &= ~1;
        }
        state = 2;
        owner->func_000C5B10(8, (int)&owner->position);
    }
}
