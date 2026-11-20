// What the item at 0x12c holds.
struct Sound_000DC1F0 {
    char unknown_00[0xc];
    int kind;
    char unknown_10[0x4c];
    unsigned int count;
};

struct Item_00016200 {
    Sound_000DC1F0 *sound;
};

struct Object_00016200 {
    void func_00016240(Item_00016200 *item);
    void func_0001D940(void **reference);
};

extern Object_00016200 data_0022FCE8;

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0xa4];
    unsigned int flags;
};

// The class whose table is at 0x1CE780 (constructor func_000DB8F0).
struct Object_000DB8F0 {
    char unknown_000[4];
    Object_000C5B50 *owner;
    int state;
    char unknown_00c[0x60];
    unsigned int value_06c;
    char unknown_070[0x28];
    int value_098;
    char unknown_09c[0x24];
    void **handle_0c0;
    char unknown_0c4[0x68];
    Item_00016200 item_12c;

    void func_000DC1F0();
};

// Clears the owner's flag 0x1000000 and sets it again when the sound of the item at 0x12c is of kind 0x2c (then,
// with more than one at 0x6c, state 4 and a set 0x98 becomes 3); then hands the handle at 0xc0 and the item to
// data_0022FCE8 (func_0001D940, func_00016240). Called by slot 8 (func_000DC490).
void Object_000DB8F0::func_000DC1F0()
{
    int *kind = &item_12c.sound->kind;
    owner->flags &= ~0x1000000;
    for (unsigned int i = 0; i < item_12c.sound->count; i++) {
        if (*kind == 0x2c) {
            owner->flags |= 0x1000000;
            if (value_06c > 1) {
                state = 4;
                if (value_098) {
                    value_098 = 3;
                }
            }
            break;
        }
    }
    data_0022FCE8.func_0001D940(handle_0c0);
    data_0022FCE8.func_00016240(&item_12c);
}
