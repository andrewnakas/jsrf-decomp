/* sym: ??0Object_000F44E0@@QAE@PAUNode@@HIPBUVector3@@PAU2@@Z = 0x000F3E60 */
struct Node;

struct Game {
    void *func_000128C0(int id);
    int func_000128E0(int first, int last);
};

struct Vector3 {
    float x;
    float y;
    float z;
};

// The child of Node whose table is at 0x1CF098 (destructor func_000F3F70): it starts at the position and moves along
// the direction, which its constructor flattens (y = 0) before normalising a copy.
struct Object_000F44E0 {
    Object_000F44E0(Node *owner, int id, unsigned int flags, const Vector3 *position, Vector3 *direction);

    char unknown_000[0x10c];
};

extern Game *data_0022FCE0;

// Creates an Object_000F44E0 under object 9 with a new id from func_000128E0(0x13b3, 0x15b3), when there is one.
void func_000F43D0(const Vector3 *position, Vector3 *direction)
{
    Node *stage = (Node *)data_0022FCE0->func_000128C0(9);
    int id = data_0022FCE0->func_000128E0(0x13b3, 0x15b3);
    if (id >= 0) {
        new Object_000F44E0(stage, id, 0x100, position, direction);
    }
}
