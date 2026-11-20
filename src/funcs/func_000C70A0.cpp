/* sym: ??0Object_000C6C40@@QAE@PAUNode@@HIPAUVector3@@@Z = 0x000C6C40 */
/* sym: ??0Object_000C6D60@@QAE@PAUNode@@HIPAUVector3@@@Z = 0x000C6D60 */
/* sym: ??0Object_000C6E70@@QAE@PAUNode@@HIPAUVector3@@@Z = 0x000C6E70 */
/* sym: ??0Object_000C6F90@@QAE@PAUNode@@HIPAUVector3@@@Z = 0x000C6F90 */
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

// The base of the four children below (their tables 0x1CE0B8 to 0x1CE178).
struct Object_000C6BF0 : Node {
    virtual ~Object_000C6BF0();

    char unknown_44[0x2c];
};

struct Object_000C6C40 : Object_000C6BF0 {
    Object_000C6C40(Node *owner, int id, unsigned int flags, Vector3 *position);
};

struct Object_000C6D60 : Object_000C6BF0 {
    Object_000C6D60(Node *owner, int id, unsigned int flags, Vector3 *position);
};

struct Object_000C6E70 : Object_000C6BF0 {
    Object_000C6E70(Node *owner, int id, unsigned int flags, Vector3 *position);
};

struct Object_000C6F90 : Object_000C6BF0 {
    Object_000C6F90(Node *owner, int id, unsigned int flags, Vector3 *position);
};

// Makes one of the four Object_000C6BF0 children (0x70 bytes, by kind 0 to 3) at the position, under the owner or
// else under node 9 (nothing for other kinds). No caller uses a result, so it returns nothing.
void func_000C70A0(Node *owner, Vector3 *position, int kind)
{
    if (!owner) {
        owner = (Node *)data_0022FCE0->func_000128C0(9);
    }
    switch (kind) {
    case 0:
        new Object_000C6C40(owner, -1, 0, position);
        return;
    case 1:
        new Object_000C6D60(owner, -1, 0, position);
        return;
    case 2:
        new Object_000C6E70(owner, -1, 0, position);
        return;
    case 3:
        new Object_000C6F90(owner, -1, 0, position);
        return;
    }
}
