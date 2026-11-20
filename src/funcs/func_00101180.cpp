struct Object_00101180 {
    char unknown_00[0x44];
    int state;

    void func_00101180();
};

extern void (Object_00101180::*data_0021FFA0[])();

// Runs the handler of the current state.
void Object_00101180::func_00101180()
{
    (this->*data_0021FFA0[state])();
}
