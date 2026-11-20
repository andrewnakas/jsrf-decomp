float func_0014C870(float value, float limit);

struct Node {
    virtual ~Node();

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

struct Object_000A1C50 : Node {
    char unknown_040[0xdc];
    int value_11c;
    char unknown_120[0x8ec];
    int value_a0c;
    char unknown_a10[0x74];
    int value_a84;
    char unknown_a88[0x7c];
    int value_b04;
    char unknown_b08[0x88];
    float ratio;
    char unknown_b94[4];
    int value_b98;
    char unknown_b9c[0xc];
    int value_ba8;
    char unknown_bac[8];
    int value_bb4;
    float speed;
    int value_bbc;
    char unknown_bc0[0x114];
    int value_cd4;
    char unknown_cd8[0x178];
    int value_e50;
    char unknown_e54[4];
    int state;
    char unknown_e5c[0x2c4];
    int value_1120;

    void func_0007EB10();
    void func_00098910();
    void func_00098970();
    void func_000A1CF0();
    void func_000A2370();
    void func_000992D0(int keep, int first, int second, float speed);
};

// Sets state 3 (unless it is 9), takes the size of the value at 0x1120 in 16384ths (at most 1) as the ratio at 0xb90,
// sets 0x11c to 9 and, as asked, copies 0xcd4 to 0xbb4, calls func_0007EB10 and func_000A2370; keeps `speed` (at most
// 25/18) at 0xbb8 and ends with func_00098970, func_000A1CF0 and 0xe50 = 5.
void Object_000A1C50::func_000992D0(int keep, int first, int second, float speed)
{
    if (state != 9) {
        state = 3;
    }
    int value = value_1120;
    if (value < 0) {
        ratio = value * -(1.0f / 16384.0f);
    } else {
        ratio = value * (1.0f / 16384.0f);
    }
    ratio = func_0014C870(ratio, 1.0f);
    func_00098910();
    value_bbc = 0;
    value_11c = 9;
    if (keep) {
        value_b98 = 0;
        value_bb4 = value_cd4;
    }
    if (first) {
        func_0007EB10();
    }
    if (second) {
        func_000A2370();
    }
    this->speed = speed;
    if (speed > 1.3888888f) {
        this->speed = 1.3888888f;
    }
    value_ba8 = value_a84;
    func_00098970();
    value_b04 = 0;
    func_000A1CF0();
    value_a0c = 0;
    value_e50 = 5;
}
