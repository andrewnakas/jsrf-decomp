struct Object_00091620 {
    void func_00091620(int index);
};

extern void (Object_00091620::*data_0020DB6C[])();

// Runs the handler the table holds for the index.
void Object_00091620::func_00091620(int index)
{
    (this->*data_0020DB6C[index])();
}
