struct Object_000A08A0 {
    void func_000A08A0(int index);
};

extern int (Object_000A08A0::*data_002152A0[])();

// Runs the handler the table holds for the index. The handlers return 1, but this function passes no result
// on: its callers read none, and func_000A0870, which sits in one outer table (data_00215230) with
// dispatchers of this shape, ends in a call to a function without a result.
void Object_000A08A0::func_000A08A0(int index)
{
    (this->*data_002152A0[index])();
}
