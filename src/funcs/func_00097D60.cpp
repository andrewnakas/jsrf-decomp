struct Object_00097D60 {
    int func_00097D60(int index);
};

extern int (Object_00097D60::*data_0020E504[])();

// Runs the handler the table holds for the index and returns its result (the handlers return 1).
int Object_00097D60::func_00097D60(int index)
{
    return (this->*data_0020E504[index])();
}
