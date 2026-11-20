struct Object_000A0890 {
    int func_000A0890(int index);
};

extern int (Object_000A0890::*data_00215280[])();

// Runs the handler the table holds for the index and returns its result (the handlers return 1).
int Object_000A0890::func_000A0890(int index)
{
    return (this->*data_00215280[index])();
}
