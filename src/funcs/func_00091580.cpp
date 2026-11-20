struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000A1C50 {
    void func_0007FD20();
    void func_00089E00();
    int func_0008EAA0(int *result, Vector3 *target);
    int func_00091380(int *first, int *second);
    void func_00091580();
};

extern int (Object_000A1C50::*data_00257C04[])(int first, int second);
extern void (Object_000A1C50::*data_0020DB1C[])(int result);

// func_00089E00, then func_00091380 picks a handler of data_00257C04 and func_0008EAA0 (with no target) one of
// the table at 0x20DB1C; after func_0007FD20 the first runs when it exists, and the second when the first is
// missing or returns 0.
void Object_000A1C50::func_00091580()
{
    int first;
    int second;
    func_00089E00();
    int index = func_00091380(&first, &second);
    int result = 0;
    int kind = func_0008EAA0(&result, 0);
    func_0007FD20();
    if (!data_00257C04[index] || !(this->*data_00257C04[index])(first, second)) {
        (this->*data_0020DB1C[kind])(result);
    }
}
