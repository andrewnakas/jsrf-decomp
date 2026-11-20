/* sym: ?func_00011C90@Object_000EB440@@UAEXXZ = 0x000EB630 */
struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_0014C300(Vector3 *out, const Vector3 *a, const Vector3 *b);
void __fastcall func_0014C5C0(Vector3 *out, const Vector3 *in, float scale);

struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C90_5();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C90_9();
    virtual void func_00011C80_4(int argument);

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);

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
    char unknown_34[0x10];
};

Node *func_000C70A0(Node *owner, Vector3 *position, int kind);

struct Object_000C1270 {
    int func_000C1160(int kind, int count, Vector3 *position);
};

extern Object_000C1270 *data_00257CE4;

// The child of Node whose table is at 0x1CEED8.
struct Object_000EB440 : Node {
    virtual void func_00011C90();

    void func_000EB3C0();

    Vector3 start;
    Vector3 position;
    Vector3 velocity;
    float rise;
    int spin[3];
    int state;
    unsigned int timer;
    unsigned int count;
    char unknown_084[0x58];
    float speed;
};

// Slot 1. State 0: for 600 frames moves from the start at 0x44 by the velocity at 0x5c (its horizontal part scaled
// by the speed at 0xdc, the vertical one from 0x68, lowered by 1/18 down to -2.3148), slows the speed by 0.98 above
// 0.9259, updates the shape (func_000EB3C0) and spins the angles at 0x6c; then state 2. State 1: after 180 frames, a
// func_000C70A0 node and func_000C1160(0x2c, 6) of data_00257CE4 at the start, then state 2. State 2: removes itself
// and its children (func_00011BE0, func_00011C20).
void Object_000EB440::func_00011C90()
{
    switch (state) {
    case 0:
        if (++count < 600) {
            velocity.y = 0.0f;
            func_0014C5C0(&velocity, &velocity, speed);
            velocity.y = rise;
            func_0014C300(&position, &start, &velocity);
            if (rise > -2.3148148f) {
                rise -= 0.055555556f;
            }
            if (speed > 0.9259259f) {
                speed *= 0.98f;
            }
            func_000EB3C0();
            spin[0] += 600;
            spin[1] += 1200;
            spin[2] += 1800;
            return;
        }
        break;
    case 1:
        if (++timer <= 180) {
            return;
        }
        func_000C70A0(0, &start, 1);
        data_00257CE4->func_000C1160(0x2c, 6, &start);
        break;
    case 2:
        func_00011BE0(this);
        func_00011C20(child);
        return;
    default:
        return;
    }
    state = 2;
}
