struct Object_0007C250 {
    char unknown_00[0x48];
    int state;

    void func_0007CE70();
};

// State handler (table at 0x20D2B8): goes to state 42.
void Object_0007C250::func_0007CE70()
{
    state = 42;
}
