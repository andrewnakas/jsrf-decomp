struct Object_00098D90 {
    void func_00098D90(int index);
};

extern int (Object_00098D90::*data_0020E584[])();

// Runs the handler the table holds for the index. The handlers return 1, but this function passes no result
// on: its callers read none, and func_000A0870, which sits in one outer table (data_00215230) with
// dispatchers of this shape, ends in a call to a function without a result.
void Object_00098D90::func_00098D90(int index)
{
    (this->*data_0020E584[index])();
}
