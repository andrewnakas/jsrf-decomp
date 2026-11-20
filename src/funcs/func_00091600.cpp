struct Object_00091600 {
    void func_00091600(int index);
};

extern void (Object_00091600::*data_0020DB2C[])();

// Runs the handler the table holds for the index.
void Object_00091600::func_00091600(int index)
{
    (this->*data_0020DB2C[index])();
}
