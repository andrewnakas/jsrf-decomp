struct Object_00099D50 {
    int func_00099D50(int index);
};

extern int (Object_00099D50::*data_0020E6AC[])();

// Runs the handler the table holds for the index and returns its result (the handlers return 1).
int Object_00099D50::func_00099D50(int index)
{
    return (this->*data_0020E6AC[index])();
}
