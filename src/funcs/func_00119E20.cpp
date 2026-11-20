struct Object_00070530 {
    int func_00070550(int first, int second, int mode);
};

struct Node {
    Node *func_00011BD0();
};

struct Object_00119C00 {
    char unknown_00[0x48];
    int first;
    int second;
    int value;

    void func_00119E20();
};

int func_00119540(int group, int index, void *position);

// Unless a value is set at +0x50: replaces the word at +0x4c by func_00070550 of the object func_00011BD0
// returns, in mode 2, and calls func_00119540 for entry 3 of group 8.
void Object_00119C00::func_00119E20()
{
    if (!value) {
        Object_00070530 *owner = (Object_00070530 *)((Node *)this)->func_00011BD0();
        second = owner->func_00070550(first, second, 2);
        func_00119540(8, 3, 0);
    }
}
