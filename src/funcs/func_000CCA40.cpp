// One of the owner's items (the list at 0xd0, linked at 0x74).
struct Item_000CCA40 {
    char unknown_00[0x4c];
    unsigned int flags;
    char unknown_50[0x24];
    Item_000CCA40 *next;
};

// The owner at 0x4. The objects of this family call func_000C5B50 (and func_000C59A0, func_000C5B10, ...) with
// this taken from 0x4, so the owner is that function's class.
struct Object_000C5B50 {
    char unknown_00[0x5c];
    float value_5c;
    char unknown_60[0x44];
    unsigned int flags;
    char unknown_a8[0x28];
    Item_000CCA40 *items;

    void func_000C5B50(int *handle);
};

struct Limits_000CC020 {
    char unknown_00[4];
    float limit;
    char unknown_08[8];
    float rate;
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

    int func_000CC040();

    Object_000C5B50 *owner;
    int state;
    int unknown_0c;
    int count;
    char unknown_14[0x1c];
    Limits_000CC020 *limits;
};

/* const: 0x40000 */
// Slot 15: unless the owner has flag 0x20, it gets that flag when every item has flag 0x40000; its 0x5c grows by
// twice the rate at 0x10 of the object at 0x30, up to twice the limit at 4; when func_000CC040 fails, flag 0x20 and
// 0x5c cleared.
void Object_000CCE00::func_000CCA40()
{
    Item_000CCA40 *item = owner->items;
    if (!(owner->flags & 0x20)) {
        while (item) {
            if (!(item->flags & 0x40000)) {
                break;
            }
            item = item->next;
        }
        if (!item) {
            owner->flags |= 0x20;
        }
        if (limits->limit * 2 > owner->value_5c) {
            owner->value_5c += limits->rate * 2;
            if (owner->value_5c > limits->limit * 2) {
                owner->value_5c = limits->limit * 2;
            }
        }
        if (!func_000CC040()) {
            owner->flags |= 0x20;
            owner->value_5c = 0.0f;
        }
    }
}
