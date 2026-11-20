struct Vector3 {
    float x;
    float y;
    float z;
};

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

    Node *func_00011BD0();
};

// The player (the camera node's parent).
struct Object_000A1C50 {
    char unknown_000[0xca4];
    Vector3 position;
    char unknown_cb0[0x190];
    float value_e40;
    float value_e44;
    float value_e48;
};

int func_0014C7D0(float first, float second);

struct Object_000A4D80 : Node {
    char unknown_040[0xb0];
    int value_f0;
    char unknown_0f4[0xf0];
    Vector3 start;
    Vector3 value_1f0;
    char unknown_1fc[0x2c];
    int value_228;
    char unknown_22c[8];
    int value_234;
    int latched;

    void func_000A5620(Vector3 *first, Vector3 *second);
    void func_000A5AF0();
};

// Entry 13 of the camera node's member-function table at 0x215534 (called by func_000A5070, its slot 1, when the mode
// at 0x208 changes): the angle (func_0014C7D0) from the player's position at 0xca4 to its point at 0xe40 into 0xf0,
// func_000A5620 with the vectors at 0x1e4 and 0x1f0, and the first time only the field at 0x228 copied to 0x234 with
// the latch at 0x238 set.
void Object_000A4D80::func_000A5AF0()
{
    Object_000A1C50 *player = (Object_000A1C50 *)func_00011BD0();
    value_f0 = func_0014C7D0(player->value_e40 - player->position.x, player->value_e48 - player->position.z);
    func_000A5620(&start, &value_1f0);
    if (!latched) {
        value_234 = value_228;
        latched = 1;
    }
}
