struct Node {
    Node *func_00011BD0();
};

struct Parent_0007F570 {
    char unknown_000[0x8ac];
    int unknown_8ac;
    char unknown_8b0[4];
    unsigned int state;
};

struct Object_0007F540 : Node {
    int func_0007F540();
};

// Says whether the node's parent (func_00011BD0) is in state 3, 4 or 5 with its word at +0x8ac set (not -1).
int Object_0007F540::func_0007F540()
{
    Parent_0007F570 *parent = (Parent_0007F570 *)func_00011BD0();
    if (parent->state >= 3 && parent->state <= 5 && parent->unknown_8ac != -1) {
        return 1;
    }
    return 0;
}
