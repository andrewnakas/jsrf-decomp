struct Object_0004ABA0 {
    char unknown_0000[0x5c];
    int state;

    void func_0004B5F0();
};

void func_00024620(unsigned int color, float step);

// State handler (table at 0x1F9888): starts a fade and goes to state 0x3b.
void Object_0004ABA0::func_0004B5F0()
{
    func_00024620(0xff000000, 1.0f / 60.0f);
    state = 0x3b;
}
