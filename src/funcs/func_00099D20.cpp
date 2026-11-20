struct Object_00099D20 {
    int func_00099D20(int index);
};

extern int (Object_00099D20::*data_0020E64C[])();

// Runs the handler the table holds for the index and returns its result (the handlers return 1).
int Object_00099D20::func_00099D20(int index)
{
    return (this->*data_0020E64C[index])();
}
