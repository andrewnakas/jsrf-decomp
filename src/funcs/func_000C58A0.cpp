/* sym: ?func_00011C90@Object_000C5B50@@UAEXXZ = 0x000C58A0 */
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

struct Vector3 {
    float x;
    float y;
    float z;
};

// The object at data_00257CE4; its position is at 0x7c.
struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 position;
};

extern Object_000C1270 *data_00257CE4;

float __fastcall func_0014C530(const Vector3 *a, const Vector3 *b);

// One item of the list at 0xd0 (linked at 0x74): flags at 0x4c.
struct Item_000C5B50 {
    char unknown_00[0x4c];
    unsigned int flags;
    char unknown_50[0x24];
    Item_000C5B50 *next;
};

// The child of Node whose table is at 0x1CDFF0 (constructor func_000C5830, destructor func_000C6150): two parts
// at 0xd4 and 0xd8 that take over slots 2, 3 and 12. The behaviours keep it at their 0x4 (func_000C5B10 and the
// other members of 0xC59A0-0xC5B70 take it as this).
struct Object_000C5B50 : Node {
    int unknown_040;
    Vector3 position;
    char unknown_050[0x20];
    float distance;
    char unknown_074[0x30];
    unsigned int flags_a4;
    char unknown_0a8[0x28];
    Item_000C5B50 *items;
    Part_000C5910 *first;
    Part_000C5910 *second;

    virtual void func_00011C90();
};

// Slot 1: the distance at 0x70 to data_00257CE4's position (func_0014C530), slot 0 of both parts, and flag 0x2000 at
// 0xa4 while it has items at 0xd0 and every one of them has that flag.
void Object_000C5B50::func_00011C90()
{
    distance = func_0014C530(&position, &data_00257CE4->position);
    if (first) {
        first->slot0();
    }
    if (second) {
        second->slot0();
    }
    if (items) {
        flags_a4 |= 0x2000;
        for (Item_000C5B50 *item = items; item; item = item->next) {
            if (!(item->flags & 0x2000)) {
                flags_a4 &= ~0x2000;
                break;
            }
        }
    }
}
