struct Object_00098DB0 {
    int func_00098DB0(int index);
};

extern int (Object_00098DB0::*data_0020E5C4[])();

// Runs the handler the table holds for the index and returns its result (the handlers return 1).
int Object_00098DB0::func_00098DB0(int index)
{
    return (this->*data_0020E5C4[index])();
}
