struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000DADE0 {
    void func_000DADE0(Vector3 *position, Vector3 *direction);
};

struct Object_000607B0 {
    void func_00060930(int id, int value);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000D8A40 {
    char unknown_000[0x8];
    int state;
    char unknown_00c[0x4];
    int ticks;
    char unknown_014[0x84];
    int target;
    int value_9c;
    int pending;
    char unknown_0a4[0x3c];
    int next;

    void func_000D89D0(Vector3 *position, Vector3 *direction);
    void func_000D9220();
    void func_000D9610();
};

// A handler of the table at 0x217378: while the node with the id at 0x98 lives, gives it this object's position
// and direction (func_000D89D0, func_000DADE0) and goes on (func_000D9220). Once it is gone: if 0xa0 is set, hands
// the value at 0x9c to node 0xe8 (func_00060930) and clears it; counts a frame at 0x10 and, once it is above 0, moves
// to state 4 (also at 0xe0); forgets the id and goes on.
void Object_000D8A40::func_000D9610()
{
    Vector3 direction;
    Vector3 position;
    Object_000DADE0 *found = (Object_000DADE0 *)data_0022FCE0->func_000128C0(target);
    if (found) {
        func_000D89D0(&position, &direction);
        found->func_000DADE0(&position, &direction);
        func_000D9220();
        return;
    }
    if (pending) {
        Object_000607B0 *node = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (node) {
            node->func_00060930(value_9c, 0);
        }
        pending = 0;
    }
    if (++ticks > 0) {
        state = 4;
        next = 4;
        ticks = 0;
    }
    target = -1;
    func_000D9220();
}
