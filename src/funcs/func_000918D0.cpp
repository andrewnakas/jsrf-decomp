struct Object_000918D0 {
    void func_000918D0(int index);
};

extern void (Object_000918D0::*data_0020DBFC[])();

// Runs the handler the table holds for the index.
void Object_000918D0::func_000918D0(int index)
{
    (this->*data_0020DBFC[index])();
}
