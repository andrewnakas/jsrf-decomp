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

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_00039BE0 {
    void func_0003A550(unsigned int index);
};

extern Object_00039BE0 data_001EFFB0;

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

// The owner at 0xb0.
struct Object_000C5B50 {
    int func_000C5B10(int message, void *data);
};

void func_000C4B70(int kind);
void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
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

struct Desc_000E5380;

// The second base (table 0x1CE1B8), two slots.
struct Object_000C60C0 {
    virtual void func_000C6090(Object_000C60C0 *previous, Desc_000E5380 *owner, int index);
    virtual void func_000C60C0();
};

// The class whose tables are at 0x1CEDF0 (Node) and 0x1CEDE8 (Object_000C60C0 at +0x44).
struct Object_000E7770 : Node, Object_000C60C0 {
    void func_000E78F0();

    Vector3 position;
    Angles_000C1300 angles;
    char unknown_060[0x50];
    Object_000C5B50 *owner;
    char unknown_0b4[8];
    int state;
    int value_c0;
    unsigned int number;
};

// Entry 2 of the handlers at 0x2584A0: state 3, unlinks the chain link (slot 1 of the second base), clears the
// number at 0xc4 in data_001EFFB0 (func_0003A550), runs func_000C4B70(4) in a matrix placed and turned like the
// object, and starts kind 0x45 of object 0xe8 and message 3 to the owner at 10 above the position.
void Object_000E7770::func_000E78F0()
{
    state = 3;
    value_c0 = 0;
    func_000C60C0();
    data_001EFFB0.func_0003A550(number);
    func_001BA9C0();
    func_001BAAA0(&position.x);
    func_001BB330(angles.y + 0x8000);
    func_001BB2E0(angles.x);
    func_001BB380(angles.z);
    func_000C4B70(4);
    func_001BAA50();
    Vector3 point = position;
    point.y += 10.0f;
    Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (object) {
        object->func_000651E0(0x45, &point, 0);
    }
    owner->func_000C5B10(3, &point);
}
