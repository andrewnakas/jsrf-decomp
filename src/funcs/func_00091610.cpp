struct Object_00091610 {
    void func_00091610(int index);
};

extern void (Object_00091610::*data_0020DB4C[])();

// Runs the handler the table holds for the index.
void Object_00091610::func_00091610(int index)
{
    (this->*data_0020DB4C[index])();
}
