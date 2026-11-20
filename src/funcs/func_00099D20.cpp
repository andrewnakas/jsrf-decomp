struct Object_00099D20 {
    void func_00099D20(int index);
};

extern int (Object_00099D20::*data_0020E64C[])();

// Runs the handler the table holds for the index. The handlers return 1, but this function passes no result
// on: its callers read none, and func_000A0870, which sits in one outer table (data_00215230) with
// dispatchers of this shape, ends in a call to a function without a result.
void Object_00099D20::func_00099D20(int index)
{
    (this->*data_0020E64C[index])();
}
