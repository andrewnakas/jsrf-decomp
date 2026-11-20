/* sym: ??0Object_000DA3E0@@QAE@PAUNode@@HIPAUVector3@@1@Z = 0x000DA1E0 */
struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Vector3;

struct Node;

// The child of Node whose table is at 0x1CE658 (0x6c4 bytes; constructor func_000DA1E0).
struct Object_000DA3E0 {
    Object_000DA3E0(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *target);

    char unknown_000[0x6c4];
};

// Builds an Object_000DA3E0 under object 9 (id -1, flags 0) with the two vectors it is given; called by
// func_000DB0F0.
void func_000DA670(Vector3 *position, Vector3 *target)
{
    Node *owner = (Node *)data_0022FCE0->func_000128C0(9);
    new Object_000DA3E0(owner, -1, 0, position, target);
}
