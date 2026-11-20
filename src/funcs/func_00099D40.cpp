struct Object_00099D40 {
    int func_00099D40(int index);
};

extern int (Object_00099D40::*data_0020E68C[])();

// Runs the handler the table holds for the index and returns its result (the handlers return 1).
int Object_00099D40::func_00099D40(int index)
{
    return (this->*data_0020E68C[index])();
}
