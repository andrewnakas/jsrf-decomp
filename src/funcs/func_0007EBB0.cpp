struct Node {
    Node *func_00011BD0();
};

struct Parent_0007EBB0 {
    char unknown_000[0x8dc];
    int unknown_8dc;
};

struct Object_0007EBB0 : Node {
    int func_0007EBB0();
};

// Returns the field at +0x8dc of the node's parent (func_00011BD0).
int Object_0007EBB0::func_0007EBB0()
{
    return ((Parent_0007EBB0 *)func_00011BD0())->unknown_8dc;
}
