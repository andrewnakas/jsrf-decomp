struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    void func_00060930(int id, int value);
};

struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);

    char unknown_00[0x28];
    Node *child;
};

int func_000DB260(Vector3 *position, Vector3 *direction);

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    int func_000C5B10(int message, void *data);

    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0x58];
    Vector3 *target;
};

// One route (0x18 bytes): its points at 0x14.
struct Route_000D9500 {
    char unknown_00[0x14];
    Vector3 *points;
};

struct Object_000D8A40 {
    char unknown_000[0x4];
    Object_000C5B50 *owner;
    int state;
    char unknown_00c[0x4];
    int ticks;
    char unknown_014[0x2c];
    Route_000D9500 *routes;
    int route;
    char unknown_048[8];
    int point;
    char unknown_054[0x44];
    int target;
    int value_9c;
    int pending;
    char unknown_0a4[0x3c];
    int next;
    char unknown_0e4[4];
    int mode;

    int func_000D8560();
    void func_000D89D0(Vector3 *position, Vector3 *direction);
    void func_000D9220();
    void func_000D9500();
};

// Entry 2 of the handler table at 0x217378: aims the owner at the current point of the current route and steers
// (func_000D8560); once it is on course in mode 2 (0xe8), state 3 (also at 0xe0), the count at 0x10 restarts, the
// node with the id at 0x98 unlinks itself and its children, a new trail (func_000DB260) starts at this object's
// position and direction with its id kept at 0x98, node 0xe8 gets func_00060930 with 0x9c, 0xa0 is set and the
// owner gets messages 0xc and 0x19. Then func_000D9220.
void Object_000D8A40::func_000D9500()
{
    owner->target = &routes[route].points[point];
    if (func_000D8560() && mode == 2) {
        Vector3 direction;
        Vector3 position;
        state = 3;
        next = 3;
        ticks = 0;
        func_000D89D0(&position, &direction);
        Node *old = (Node *)data_0022FCE0->func_000128C0(target);
        if (old) {
            old->func_00011BE0(old);
            old->func_00011C20(old->child);
        }
        target = func_000DB260(&position, &direction);
        Object_000607B0 *node = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (node) {
            node->func_00060930(value_9c, 1);
        }
        pending = 1;
        owner->func_000C5B10(0xc, &owner->position);
        owner->func_000C5B10(0x19, &position);
    }
    func_000D9220();
}
