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
    char unknown_120[0x8b8];
    int ready;
    char unknown_9dc[0x1b8];
    int waiting;
    int value_b98;
    unsigned int phase;
    unsigned int ticks;
    int value_ba4;
    char unknown_ba8[0x10];
    float speed;
    char unknown_bbc[0x104];
    int value_cc0;
    char unknown_cc4[0x3ec];
    int count;

    void func_0008E5A0();
    void func_00089E00();
    int func_00091380(int *first, int *second);
    void func_000992D0(int keep, int first, int second, float speed);
    int func_0009C690(int value);
    void func_00099590();
};

// Steps the player (func_0008E5A0, func_00089E00, func_00091380, func_0009C690 (0)), then by the phase at 0xb9c:
// 0 waits for 0x9d8 (state 0x79, phase 1); 1 counts 0xba0 down to 0, or below 174 when 0xb94 is clear (state 0x7a,
// phase 2); 2 waits for 0x9d8 again, copies 0xba4 to 0xcc0 and calls func_000992D0 with the speed at 0xbb8 plus 25/27.
void Object_000A1C50::func_00099590()
{
    func_0008E5A0();
    func_00089E00();
    int first;
    int second;
    func_00091380(&second, &first);
    func_0009C690(0);
    switch (phase) {
    case 0:
        if (ready) {
            value_11c = 0x79;
            phase = 1;
        }
        break;
    case 1:
        if (--ticks == 0 || !waiting && ticks < 174.0) {
            value_11c = 0x7a;
            phase = 2;
        }
        break;
    case 2:
        if (ready) {
            value_cc0 = value_ba4;
            value_b98 = 1;
            func_000992D0(0, 0, 0, speed + 0.9259259f);
            count++;
        }
        break;
    }
}
