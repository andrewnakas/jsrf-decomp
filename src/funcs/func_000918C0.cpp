struct Object_000918C0 {
    void func_000918C0(int index);
};

extern void (Object_000918C0::*data_0020DBDC[])();

// Runs the handler the table holds for the index.
void Object_000918C0::func_000918C0(int index)
{
    (this->*data_0020DBDC[index])();
}
