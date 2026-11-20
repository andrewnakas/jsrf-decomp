/* sym: ??0Object_000F37B0@@QAE@PAUNode@@HIPBUVector3@@@Z = 0x000F37B0 */
struct Game {
    void *func_000128C0(int id);
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

struct Node;
struct Vector3;

// The child of Node whose table is at 0x1CF058 (0x11f0 bytes).
struct Object_000F37B0 {
    Object_000F37B0(Node *owner, int id, unsigned int flags, const Vector3 *position);

    char unknown_0000[0x11f0];
};

// Called by func_000F2420: takes a free id from 0x13b3 to 0x15b3 and creates an Object_000F37B0 under object 9 at
// the position (flags 0x1000). Gives the id, or -1 when there is none.
int func_000F3DA0(const Vector3 *position)
{
    Node *owner = (Node *)data_0022FCE0->func_000128C0(9);
    int id = data_0022FCE0->func_000128E0(0x13b3, 0x15b3);
    if (id >= 0) {
        new Object_000F37B0(owner, id, 0x1000, position);
        return id;
    }
    return -1;
}
