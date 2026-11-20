struct Game {
    void func_000127C0(int index, int value);
    int func_000127E0(int index);
    void *func_000128C0(int index);
};

extern Game *data_0022FCE0;

struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);

    char unknown_00[0x28];
    Node *child;
};

struct Object_0004EF90 : Node {
    void func_0004F970();
};

// A state handler (table 0x1FA008, slot 20): when object 2 does not exist, takes this node out (func_00011BE0) and
// passes its child to func_00011C20.
void Object_0004EF90::func_0004F970()
{
    if (data_0022FCE0->func_000128C0(2) == 0 && this != 0) {
        func_00011BE0(this);
        func_00011C20(child);
    }
}
