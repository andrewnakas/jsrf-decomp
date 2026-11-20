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
    void func_000D3DB0();
};

// A handler of the member-function table at 0x2169e0 (entry 7): in phase 2 at 0xf38, state 1, 0 at 0x84 and the
// timer at 0x10 set to 60; then func_000D34B0.
void Object_000D27F0::func_000D3DB0()
{
    if (phase == 2) {
        state = 1;
        value_84 = 0;
        timer = 60;
    }
    func_000D34B0();
}
