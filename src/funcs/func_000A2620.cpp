struct Object_000A2620 {
    int func_000A2620(int index);
};

extern int (Object_000A2620::*data_00215324[])();

// Runs the handler the table holds for the index and returns its result (the handlers return 1).
int Object_000A2620::func_000A2620(int index)
{
    return (this->*data_00215324[index])();
}
