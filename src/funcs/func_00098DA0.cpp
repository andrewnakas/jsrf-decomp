struct Object_00098DA0 {
    int func_00098DA0(int index);
};

extern int (Object_00098DA0::*data_0020E5A4[])();

// Runs the handler the table holds for the index and returns its result (the handlers return 1).
int Object_00098DA0::func_00098DA0(int index)
{
    return (this->*data_0020E5A4[index])();
}
