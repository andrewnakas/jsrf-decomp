struct Node {
    char unknown_00[0x28];
    Node *child;

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

struct Object_001118F0 {
    virtual ~Object_001118F0();
    virtual void func_00112110();

    char unknown_004[0x158];
    int state;

    void func_00111C10();
};

// Slot 1 of the table at 0x1D27C8: state 0 goes to 1 and steps func_00111C10, state 1 steps it, state 2 runs
// func_00011BE0 and func_00011C20 on the node.
void Object_001118F0::func_00112110()
{
    switch (state) {
    case 0:
        state = 1;
    case 1:
        func_00111C10();
        break;
    case 2:
        ((Node *)this)->func_00011BE0((Node *)this);
        ((Node *)this)->func_00011C20(((Node *)this)->child);
        break;
    }
}
