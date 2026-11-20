/* sym: ??0Object_00079B50@@QAE@PAUNode@@HIH@Z = 0x0007A8B0 */
/* const: 0x10003 */
struct Node;

struct Game {
    void func_00012730(int value);
};

extern Game *data_0022FCE0;

// The class whose table is at 0x1CCDE8 (destructor 0x79B50; 0x144 bytes).
struct Object_00079B50 {
    Object_00079B50(Node *owner, int id, unsigned int flags, int value);

    char unknown_000[0x144];
};

// Creates object 0x1167 (the class at 0x1CCDE8) under an owner and runs the game's func_00012730(1).
void func_00078080(void *owner)
{
    new Object_00079B50((Node *)owner, 0x1167, 0x10003, 1);
    data_0022FCE0->func_00012730(1);
}
