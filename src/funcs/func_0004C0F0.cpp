struct Object_0004ABA0 {
    char unknown_0000[0x5c];
    int state;

    void func_0004C0F0();
};

void func_00024620(unsigned int color, float step);
void func_00078080(void *owner);

// State handler (table at 0x1F9888): starts a fade, calls func_00078080 and goes to state 0x6a.
void Object_0004ABA0::func_0004C0F0()
{
    func_00024620(0xff000000, 1.0f / 60.0f);
    func_00078080(this);
    state = 0x6a;
}
