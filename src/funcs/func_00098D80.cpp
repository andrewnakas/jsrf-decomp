struct Object_00098D80 {
    int func_00098D80(int index);
};

extern int (Object_00098D80::*data_0020E564[])();

// Runs the handler the table holds for the index and returns its result (the handlers return 1).
int Object_00098D80::func_00098D80(int index)
{
    return (this->*data_0020E564[index])();
}
