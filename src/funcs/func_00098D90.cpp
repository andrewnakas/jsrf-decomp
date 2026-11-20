struct Object_00098D90 {
    int func_00098D90(int index);
};

extern int (Object_00098D90::*data_0020E584[])();

// Runs the handler the table holds for the index and returns its result (the handlers return 1).
int Object_00098D90::func_00098D90(int index)
{
    return (this->*data_0020E584[index])();
}
