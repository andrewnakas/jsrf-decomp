struct Game {
    void func_000127C0(int index, int value);
};

extern Game *data_0022FCE0;

struct Info_00047080;

// The memory-unit manager at 0x1F97A8.
struct Object_00047110 {
    int func_000470C0(Info_00047080 *info);
    int func_00046E10();
};

extern Object_00047110 data_001F97A8;

// Called by 0x7BE30. Game value 0x1b2 tells the result: 1 when func_000470C0 finds nothing, 2 when func_00046E10
// fails; then 0. Otherwise the value stays 0 and the answer is 1.
int func_0006F1B0()
{
    data_0022FCE0->func_000127C0(0x1b2, 0);
    if (data_001F97A8.func_000470C0(0) == 0) {
        data_0022FCE0->func_000127C0(0x1b2, 1);
        return 0;
    }
    if (data_001F97A8.func_00046E10() < 0) {
        data_0022FCE0->func_000127C0(0x1b2, 2);
        return 0;
    }
    return 1;
}
