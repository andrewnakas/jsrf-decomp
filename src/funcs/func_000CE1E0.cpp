struct Object_000C5B50 {
    char unknown_00[0xa4];
    unsigned int flags;
};

struct Object_000CE220 {
    int unknown_00;
    Object_000C5B50 *owner;
    int state;
    char unknown_0c[4];
    int count;
    char unknown_14[0x80];
    int value_94;

    void func_000CE1E0();
};

// Counts up at 0x10; past 120: state 15, the field at 0x94 = 11, the owner at 4 loses flag 0x4000000 and
// the count restarts.
void Object_000CE220::func_000CE1E0()
{
    if (++count > 120) {
        state = 15;
        value_94 = 11;
        owner->flags &= ~0x4000000;
        count = 0;
    }
}
