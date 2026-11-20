struct Object_00101190 {
    char unknown_00[0x44];
    int state;

    void func_00101190();
};

extern void (Object_00101190::*data_0021FFA8[])();

// Runs the handler of the current state.
void Object_00101190::func_00101190()
{
    (this->*data_0021FFA8[state])();
}
