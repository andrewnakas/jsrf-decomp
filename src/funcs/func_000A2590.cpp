struct Object_000A1C50 {
    void func_00089E00();
    void func_0008D280();
    void func_0008E5A0();
    int func_00090640(int *result);
    int func_00091380(int *first, int *second);
    void func_000A2590();
};

extern int (Object_000A1C50::*data_002152C4[])(int first, int second);
extern void (Object_000A1C50::*data_002152F4[])(int result);

// func_0008E5A0, func_0008D280 and func_00089E00; then func_00091380 picks a handler of data_002152C4 and
// func_00090640 one of data_002152F4. The first runs when it exists, and the second, when it exists, if the
// first is missing or returns 0.
void Object_000A1C50::func_000A2590()
{
    int first;
    int second;
    func_0008E5A0();
    func_0008D280();
    func_00089E00();
    int index = func_00091380(&first, &second);
    int result = 0;
    int kind = func_00090640(&result);
    if (!data_002152C4[index] || !(this->*data_002152C4[index])(first, second)) {
        if (data_002152F4[kind]) {
            (this->*data_002152F4[kind])(result);
        }
    }
}
