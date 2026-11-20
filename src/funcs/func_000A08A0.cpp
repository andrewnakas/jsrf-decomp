struct Object_000A08A0 {
    int func_000A08A0(int index);
};

extern int (Object_000A08A0::*data_002152A0[])();

// Runs the handler the table holds for the index and returns its result (the handlers return 1).
int Object_000A08A0::func_000A08A0(int index)
{
    return (this->*data_002152A0[index])();
}
