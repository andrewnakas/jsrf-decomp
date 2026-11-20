/* sym: ??1Object_000C39E0@@UAE@XZ = 0x000C3970 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000C39E0@@UAEXXZ = 0x000C39E0 */
/* sym: ?func_00011C90_1@Object_000C39E0@@UAEXXZ = 0x000C3A20 */
/* sym: ?func_00011C80@Object_000C39E0@@UAEXH@Z = 0x000C3A60 */
/* sym: ?func_00011C90_6@Object_000C39E0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_7@Object_000C39E0@@UAEXXZ = 0x000AEE80 */
/* sym: ?func_00011C80_3@Object_000C39E0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000C39E0@@UAEXH@Z = 0x000B3DE0 */
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
    char unknown_34[0x10];
};

struct Item_000C39E0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual ~Item_000C39E0();
    virtual void slot10();

    char unknown_04[0x44];
    float value_48;
    char unknown_4c[0x7c];
    Item_000C39E0 *next;
};

// The Node class whose table is at 0x1cdd60 (stored by its constructor): overrides Node's slots 1 to 3.
struct Object_000C39E0 : Node {
    virtual ~Object_000C39E0();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    Item_000C39E0 *items;
};

// Deletes every item of the list at 0x44 (linked at 0xc8; their destructor is slot 9).
Object_000C39E0::~Object_000C39E0()
{
    Item_000C39E0 *item = items;
    while (item) {
        Item_000C39E0 *current = item;
        item = item->next;
        delete current;
    }
}
