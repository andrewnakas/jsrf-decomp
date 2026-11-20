/* sym: ??0Object_000D01A0@@QAE@PAUNode@@HIPAUVector3@@@Z = 0x000D01A0 */
struct Vector3;

struct Game {
    int func_000128E0(int first, int last);
};

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();

    char unknown_04[0x40];
};

// The class whose table is at 0x1CE3B8 (destructor 0xCFA90, constructor 0xD01A0).
struct Object_000D01A0 : Node {
    Object_000D01A0(Node *owner, int id, unsigned int flags, Vector3 *position);

    char unknown_44[0x4c];
};

extern Game *data_0022FCE0;

// Takes a handle from the game's func_000128E0 (0x13b3, 0x15b3) and makes an Object_000D01A0 under `owner` with it
// (flags 0x800) at `position`. Returns the handle, or -1 when there is none.
int func_000D0530(Node *owner, Vector3 *position)
{
    int handle = data_0022FCE0->func_000128E0(0x13b3, 0x15b3);
    if (handle >= 0) {
        new Object_000D01A0(owner, handle, 0x800, position);
        return handle;
    }
    return -1;
}
