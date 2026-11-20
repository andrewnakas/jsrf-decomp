/* sym: ?func_00011C90_10@Object_000C5490@@UAEXXZ = 0x000C5490 */
struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_0014C730(Vector3 *target, Vector3 *direction, float scale);

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

// The child of Node whose table is at 0x1CDE60 (constructor func_000C4CF0, destructor func_000C4E50): it
// overrides slots 1, 2, 3, 12 and 15 and adds three empty slots, 16 to 18.
struct Object_000C4CF0 : Node {
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);
    virtual void func_00011C90_10();
    virtual void func_00011C90_11();
    virtual void func_00011C90_12();
};

// The child of func_000C4CF0's class with the table at 0x1CDF50 (constructor func_000C53D0).
struct Object_000C5490 : Object_000C4CF0 {
    char unknown_40[0x10];
    Vector3 position;
    Vector3 velocity;

    virtual void func_00011C90_10();
};

// Overrides slot 16: moves the position along the velocity (func_0014C730 adds direction * scale to target).
void Object_000C5490::func_00011C90_10()
{
    func_0014C730(&position, &velocity, 3.7037037f);
}
