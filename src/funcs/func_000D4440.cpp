struct Object_000D1700 {
    char unknown_000[8];
    int state;
    char unknown_00c[4];
    int timer;
    char unknown_014[0xf1c];
    int next;

    void func_000D38D0(int kind);
    void func_000D4440();
};

// A handler of the table at 0x216A38 (twice): func_000D38D0(3); after 120 calls, state 20 and 15 at 0xf30.
void Object_000D1700::func_000D4440()
{
    func_000D38D0(3);
    if (++timer > 120) {
        state = 0x14;
        next = 0xf;
    }
}
