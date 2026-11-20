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
    void func_000D41B0();
};

// A handler of the same table (entry 17): the same with func_000D38D0(3).
void Object_000D1700::func_000D41B0()
{
    func_000D38D0(3);
    if (count <= 1) {
        state = 18;
        next = 13;
    }
    func_000D34B0();
}
