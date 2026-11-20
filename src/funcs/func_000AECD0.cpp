/* sym: ?func_00011C90_1@Object_000AE970@@UAEXXZ = 0x000AECD0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BAA00();
void func_001BAA50();
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB330(int angle);
float __fastcall func_0014C6B0(const Vector3 *vector);
int func_000BA800(int bank, int kind, int sound, void *position, int handle);

// One of the motions touching the node (0x180), linked through 0x38: its state at 0, its velocity at 8 and a
// direction at 0x2c.
struct Motion_000AECD0 {
    int state;
    int unknown_04;
    Vector3 velocity;
    char unknown_14[0x18];
    float dx;
    float unknown_30;
    float dz;
    Motion_000AECD0 *next;
};

struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();

    unsigned int flags;
    int id;
    unsigned int mask;
    float depth;
    int sortKey;
    char unknown_18[0xc];
    Node *parent;
    Node *child;
    Node *previous;
    Node *next;
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD770).
struct Object_000AE970 : Node {
    virtual void func_00011C90_1();

    int unknown_40;
    unsigned int state;
    char unknown_048[0x70];
    int touched;
    int value_bc;
    int bank;
    char unknown_0c4[0x18];
    Vector3 position;
    int angles[3];
    char unknown_0f4[0x24];
    float side;
    char unknown_11c[0x50];
    unsigned int mode;
    char unknown_170[0x10];
    Motion_000AECD0 *motion;
};

// Slot 2. In mode 1 a touched node looks for a settled motion (state 0 or 1) faster than 0.1: it keeps on which side
// of the node (turned by the angle at 0xec) the motion runs at 0x118, sets state bit 0x40000000 (clearing 0x30000000),
// moves to mode 2 and plays sound 0x16 (func_000BA800) at its position. In modes 2 and 3 with no settled motion it
// clears bits 0x70000000, moves to mode 4 and plays the sound; with one it sets bit 0x40000000 and, unless that bit
// was set already, moves to mode 2 once the motion is faster than 0.01. The touch words at 0xb8 and 0xbc are cleared.
void Object_000AE970::func_00011C90_1()
{
    Vector3 axis;
    axis.x = 1.0f;
    axis.y = 0.0f;
    axis.z = 0.0f;
    Motion_000AECD0 *motion;
    switch (mode) {
    case 1:
        if (touched && this->motion) {
            for (motion = this->motion; motion; motion = motion->next) {
                if ((motion->state == 0 || motion->state == 1) && func_0014C6B0(&motion->velocity) > 0.1f) {
                    func_001BAA00();
                    func_001BB330(angles[1]);
                    func_001BAB20(&axis, &axis);
                    if (axis.z * motion->dx - axis.x * motion->dz < 0.0f) {
                        side = -1.0f;
                    } else {
                        side = 1.0f;
                    }
                    func_001BAA50();
                    mode = 2;
                    state = state & 0xcfffffff | 0x40000000;
                    func_000BA800(bank, 0, 0x16, &position, -1);
                    break;
                }
            }
        }
        break;
    case 2:
    case 3:
        for (motion = this->motion; motion; motion = motion->next) {
            if (motion->state == 0 || motion->state == 1) {
                break;
            }
        }
        if (!motion) {
            mode = 4;
            state &= 0x8fffffff;
            func_000BA800(bank, 0, 0x16, &position, -1);
        } else {
            float speed = func_0014C6B0(&motion->velocity);
            if (!(state & 0x40000000) && speed > 0.01f) {
                mode = 2;
            }
            state |= 0x40000000;
        }
        break;
    }
    touched = 0;
    value_bc = 0;
}
