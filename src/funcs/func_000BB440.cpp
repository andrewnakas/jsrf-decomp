/* sym: ??0Object_000BAE00@@QAE@PAUNode@@HIHH@Z = 0x000BB270 */
struct Game {
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

struct Node {
    virtual ~Node();

    char unknown_04[0x3c];
};

// The child of Node whose table is at 0x1CDA20 (0xa4 bytes, destructor func_000BAE00).
struct Object_000BAE00 : Node {
    Object_000BAE00(Node *owner, int id, unsigned int flags, int first, int second);

    char unknown_40[0x64];
};

// The node func_000585E0 asks for an Object_000BAE00.
struct Object_000BB440 : Node {
    int func_000BB440(int first, int second);
};

// Makes an Object_000BAE00 under this node with a free id from 0xec to 0x10ec, flags 0 and both values; returns
// the id.
int Object_000BB440::func_000BB440(int first, int second)
{
    int id = data_0022FCE0->func_000128E0(0xec, 0x10ec);
    new Object_000BAE00(this, id, 0, first, second);
    return id;
}
