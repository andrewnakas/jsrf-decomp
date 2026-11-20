/* sym: ??0Object_000C4850@@QAE@PAUNode@@HIPAUVector3@@1H@Z = 0x000C4850 */
struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Node {
    virtual ~Node();

    char unknown_04[0x3c];
};

// The child of Node with the table at 0x1CDE20 (0xc0 bytes).
struct Object_000C4850 : Node {
    Object_000C4850(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *direction, int angle);

    char unknown_40[0x80];
};

// For kind 0, creates an Object_000C4850 at the position, thrown along the direction at the angle, under object 9
// (id -1, flags 0x100).
void func_000C4BE0(int kind, Vector3 *position, Vector3 *direction, int angle)
{
    Node *stage = (Node *)data_0022FCE0->func_000128C0(9);
    if (kind == 0) {
        new Object_000C4850(stage, -1, 0x100, position, direction, angle);
    }
}
