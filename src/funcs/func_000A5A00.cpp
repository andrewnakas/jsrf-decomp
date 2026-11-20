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
    char unknown_cb0[0x32c];
    float value_fdc;
    float value_fe0;
    float value_fe4;
};

int func_0014C7D0(float first, float second);

struct Object_000A4D80 : Node {
    char unknown_040[0xac];
    int value_ec;
    char unknown_0f0[0xf4];
    Vector3 start;
    Vector3 value_1f0;
    char unknown_1fc[0x2c];
    int value_228;
    char unknown_22c[8];
    int value_234;
    int latched;

    void func_000A5390(Vector3 *first, Vector3 *second);
    void func_000A5A00();
};

// Entry 9 of the camera node's member-function table at 0x215534 (called by func_000A5070, its slot 1, when the mode
// at 0x208 changes): the angle (func_0014C7D0) from the player's position at 0xca4 to its point at 0xfdc into 0xec,
// func_000A5390 with the vectors at 0x1e4 and 0x1f0, and the first time only the field at 0x228 copied to 0x234 with
// the latch at 0x238 set.
void Object_000A4D80::func_000A5A00()
{
    Object_000A1C50 *player = (Object_000A1C50 *)func_00011BD0();
    value_ec = func_0014C7D0(player->value_fdc - player->position.x, player->value_fe4 - player->position.z);
    func_000A5390(&start, &value_1f0);
    if (!latched) {
        value_234 = value_228;
        latched = 1;
    }
}
