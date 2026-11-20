/* sym: ??0Object_0004EF90@@QAE@PAUNode@@HI@Z = 0x0004ECD0 */
void func_0004EAF0();

struct Game {
    void func_000127C0(int id, int value);
    int func_000127E0(int id);
};

extern Game *data_0022FCE0;

struct Object_00039BE0 {
    void func_0003B5A0();
    void func_0003B680();
};

extern Object_00039BE0 data_001EFFB0;

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();

    char unknown_04[0x40];
};

// The class whose table is at 0x1CAAF8 (constructor 0x4ECD0, destructor 0x4EF00; 0xb0 bytes).
struct Object_0004EF90 : Node {
    Object_0004EF90(Node *owner, int id, unsigned int flags);
    virtual ~Object_0004EF90();

    char unknown_44[0x6c];
};

struct Object_0007C250 : Node {
    int unknown_44;
    int state;

    void func_0007CC40();
};

// State handler 36 of the table at 0x20D2B8: sets setting 0x19a, keeps setting 2 at +0x44, runs data_001EFFB0's
// func_0003B680, copies settings 5 and 6 to 2 and 3, runs data_001EFFB0's func_0003B5A0 and func_0004EAF0, makes a new
// Object_0004EF90 under this object (id 8) and goes to state 0x25.
void Object_0007C250::func_0007CC40()
{
    data_0022FCE0->func_000127C0(0x19a, 1);
    unknown_44 = data_0022FCE0->func_000127E0(2);
    data_001EFFB0.func_0003B680();
    data_0022FCE0->func_000127C0(2, data_0022FCE0->func_000127E0(5));
    data_0022FCE0->func_000127C0(3, data_0022FCE0->func_000127E0(6));
    data_001EFFB0.func_0003B5A0();
    func_0004EAF0();
    new Object_0004EF90(this, 8, 0);
    state = 0x25;
}
