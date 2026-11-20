// The player object: func_00098CF0, which calls func_00091380 with its own `this`, runs this from the table at
// 0x20E554 with it.
struct Object_000A1C50 {
    void func_00098D80(int index);
};

extern int (Object_000A1C50::*data_0020E564[])();

// Runs the handler the table holds for the index. The handlers return 1, but this function passes no result
// on: its callers read none, and func_000A0870, which sits in one outer table (data_00215230) with
// dispatchers of this shape, ends in a call to a function without a result.
void Object_000A1C50::func_00098D80(int index)
{
    (this->*data_0020E564[index])();
}
