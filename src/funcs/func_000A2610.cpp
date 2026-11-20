struct Object_000A2610 {
    int func_000A2610(int index);
};

extern int (Object_000A2610::*data_00215304[])();

// Runs the handler the table holds for the index and returns its result (the handlers return 1).
int Object_000A2610::func_000A2610(int index)
{
    return (this->*data_00215304[index])();
}
