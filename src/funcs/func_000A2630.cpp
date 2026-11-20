struct Object_000A2630 {
    int func_000A2630(int index);
};

extern int (Object_000A2630::*data_00215344[])();

// Runs the handler the table holds for the index and returns its result (the handlers return 1).
int Object_000A2630::func_000A2630(int index)
{
    return (this->*data_00215344[index])();
}
