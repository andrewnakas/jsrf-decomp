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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};

struct Vector3 {
    float x;
    float y;
    float z;
};

unsigned int func_0014C690(float value);

// The child of Node whose table is at 0x1D1D48 (constructor func_00100F40, destructor func_00101100); data_0021FF98
// holds the handlers of its states.
struct Object_00101180 : Node {
    void func_001011E0();
    void func_00101410();

    int unknown_040;
    int state;
    int mode;
    unsigned int counter;
    unsigned int flags_50;
    int pending;
    char unknown_058[0x3c];
    Vector3 position;
    int angles[3];
    char unknown_0ac[0xc];
    Vector3 shown;
    char unknown_0c4[0xc];
    Vector3 velocity;
    char unknown_0dc[0x40];
    float fall;
    float alpha;
};

// Entry 3 of data_0021FF98, by the mode at 0x48: 0 starts mode 1, which after 39 frames sets bit 31 at 0x50, takes the
// player's place (func_001011E0) and moves to mode 3; 3 moves by the velocity (y falling by 0.1 to at most the speed
// at 0x11c), turns by 5 times the z and -5 times the x velocity (as func_0014C690 gives them) and shows the position
// at 0xb8; 5 fades the alpha at 0x120 by 1/30 to 0 and mode 6; 6 unlinks the node (func_00011BE0, func_00011C20).
void Object_00101180::func_00101410()
{
    switch (mode) {
    case 0:
        pending = 1;
        flags_50 = 0;
        counter = 0;
        mode = 1;
    case 1:
        pending = 1;
        if (++counter >= 39.0) {
            counter = 0;
            flags_50 |= 0x80000000;
            func_001011E0();
            mode = 3;
        }
        break;
    case 3: {
        position.x += velocity.x;
        position.y += velocity.y;
        position.z += velocity.z;
        velocity.y -= 0.1f;
        float limit = -fall;
        if (velocity.y < limit) {
            velocity.y = limit;
        }
        float turn = (int)func_0014C690(velocity.z) * 5.0f;
        angles[0] += (int)(turn * 182.04445f);
        turn = (int)func_0014C690(velocity.x) * -5.0f;
        angles[2] += (int)(turn * 182.04445f);
        shown = position;
        break;
    }
    case 5:
        alpha -= 0.033333335f;
        if (alpha <= 0.0f) {
            alpha = 0.0f;
            mode = 6;
        }
        break;
    case 6:
        func_00011BE0(this);
        func_00011C20(child);
        break;
    }
}
