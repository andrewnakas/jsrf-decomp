struct Object_000A0860 {
    int func_000A0860(int index);
};

extern int (Object_000A0860::*data_00215240[])();

// Runs the handler the table holds for the index and returns its result (the handlers return 1).
int Object_000A0860::func_000A0860(int index)
{
    return (this->*data_00215240[index])();
}
