struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000A1C50 {
    char unknown_000[0x9d8];
    int value_9d8;

    void func_0007FD20();
    void func_00089E00();
    int func_0008EAA0(int *result, Vector3 *target);
    int func_00091380(int *first, int *second);
    void func_000934C0();
    void func_000A0610(int flag);
};

// func_00089E00, func_00091380 and func_0008EAA0 (with no target) for their side effects, func_0007FD20, then
// func_000A0610(1) when the field at 0x9d8 is set.
void Object_000A1C50::func_000934C0()
{
    int first;
    int second;
    func_00089E00();
    func_00091380(&first, &second);
    int result = 0;
    func_0008EAA0(&result, 0);
    func_0007FD20();
    if (value_9d8) {
        func_000A0610(1);
    }
}
