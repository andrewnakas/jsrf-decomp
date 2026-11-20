struct Object_00097D30 {
    int func_00097D30(int index);
};

extern int (Object_00097D30::*data_0020E4A4[])();

// Runs the handler the table holds for the index and returns its result (the handlers return 1).
int Object_00097D30::func_00097D30(int index)
{
    return (this->*data_0020E4A4[index])();
}
