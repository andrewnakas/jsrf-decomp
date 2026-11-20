// The player object: func_000A07C0 runs this from the table at 0x215230 with its own `this`, beside the
// player member func_000A0870.
struct Object_000A1C50 {
    void func_000A0890(int index);
};

extern int (Object_000A1C50::*data_00215280[])();

// Runs the handler the table holds for the index. The handlers return 1, but this function passes no result
// on: its callers read none, and func_000A0870, which sits in one outer table (data_00215230) with
// dispatchers of this shape, ends in a call to a function without a result.
void Object_000A1C50::func_000A0890(int index)
{
    (this->*data_00215280[index])();
}
