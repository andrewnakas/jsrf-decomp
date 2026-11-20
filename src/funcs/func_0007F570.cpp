struct Node {
    Node *func_00011BD0();
};

struct Parent_0007F570 {
    char unknown_000[0x8b4];
    unsigned int state;
};

struct Object_0007F570 : Node {
    int func_0007F570();
};

// Says whether the node's parent (func_00011BD0) is in state 4.
int Object_0007F570::func_0007F570()
{
    return ((Parent_0007F570 *)func_00011BD0())->state == 4;
}
