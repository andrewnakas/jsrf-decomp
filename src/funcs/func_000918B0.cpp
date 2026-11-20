struct Object_000918B0 {
    void func_000918B0(int index);
};

extern void (Object_000918B0::*data_0020DBBC[])();

// Runs the handler the table holds for the index.
void Object_000918B0::func_000918B0(int index)
{
    (this->*data_0020DBBC[index])();
}
