// The player object: func_00091830 runs this from the table at 0x20DBAC with its own `this`.
struct Object_000A1C50 {
    void func_000918D0(int index);
};

extern void (Object_000A1C50::*data_0020DBFC[])();

// Runs the handler the table holds for the index.
void Object_000A1C50::func_000918D0(int index)
{
    (this->*data_0020DBFC[index])();
}
