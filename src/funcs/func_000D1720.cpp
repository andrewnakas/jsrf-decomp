struct Object_000D27F0 {
    char unknown_00[8];
    int state;
    char unknown_0c[0x74];
    int toggle;

    void func_000D1720();
};

// A handler of the member-function table at 0x216a08, next to the merged func_000D1700 (whose class it
// shares): state 1, and the field at 0x80 toggles between 14 and 18.
void Object_000D27F0::func_000D1720()
{
    state = 1;
    toggle = (toggle == 14) ? 18 : 14;
}
