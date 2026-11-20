struct Object_000A2640 {
    int func_000A2640(int index);
};

extern int (Object_000A2640::*data_00215364[])();

// Runs the handler the table holds for the index and returns its result (the handlers return 1).
int Object_000A2640::func_000A2640(int index)
{
    return (this->*data_00215364[index])();
}
