struct Node {
    Node *func_00011BD0();
};

struct Parent_0007F570 {
    char unknown_000[0x8b4];
    unsigned int state;
};

struct Object_0007FC90 : Node {
    char unknown_0000[0xfa0];
    int unknown_fa0;

    int func_0007FC90(int value);
};

// 1 while the parent (func_00011BD0) is in state 4; otherwise whether the word at +0xfa0 has reached a value.
int Object_0007FC90::func_0007FC90(int value)
{
    if (((Parent_0007F570 *)func_00011BD0())->state == 4) {
        return 1;
    }
    return unknown_fa0 >= value;
}
