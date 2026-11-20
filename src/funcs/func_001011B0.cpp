void *__stdcall func_0006EBB0(unsigned int size);

// The Node child whose table is at 0x1D1D48 (constructor func_00100F40, which runs the handlers of
// data_0021FF98 by the state at 0x44).
struct Object_00101180 {
    char unknown_000[0x70];
    float value_70;
    float value_74;
    int value_78;
    char unknown_07c[0x10];
    void *block;
    char unknown_090[0x94];
    int value_124;

    void func_001011B0();
};

// Entry 0 of data_0021FF98: a 0x40-byte aligned block (func_0006EBB0) at 0x8c, -32 and 24 at 0x70 and 0x74,
// and 0 at 0x78 and 0x124.
void Object_00101180::func_001011B0()
{
    block = func_0006EBB0(0x40);
    value_70 = -32.0f;
    value_74 = 24.0f;
    value_78 = 0;
    value_124 = 0;
}
