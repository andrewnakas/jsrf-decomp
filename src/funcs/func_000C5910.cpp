/* sym: ?func_00011C90_1@Object_000C5B50@@UAEXXZ = 0x000C5910 */
struct Part_000C5910 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2(int argument);
    virtual void slot3(int argument);
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

// The child of Node whose table is at 0x1CDFF0 (constructor func_000C5830, destructor func_000C6150): two parts
// at 0xd4 and 0xd8 that take over slots 2, 3 and 12. The behaviours keep it at their 0x4 (func_000C5B10 and the
// other members of 0xC59A0-0xC5B70 take it as this).
struct Object_000C5B50 : Node {
    char unknown_040[0x94];
    Part_000C5910 *first;
    Part_000C5910 *second;

    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
};

// Overrides Node's slot 2: calls slot 1 of the two parts that exist.
void Object_000C5B50::func_00011C90_1()
{
    if (first) {
        first->slot1();
    }
    if (second) {
        second->slot1();
    }
}
