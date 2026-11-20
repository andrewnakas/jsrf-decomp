struct Node {
    Node *func_00011BD0();
};

struct Parent_0007F570 {
    char unknown_000[0x8b4];
    unsigned int state;
};

struct Object_0007F520 : Node {
    int func_0007F520();
};

// Says whether the node's parent (func_00011BD0) is in state 3, 4 or 5.
int Object_0007F520::func_0007F520()
{
    unsigned int state = ((Parent_0007F570 *)func_00011BD0())->state;
    if (state >= 3 && state <= 5) {
        return 1;
    }
    return 0;
}
