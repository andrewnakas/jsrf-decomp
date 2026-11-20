struct Object_000A1C50 {
    void func_00089E00();
    void func_0008D280();
    void func_0008E5A0();
    int func_0008FE10(int *result);
    int func_00091380(int *first, int *second);
    void func_00097CB0();
};

extern int (Object_000A1C50::*data_0020E464[])(int first, int second);
extern void (Object_000A1C50::*data_0020E494[])(int result);

// func_0008E5A0, func_0008D280 and func_00089E00; then func_00091380 picks a handler of data_0020E464 and
// func_0008FE10 one of data_0020E494. The first runs when it exists, and the second, when it exists, if the
// first is missing or returns 0.
void Object_000A1C50::func_00097CB0()
{
    int first;
    int second;
    func_0008E5A0();
    func_0008D280();
    func_00089E00();
    int index = func_00091380(&first, &second);
    int result = 0;
    int kind = func_0008FE10(&result);
    if (!data_0020E464[index] || !(this->*data_0020E464[index])(first, second)) {
        if (data_0020E494[kind]) {
            (this->*data_0020E494[kind])(result);
        }
    }
}
