struct Vector3 {
    float x;
    float y;
    float z;
};

struct Params_00092E70 {
    int value_00;
};

struct Object_000A1C50 {
    char unknown_000[0x2a0];
    Params_00092E70 *params;
    char unknown_2a4[0x734];
    int value_9d8;
    char unknown_9dc[0x290];
    float value_c6c;
    char unknown_c70[0x1b0];
    int value_e20;
    char unknown_e24[0x2c];
    int state_e50;

    void func_0007FD20();
    void func_00089E00();
    int func_0008EAA0(int *result, Vector3 *target);
    int func_00091380(int *first, int *second);
    void func_00093240();
    void func_000A0DA0();
};

// Like func_000934C0 up to func_0007FD20. Then, when the field at 0x9d8 is set, the first value of the
// parameters at 0x2a0 goes to 0xe20 and the state at 0xe50 becomes 0x12; otherwise the value at 0xc6c drops by
// 1/90 (not below 0) and func_000A0DA0 runs.
void Object_000A1C50::func_00093240()
{
    int first;
    int second;
    func_00089E00();
    func_00091380(&first, &second);
    int result = 0;
    func_0008EAA0(&result, 0);
    func_0007FD20();
    if (value_9d8) {
        value_e20 = params->value_00;
        state_e50 = 0x12;
        return;
    }
    value_c6c -= 0.011111111f;
    if (value_c6c < 0.0f) {
        value_c6c = 0.0f;
    }
    func_000A0DA0();
}
