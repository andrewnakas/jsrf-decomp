struct Object_000D1700 {
    char unknown_000[8];
    int state;
    char unknown_00c[4];
    int timer;
    char unknown_014[0xf1c];
    int next;

    void func_000D38D0(int kind);
    void func_000D43A0();
};

// A handler (0x216A40): func_000D38D0(3), then counts up the timer at 0x10; past 120, state 0x13 and 0xe at
// 0xf30.
void Object_000D1700::func_000D43A0()
{
    func_000D38D0(3);
    if (++timer > 120) {
        state = 0x13;
        next = 0xe;
    }
}
