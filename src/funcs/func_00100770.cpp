struct Object_00100770 {
    char unknown_00[0x60];
    int mode;

    void func_00100770();
};

extern void (Object_00100770::*data_0021FF88[])();

// Runs the handler of the current mode.
void Object_00100770::func_00100770()
{
    (this->*data_0021FF88[mode])();
}
