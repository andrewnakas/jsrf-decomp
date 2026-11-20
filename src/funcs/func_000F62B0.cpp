/* sym: ?func_00011C90_1@Object_000F55E0@@UAEXXZ = 0x000F62B0 */
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
    int unknown_40;
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_0006DB80 {
    void func_0006DFC0(int key, const Vector3 *position);
};

extern Object_0006DB80 data_00251F78;

// The object at data_00257CE8 (func_00157F10 is the engine's); it also answers func_000C1D40.
struct Object_00157F10 {
    int func_000C1D40(int *effect, int *second, int *third);
};

extern Object_00157F10 *data_00257CE8;

// The owner at 0xb0.
struct Object_000C5B50 {
    char unknown_00[0x9c];
    int value_9c;

    int func_000C5B10(int message, void *data);
};

void func_000FEC30(int value, const Vector3 *position);

// The skeleton at 0x130.
struct Object_00047470 {
    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

void func_001BA9C0();
void func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

// The second base (table 0x1CE1B8), two slots.
struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

// The child of Node whose table is at 0x1CF220 (constructor func_000F5E70, destructor func_000F60C0). The class of the
// table at 0x1CEAC0 derives from it. The second base sits at 0x44 (tables 0x1CE1B8, then 0x1CF214).
struct Object_000F55E0 : Node, Object_000C60C0 {
    virtual void func_00011C90_1();
    void func_000F59B0();

    Vector3 position;
    char unknown_054[0x3c];
    unsigned int bits;
    char unknown_094[4];
    int effect_98;
    int value_9c;
    char unknown_0a0[0x10];
    Object_000C5B50 *owner;
    char unknown_0b4[8];
    int state;
    char unknown_0c0[0xc];
    Vector3 point;
    int value_d8;
    char unknown_0dc[0x54];
    Object_00047470 *skeleton;
    char unknown_134[0x14];
    void *motion;
    char unknown_14c[0x1c];
    int value_168;
    char unknown_16c[0x80];
    int sound;
    int value_1f0;
    int value_1f4;
};

// Slot 2: func_000F59B0, then the position takes the point at 0xcc. Unless 0x90 has bit 13, func_000C1D40 on
// data_00257CE8 accepts the sound at 0x1ec (with 0x1f4 and 0x1f0): bit 13 set (bits 15 and 24 cleared), state 0xf,
// 0x168 = 0xb, the second base's slot 1, 0xd8 = 0, 0x9c = 1 and owner message 0x11 with the position; or
// func_000FEC30 gets the owner's 0x9c and the position. Then the effect at 0x98 (unless -1) goes to the origin of
// bone 9 of the skeleton posed at the position (func_0006DFC0).
void Object_000F55E0::func_00011C90_1()
{
    func_000F59B0();
    position = point;
    if (bits & 0x2000) {
        return;
    }
    if (data_00257CE8->func_000C1D40(&sound, &value_1f4, &value_1f0)) {
        bits = (bits & 0xfedf7fff) | 0x2000;
        state = 0xf;
        value_168 = 0xb;
        func_000C60C0();
        value_d8 = 0;
        value_9c = 1;
        owner->func_000C5B10(0x11, &position);
    } else {
        func_000FEC30(owner->value_9c, &position);
    }
    if (effect_98 != -1) {
        Vector3 origin;
        func_001BA9C0();
        func_001BAAA0(&position.x);
        skeleton->func_00047970(motion, 0);
        skeleton->func_000480C0(9);
        func_001BAB20(&origin, 0);
        func_001BAA50();
        data_00251F78.func_0006DFC0(effect_98, &origin);
    }
}
