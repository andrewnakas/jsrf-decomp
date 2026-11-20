struct Object_00098DB0 {
    void func_00098DB0(int index);
};

extern int (Object_00098DB0::*data_0020E5C4[])();

// Runs the handler the table holds for the index. The handlers return 1, but this function passes no result
// on: its callers read none, and func_000A0870, which sits in one outer table (data_00215230) with
// dispatchers of this shape, ends in a call to a function without a result.
void Object_00098DB0::func_00098DB0(int index)
{
    (this->*data_0020E5C4[index])();
}
