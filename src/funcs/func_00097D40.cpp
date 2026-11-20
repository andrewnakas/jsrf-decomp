struct Object_00097D40 {
    int func_00097D40(int index);
};

extern int (Object_00097D40::*data_0020E4C4[])();

// Runs the handler the table holds for the index and returns its result (the handlers return 1).
int Object_00097D40::func_00097D40(int index)
{
    return (this->*data_0020E4C4[index])();
}
