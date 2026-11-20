/* sym: ??0Object_0004EF90@@QAE@PAUNode@@HI@Z = 0x0004ECD0 */
void func_0004EAF0();
void func_001165D0(int value);

struct Game {
    void func_000127C0(int id, int value);
    int func_000127E0(int id);
};

extern Game *data_0022FCE0;

struct Object_00039BE0 {
    void func_0003AED0();
    void func_0003B3C0();
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

    void func_0007C160();
};

// State handler 10 of the table at 0x20D2B8: sets settings 8 (0), 0xb (1), 9 (0) and 0x19a (1), runs func_0004EAF0,
// makes a new Object_0004EF90 under this object (id 8), goes to state 0xb, runs data_001EFFB0's func_0003AED0 and
// func_0003B3C0 (open; declared `void ()`) and func_001165D0 (0x3c).
void Object_0007C250::func_0007C160()
{
    data_0022FCE0->func_000127C0(8, 0);
    data_0022FCE0->func_000127C0(0xb, 1);
    data_0022FCE0->func_000127C0(9, 0);
    data_0022FCE0->func_000127C0(0x19a, 1);
    func_0004EAF0();
    new Object_0004EF90(this, 8, 0);
    state = 0xb;
    data_001EFFB0.func_0003AED0();
    data_001EFFB0.func_0003B3C0();
    func_001165D0(0x3c);
}
