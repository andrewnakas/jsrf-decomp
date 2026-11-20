struct Object_000D27F0 {
    char unknown_000[8];
    int state;
    char unknown_00c[4];
    int timer;
    char unknown_014[0x70];
    int value_84;
    char unknown_088[4];
    int limit;
    char unknown_090[0xe28];
    unsigned int count;
    char unknown_ebc[0x74];
    int next;
    char unknown_f34[4];
    int phase;

    void func_000D34B0();
    void func_000D38D0(int kind);
    void func_000D4150();
};

// A handler of the same table (entry 15): counts the timer at 0x10 up; past the limit at 0x8c, state 16 and 12 at
// 0xf30; then func_000D34B0.
void Object_000D27F0::func_000D4150()
{
    if (++timer > limit) {
        state = 16;
        next = 12;
    }
    func_000D34B0();
}
