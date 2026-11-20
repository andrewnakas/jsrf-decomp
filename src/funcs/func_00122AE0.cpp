struct Object_00070530 {
    void func_00070960(int index);
};

struct Object_00120420 {
    char unknown_0000[0x1084];
    int level;

    int func_00127070();
    void func_00122AE0();
};

// Moves the level at +0x1084 up (to at most 7) or down (to at least 1) by the sign of func_00127070, calling
// func_00070960 with 1 on each change.
void Object_00120420::func_00122AE0()
{
    if (func_00127070() > 0 && level < 7) {
        level++;
        ((Object_00070530 *)this)->func_00070960(1);
    }
    if (func_00127070() < 0 && level > 1) {
        level--;
        ((Object_00070530 *)this)->func_00070960(1);
    }
}
