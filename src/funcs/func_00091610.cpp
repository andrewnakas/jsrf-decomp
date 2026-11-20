// The player object: func_00091580 runs this from the table at 0x20DB1C with its own `this`.
struct Object_000A1C50 {
    void func_00091610(int index);
};

extern void (Object_000A1C50::*data_0020DB4C[])();

// Runs the handler the table holds for the index.
void Object_000A1C50::func_00091610(int index)
{
    (this->*data_0020DB4C[index])();
}
