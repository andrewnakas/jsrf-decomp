struct Object_00099D50 {
    void func_00099D50(int index);
};

extern int (Object_00099D50::*data_0020E6AC[])();

// Runs the handler the table holds for the index. The handlers return 1, but this function passes no result
// on: its callers read none, and func_000A0870, which sits in one outer table (data_00215230) with
// dispatchers of this shape, ends in a call to a function without a result.
void Object_00099D50::func_00099D50(int index)
{
    (this->*data_0020E6AC[index])();
}
