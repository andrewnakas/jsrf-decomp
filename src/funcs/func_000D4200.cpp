struct Owner_000D1700 {
    char unknown_00[0x60];
    float step;
    char unknown_64[0x40];
    unsigned int flags;
};

struct Object_000D1700 {
    char unknown_000[4];
    Owner_000D1700 *owner;
    int state;
    char unknown_00c[4];
    int timer;
    char unknown_014[4];
    float time;
    char unknown_01c[0x68];
    int value_84;
    char unknown_088[0xea8];
    int next;

    void func_000D34B0();
    void func_000D4200();
};

// A handler of the table at 0x216A08: clears the owner's flag 0x1000000 and advances the time by the owner's step;
// unless 0xf30 is 14, state 1, +0x84 cleared, the timer at 60 and the owner's flag 0x8000 cleared; then
// func_000D34B0.
void Object_000D1700::func_000D4200()
{
    owner->flags &= ~0x1000000;
    time += owner->step;
    if (next != 0xe) {
        state = 1;
        value_84 = 0;
        timer = 0x3c;
        owner->flags &= ~0x8000;
    }
    func_000D34B0();
}
