struct Object_001011A0 {
    char unknown_00[0x44];
    int state;

    void func_001011A0(int event);
};

extern void (Object_001011A0::*data_0021FFB0[])(int event);

// Passes an event to the handler of the current state (func_00101A70 switches on the value).
void Object_001011A0::func_001011A0(int event)
{
    (this->*data_0021FFB0[state])(event);
}
