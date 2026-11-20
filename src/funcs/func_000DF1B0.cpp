struct Owner_000DCBC0 {
    char unknown_00[0x60];
    float climb;
    char unknown_64[0x40];
    unsigned int flags;
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000DCBC0 {
    char unknown_000[0x4];
    Owner_000DCBC0 *owner;
    int state;
    char unknown_00c[0x8];
    Vector3 position;
    char unknown_020[0x1a0];
    int next;

    void func_000DE6C0();
    void func_000DF1B0();
};

// A handler of the table at 0x217A20: lifts the position at 0x14 by the owner's climb; unless 0x1c0 is 16, goes to
// state 2 with 0 at 0x1c0 and clears the owner's flags 0x8000, 0x200000 and 0x8000000; then func_000DE6C0.
void Object_000DCBC0::func_000DF1B0()
{
    Owner_000DCBC0 *current = owner;
    position.y += current->climb;
    if (next != 16) {
        state = 2;
        next = 0;
        current->flags &= ~0x8208000;
    }
    func_000DE6C0();
}
