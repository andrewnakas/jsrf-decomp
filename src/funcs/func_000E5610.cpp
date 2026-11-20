struct Owner_000E5650 {
    char unknown_00[0xa4];
    unsigned int flags;
};

struct Object_000E5650 {
    int unknown_00;
    Owner_000E5650 *owner;
    int state;
    char unknown_0c[4];
    int count;
    char unknown_14[0x1c];
    int value_30;
    int value_34;

    void func_000E5610();
};

// Counts up at 0x10; past 240: clears 0x34 and the count, state 11, the field at 0x30 = 8, and the owner at 4
// loses the flags 0x1010000.
void Object_000E5650::func_000E5610()
{
    if (++count > 240) {
        value_34 = 0;
        count = 0;
        state = 11;
        value_30 = 8;
        owner->flags &= ~0x1010000;
    }
}
