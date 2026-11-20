/* sym: ??0Object_000CFA90@@QAE@PAUNode@@HIH@Z = 0x000D01A0 */
struct Game {
    int func_000128E0(int first, int last);
};

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();

    char unknown_04[0x40];
};

// The class whose table is at 0x1CE3B8 (destructor 0xCFA90, constructor 0xD01A0).
struct Object_000CFA90 : Node {
    Object_000CFA90(Node *owner, int id, unsigned int flags, int value);

    char unknown_44[0x4c];
};

extern Game *data_0022FCE0;

// Takes a handle from the game's func_000128E0 (0x13b3, 0x15b3) and makes an Object_000CFA90 under `owner` with it
// (flags 0x800) and `value`. Returns the handle, or -1 when there is none.
int func_000D0530(Node *owner, int value)
{
    int handle = data_0022FCE0->func_000128E0(0x13b3, 0x15b3);
    if (handle >= 0) {
        new Object_000CFA90(owner, handle, 0x800, value);
        return handle;
    }
    return -1;
}
