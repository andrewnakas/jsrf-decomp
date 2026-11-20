struct Vector3 {
    float x;
    float y;
    float z;
};

// Three angles (x, y, z).
struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 position;
};

extern Object_000C1270 *data_00257CE4;

struct Object_00157F10 {
    void func_000C1300(Angles_000C1300 *angles, Vector3 *direction);
    void func_000C1F20(Angles_000C1300 *angles, Vector3 *direction, int step);
};

extern Object_00157F10 *data_00257CE8;

struct Object_00066980 {
    float func_00066950();
};

extern Object_00066980 data_00251F28;

void __fastcall func_0014C300(Vector3 *out, const Vector3 *a, const Vector3 *b);
void __fastcall func_0014C370(Vector3 *out, const Vector3 *in, float scale);
void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
float __fastcall func_0014C620(int angle);
void __fastcall func_0014C730(Vector3 *target, Vector3 *direction, float scale);
void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

struct Node {
    Node(Node *owner, int id, unsigned int flags);
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

// The child of Node whose table is at 0x1CEDA0; its handlers (table at 0x218E4C) run by the state at 0x9c.
struct Object_000E6E80 : Node {
    void func_000E7260();

    Vector3 origin;
    Vector3 position;
    Vector3 start;
    Vector3 previous;
    Vector3 direction;
    float speed;
    Angles_000C1300 angles;
    Angles_000C1300 angles_90;
    char unknown_09c[0x484];
    float sway;
    int phase;
    int roll;
};

// Turns towards the object at data_00257CE4 from the origin (func_000C1F20 with 0x111), moves the position along
// the direction at the speed, and keeps at 0x68 the position plus the up vector turned by the angles and the roll
// (0x528) and scaled by the sway at 0x520. The phase at 0x524 steps by 0x36; past 0x8000 it starts again and the
// roll moves on by 0x6000 less a random part of 0x4000 (16 bits kept). The sway is 20 times the sine of the phase;
// the angles at 0x90 point from the start (0x5c) to the point at 0x68.
void Object_000E6E80::func_000E7260()
{
    Vector3 offset;
    func_0014C4C0(&offset, &data_00257CE4->position, &origin);
    data_00257CE8->func_000C1F20(&angles, &offset, 0x111);
    data_00257CE8->func_000C1300(&angles, &direction);
    func_0014C730(&position, &direction, speed);
    Vector3 up;
    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;
    func_001BAA00();
    func_001BB330(angles.y + 0x8000);
    func_001BB2E0(angles.x);
    func_001BB380(roll);
    func_001BAC00(&up, &up);
    func_001BAA50();
    func_0014C370(&up, &up, sway);
    func_0014C300(&previous, &position, &up);
    phase += 0x36;
    if (phase >= 0x8000) {
        phase = 0;
        roll += 0x6000 - (int)(data_00251F28.func_00066950() * -16384.0f);
        ((short *)&roll)[1] = 0;
    }
    sway = func_0014C620(phase) * 20.0f;
    func_0014C4C0(&up, &previous, &start);
    data_00257CE8->func_000C1F20(&angles_90, &up, 0x8000);
}
