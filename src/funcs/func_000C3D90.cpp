struct Object_000C3D90 {
    char unknown_00[8];
    int state;

    void func_000C3D90();
};

extern void (Object_000C3D90::*data_00216148[])();

// Runs the handler of the current state.
void Object_000C3D90::func_000C3D90()
{
    (this->*data_00216148[state])();
}
