/* sym: ??0Object_000C4510@@QAE@PAUNode@@HIH@Z = 0x000C4510 */
struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Node {
    virtual ~Node();

    char unknown_04[0x3c];
};

// The child of Node with the table at 0x1CDDE0 (0xa8 bytes).
struct Object_000C4510 : Node {
    Object_000C4510(Node *owner, int id, unsigned int flags, int kind);

    char unknown_40[0x68];
};

// Creates an Object_000C4510 of the kind under object 9 (id -1, flags 0x100).
void func_000C4B70(int kind)
{
    Node *stage = (Node *)data_0022FCE0->func_000128C0(9);
    new Object_000C4510(stage, -1, 0x100, kind);
}
