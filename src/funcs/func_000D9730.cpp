struct Owner_000D8A40 {
    char unknown_00[0x60];
    float step;
    char unknown_64[0x40];
    unsigned int flags;
};

struct Object_000D8A40 {
    char unknown_000[4];
    Owner_000D8A40 *owner;
    int state;
    char unknown_00c[0xc];
    float time;
    char unknown_01c[0xc4];
    int next;

    void func_000D9220();
    void func_000D9730();
};

// A handler of the table at 0x217378: clears the owner's flag 0x1000000 and advances the time by the owner's step;
// unless 0xe0 is 5, state 1, 0xe0 cleared and the owner's flag 0x8000 cleared; then func_000D9220.
void Object_000D8A40::func_000D9730()
{
    owner->flags &= ~0x1000000;
    time += owner->step;
    if (next != 5) {
        state = 1;
        next = 0;
        owner->flags &= ~0x8000;
    }
    func_000D9220();
}
