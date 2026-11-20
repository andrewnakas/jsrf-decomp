void func_00025740(unsigned int index, int argument);

struct Object_0007C250 {
    char unknown_00[0x48];
    int state;

    void func_0007C140();
};

// State handler 9 of the table at 0x20D2B8: runs action 0x16 and goes to state 10.
void Object_0007C250::func_0007C140()
{
    func_00025740(0x16, 1);
    state = 10;
}
