struct Owner_000CE1A0 {
    char unknown_00[0xa4];
    unsigned int flags;
};

struct Object_000CE220 {
    int unknown_00;
    Owner_000CE1A0 *owner;
    int state;
    char unknown_0c[4];
    int count;
    char unknown_14[0x80];
    int value_94;

    void func_000CE1A0();
};

// Counts up at 0x10; past 120: state 16, the field at 0x94 = 12, the owner at 4 loses flag 0x4000000 and
// the count restarts.
void Object_000CE220::func_000CE1A0()
{
    if (++count > 120) {
        state = 16;
        value_94 = 12;
        owner->flags &= ~0x4000000;
        count = 0;
    }
}
