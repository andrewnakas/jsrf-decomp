struct Object_00070850 {
    int func_00070550(int first, int second, int mode);
};

struct Node {
    Node *func_00011BD0();
};

struct Object_001197F0 {
    char unknown_00[0x48];
    int first;
    int second;
    int value;

    void func_00119DA0();
};

int func_00119540(int group, int index, void *position);

// Unless a value is set at +0x50: replaces the word at +0x4c by func_00070550 of the object func_00011BD0
// returns, in mode 0, and calls func_00119540 for entry 8 of group 8.
void Object_001197F0::func_00119DA0()
{
    if (!value) {
        Object_00070850 *owner = (Object_00070850 *)((Node *)this)->func_00011BD0();
        second = owner->func_00070550(first, second, 0);
        func_00119540(8, 8, 0);
    }
}
