struct Object_00091630 {
    void func_00091630(int index);
};

extern void (Object_00091630::*data_0020DB8C[])();

// Runs the handler the table holds for the index.
void Object_00091630::func_00091630(int index)
{
    (this->*data_0020DB8C[index])();
}
