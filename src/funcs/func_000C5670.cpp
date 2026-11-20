/* sym: ??0Object_000C51D0@@QAE@PAUNode@@HIPAUVector3@@1@Z = 0x000C51D0 */
/* sym: ??0Object_000C52E0@@QAE@PAUNode@@HIPAUVector3@@1@Z = 0x000C52E0 */
/* sym: ??0Object_000C5490@@QAE@PAUNode@@HIPAUVector3@@1@Z = 0x000C53D0 */
/* sym: ??0Object_000C5500@@QAE@PAUNode@@HIPAUVector3@@1@Z = 0x000C5500 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Node {
    virtual ~Node();

    char unknown_04[0x40];
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The shot (table 0x1CDE60, 0x100 bytes with its children's fields).
struct Object_000C4CF0 : Node {
    virtual ~Object_000C4CF0();

    char unknown_044[0xbc];
};

struct Object_000C51D0 : Object_000C4CF0 {
    Object_000C51D0(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *direction);
};

struct Object_000C52E0 : Object_000C4CF0 {
    Object_000C52E0(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *direction);
};

struct Object_000C5490 : Object_000C4CF0 {
    Object_000C5490(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *direction);
};

struct Object_000C5500 : Object_000C4CF0 {
    Object_000C5500(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *direction);
};

// Fires one of the four Object_000C4CF0 shots (by kind 0 to 3: func_000C51D0, func_000C52E0, func_000C53D0,
// func_000C5500) from the position along the direction, under the parent or else under node 9.
void func_000C5670(void *parent, Vector3 *position, Vector3 *direction, int kind)
{
    Node *owner = (Node *)parent;
    if (!owner) {
        owner = (Node *)data_0022FCE0->func_000128C0(9);
    }
    switch (kind) {
    case 0:
        new Object_000C51D0(owner, -1, 0, position, direction);
        return;
    case 1:
        new Object_000C52E0(owner, -1, 0, position, direction);
        return;
    case 2:
        new Object_000C5490(owner, -1, 0, position, direction);
        return;
    case 3:
        new Object_000C5500(owner, -1, 0, position, direction);
        return;
    }
}
