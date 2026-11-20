struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
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

struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);

// The part an object of the family keeps at +0xb4.
struct Part_000866F0 : Node {
    char unknown_44[0x14];
    float unknown_58;
    char unknown_5c[0x20];
    float unknown_7c;
    char unknown_80[0x4];
    Vector3 unknown_84;
};

// The family of tables at 0x1CD120, 0x1CD170, 0x1CD1C0 and 0x1CD210.
struct Object_00086960 : Node {
    virtual void func_000866F0(int argument);

    char unknown_044[0x24];
    Vector3 unknown_68;
    char unknown_074[0x3c];
    int unknown_b0;
    Part_000866F0 *part;
};

// Slot 18 of the tables at 0x1CD120, 0x1CD1C0 and 0x1CD210: hands the vector at +0x68 through func_001BAC00 to the
// part's +0x84, sets the part's +0x7c to 70 and +0x58 to 1, and runs the part's slot 6 with the word at +0xb0.
void Object_00086960::func_000866F0(int argument)
{
    Part_000866F0 *part = this->part;
    func_001BAC00(&part->unknown_84, &unknown_68);
    part->unknown_7c = 70.0f;
    part->unknown_58 = 1.0f;
    part->func_00011C80_1(unknown_b0);
}
