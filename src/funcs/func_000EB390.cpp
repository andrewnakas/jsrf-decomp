/* sym: ?func_00011C80@Object_000EB440@@UAEXH@Z = 0x000EB390 */
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAC50(int *angles, int zero);

struct Part_000EB390 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);
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
};

// The child of Node whose table is at 0x1CEED8.
struct Object_000EB440 : Node {
    char unknown_40[4];
    float position[3];
    char unknown_50[0x1c];
    int angles[3];
    char unknown_78[0xc];
    Part_000EB390 *part;

    virtual void func_00011C80(int argument);
};

// Overrides Node's slot 3 (the argument is not used): func_001BAAA0 on the position at 0x44, func_001BAC50 on
// the angles at 0x6c, then slot 5 of the part at 0x84 with two zeros.
void Object_000EB440::func_00011C80(int)
{
    func_001BAAA0(position);
    func_001BAC50(angles, 0);
    part->slot5(0, 0);
}
