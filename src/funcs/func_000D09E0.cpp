/* sym: ??0Object_000D0680@@QAE@PAUNode@@HIH@Z = 0x000D0680 */
struct Game {
    int func_000128E0(int first, int last);
};

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();

    char unknown_04[0x40];
};

// The class whose table is at 0x1CE400 (destructor 0xD07A0).
struct Object_000D0680 : Node {
    Object_000D0680(Node *owner, int id, unsigned int flags, int value);

    char unknown_44[0x54];
};

extern Game *data_0022FCE0;

// Takes a handle from the game's func_000128E0 (0x13b3, 0x15b3) and, when there is one, makes an Object_000D0680
// under `owner` with it (flags 0x1000) and `value`. Returns the handle.
int func_000D09E0(Node *owner, int value)
{
    int handle = data_0022FCE0->func_000128E0(0x13b3, 0x15b3);
    if (handle >= 0) {
        new Object_000D0680(owner, handle, 0x1000, value);
    }
    return handle;
}
