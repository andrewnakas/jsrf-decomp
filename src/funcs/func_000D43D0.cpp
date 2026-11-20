struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 unknown_7c;
};

extern Object_000C1270 *data_00257CE4;

void func_000C6950(void *place, float *scale);

struct Node {
    char unknown_00[0x28];
    Node *child;

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

// The object the handlers serve (at 0x4), a Node.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0xc];
    float speed;
    float climb;
    char unknown_64[0x40];
    unsigned int flags;

    int func_000C5B10(int message, void *data);
};

// A point of the path at 0x34 (24 bytes).
struct Point_000D1700 {
    char unknown_00[0x18];
};

// The class (constructor func_000D27F0) whose slot 0 runs the member-function table at 0x2169e0; these are its
// handlers.
struct Object_000D27F0 {
    char unknown_000[4];
    Object_000C5B50 *owner;
    int state;
    char unknown_00c[4];
    int timer;
    char unknown_014[4];
    float y;
    char unknown_01c[0x18];
    Point_000D1700 *path;
    int index;
    char unknown_03c[4];
    float scale[11];
    int placed;
    char unknown_070[4];
    unsigned int toggle;
    float shown;
    float glow;
    char unknown_080[8];
    int held;
    char unknown_08c[0xe2c];
    unsigned int count;
    int value_ebc;
    char unknown_ec0[0x20];
    int value_ee0;
    char unknown_ee4[0x4c];
    int next;
    char unknown_f34[4];
    int phase;

    int func_000D2120(Point_000D1700 *point, int range);
    int func_000D2190(Vector3 *position, int range, int angle);
    void func_000D34B0();
    void func_000D38D0(int kind);
    void func_000D1750();
    void func_000D3B30();
    void func_000D3EB0();
    void func_000D43D0();
};

// Entry 25 of the member-function table at 0x2169e0: climbs by the owner's 0x60 and runs func_000D38D0(3); when the
// owner lacks the flag 0x80: state 0x1a, 0xf30 = 0x15, 0x88 cleared, the owner gains the flag 0x8000 and stops, the
// timer restarts, and the first time func_000C6950 places the owner's position with the scale at 0x40.
void Object_000D27F0::func_000D43D0()
{
    y += owner->climb;
    func_000D38D0(3);
    if (!(owner->flags & 0x80)) {
        state = 0x1a;
        next = 0x15;
        held = 0;
        owner->flags |= 0x8000;
        owner->speed = 0.0f;
        timer = 0;
        if (placed == 0) {
            func_000C6950(&owner->position, scale);
            placed = 1;
        }
    }
}
