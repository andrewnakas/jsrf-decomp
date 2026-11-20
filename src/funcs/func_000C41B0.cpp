struct Object_000C41B0 {
    char unknown_00[8];
    int state;
    int count;

    void func_000C41B0();
};

extern void (Object_000C41B0::*data_0021615C[])();

// Runs the handler of the current state and counts the call.
void Object_000C41B0::func_000C41B0()
{
    (this->*data_0021615C[state])();
    count++;
}
