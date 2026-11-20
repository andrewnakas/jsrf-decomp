struct Object_00097D50 {
    int func_00097D50(int index);
};

extern int (Object_00097D50::*data_0020E4E4[])();

// Runs the handler the table holds for the index and returns its result (the handlers return 1).
int Object_00097D50::func_00097D50(int index)
{
    return (this->*data_0020E4E4[index])();
}
