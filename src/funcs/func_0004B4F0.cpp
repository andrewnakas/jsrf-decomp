void func_00060C90();

struct Object_0004ABA0 {
    char unknown_00[0x5c];
    int state;

    void func_0004B4F0();
};

// State handler (table at 0x1F9888): calls func_00060C90 and goes to state 0x31.
void Object_0004ABA0::func_0004B4F0()
{
    func_00060C90();
    state = 0x31;
}
