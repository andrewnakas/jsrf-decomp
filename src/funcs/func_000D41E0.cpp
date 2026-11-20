struct Object_000D1700 {
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
    void func_000D41E0();
};

// A handler of the same table (entry 18): in phase 2 at 0xf38, state 1 and the fields at 0xf30 and 0x10 cleared;
// then func_000D34B0.
void Object_000D1700::func_000D41E0()
{
    if (phase == 2) {
        state = 1;
        next = 0;
        timer = 0;
    }
    func_000D34B0();
}
