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

// Entry 12 of the member-function table at 0x2169e0: when 0x88 holds 1 or func_000D2190 passes for the point at 0x7c
// of data_00257CE4, the count at 0xeb8 becomes 1, 0xebc and 0xee0 0, state 13 and 9 at 0xf30, and the owner gets
// message 10 with its position (func_000C5B10); then func_000D34B0.
void Object_000D27F0::func_000D3EB0()
{
    if (held == 1 || func_000D2190(&data_00257CE4->unknown_7c, 0x222, 0x1555)) {
        count = 1;
        value_ebc = 0;
        value_ee0 = 0;
        state = 13;
        next = 9;
        owner->func_000C5B10(10, &owner->position);
    }
    func_000D34B0();
}
