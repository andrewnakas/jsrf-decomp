struct Object_0004ABA0 {
    char unknown_00[0x5c];
    int state;

    void func_0004D880();
    void func_00053AF0();
};

// State handler (table at 0x1F9888): calls func_0004D880 and goes to state 100.
void Object_0004ABA0::func_00053AF0()
{
    func_0004D880();
    state = 100;
}
