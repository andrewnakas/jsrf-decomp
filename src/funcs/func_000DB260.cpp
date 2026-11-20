/* sym: ??0Object_000DB0F0@@QAE@PAUNode@@HI@Z = 0x000DAC90 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

struct Node;

struct Object_000DADE0 {
    void func_000DADE0(Vector3 *position, Vector3 *direction) throw();
};

// The child of Node whose table is at 0x1CE6F8 (0x97c bytes; constructor func_000DAC90, destructor func_000DAD60).
struct Object_000DB0F0 {
    Object_000DB0F0(Node *owner, int id, unsigned int flags);

    char unknown_000[0x97c];
};

// Takes a free id in 0x13b3..0x15b3 (func_000128E0) and builds an Object_000DB0F0 with it under object 9, started at
// `position` and `direction` (func_000DADE0); returns the id, or -1 when none is free. Called by func_000D9500.
int func_000DB260(Vector3 *position, Vector3 *direction)
{
    Node *owner = (Node *)data_0022FCE0->func_000128C0(9);
    int id = data_0022FCE0->func_000128E0(0x13b3, 0x15b3);
    if (id >= 0) {
        Object_000DB0F0 *trail = new Object_000DB0F0(owner, id, 0);
        if (trail) {
            ((Object_000DADE0 *)trail)->func_000DADE0(position, direction);
        }
        return id;
    }
    return -1;
}
