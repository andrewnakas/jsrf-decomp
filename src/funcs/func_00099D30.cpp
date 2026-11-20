struct Object_00099D30 {
    int func_00099D30(int index);
};

extern int (Object_00099D30::*data_0020E66C[])();

// Runs the handler the table holds for the index and returns its result (the handlers return 1).
int Object_00099D30::func_00099D30(int index)
{
    return (this->*data_0020E66C[index])();
}
