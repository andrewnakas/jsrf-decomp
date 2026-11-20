struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000A1C50 {
    unsigned int func_0007FCC0();
    void func_00089E00();
    void func_0008D040();
    void func_0008D280();
    void func_0008E5A0();
    int func_0008EAA0(int *result, Vector3 *target);
    int func_00091380(int *first, int *second);
    void func_00092ED0();
    void func_000A07C0();
};

extern int (Object_000A1C50::*data_00215200[])(int first, int second);
extern void (Object_000A1C50::*data_00215230[])(int result);

// func_0008E5A0, func_0008D280, func_00089E00 and func_0008D040; then func_00091380 picks a handler of
// data_00215200 and func_0008EAA0 (with no target) one of data_00215230. With three or more of the words
// func_0007FCC0 counts set, func_00092ED0 runs instead of them; otherwise the first runs when it exists, and the
// second, when it exists, if the first is missing or returns 0.
void Object_000A1C50::func_000A07C0()
{
    int first;
    int second;
    func_0008E5A0();
    func_0008D280();
    func_00089E00();
    func_0008D040();
    int index = func_00091380(&first, &second);
    int result = 0;
    int kind = func_0008EAA0(&result, 0);
    if (func_0007FCC0() >= 3) {
        func_00092ED0();
        return;
    }
    if (!data_00215200[index] || !(this->*data_00215200[index])(first, second)) {
        if (data_00215230[kind]) {
            (this->*data_00215230[kind])(result);
        }
    }
}
