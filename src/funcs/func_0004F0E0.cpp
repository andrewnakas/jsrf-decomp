struct Game {
    void func_000127C0(int index, int value);
    int func_000127E0(int index);
    void *func_000128C0(int index);
};

extern Game *data_0022FCE0;

void func_00025740(unsigned int index, int argument);

struct Object_0004D8C0 {
    void func_0004DAA0();
};

extern Object_0004D8C0 data_001FA05C;

struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);

    char unknown_00[0x28];
    Node *child;
};

struct Object_0004EF90 : Node {
    char unknown_2c[0x18];
    int next;

    void func_0004F0E0();
};

// A state handler (table 0x1FA008, slot 7): with object 9, goes to state 4 once object 10 exists too; without it, by
// game value 4: -1 takes this node out (as slot 20), 0x60 sends 0 to handlers 0x19 and 0x1a, runs func_0004DAA0 and
// goes to state 8, anything else goes to state 2.
void Object_0004EF90::func_0004F0E0()
{
    void *stage = data_0022FCE0->func_000128C0(9);
    void *other = data_0022FCE0->func_000128C0(10);
    if (stage) {
        if (other) {
            next = 4;
        }
        return;
    }
    int value = data_0022FCE0->func_000127E0(4);
    if (value == -1) {
        if (this) {
            func_00011BE0(this);
            func_00011C20(child);
        }
    } else if (value == 0x60) {
        func_00025740(0x19, 0);
        func_00025740(0x1a, 0);
        data_001FA05C.func_0004DAA0();
        next = 8;
    } else {
        next = 2;
    }
}
