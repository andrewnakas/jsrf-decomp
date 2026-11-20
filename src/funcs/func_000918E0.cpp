struct Object_000918E0 {
    void func_000918E0(int index);
};

extern void (Object_000918E0::*data_0020DC1C[])();

// Runs the handler the table holds for the index.
void Object_000918E0::func_000918E0(int index)
{
    (this->*data_0020DC1C[index])();
}
