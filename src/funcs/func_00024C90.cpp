/* sym: ??1Object_00024CF0@@UAE@XZ = 0x00024CF0 */
/* sym: ?func_00011C90@Object_00024CF0@@UAEXXZ = 0x00025040 */
/* sym: ?func_00011C90_2@Object_00024CF0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_4@Object_00024CF0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_6@Object_00024CF0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_8@Object_00024CF0@@UAEXXZ = 0x000AECC0 */
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

/* sym: ??0Object_00024CF0@@QAE@PAUNode@@HI@Z = 0x00024C90 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */

// The class whose table is at 0x1C4D58: overrides slots 1 (25040), 4 (AECC0), 7 (AECC0), 10 (AECC0), 13 (AECC0).
struct Object_00024CF0 : Node {
    virtual ~Object_00024CF0();
    virtual void func_00011C90();
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();

    Object_00024CF0(Node *owner, int id, unsigned int flags);

    int unknown_44;
    int unknown_48;
    int unknown_4c;
    int unknown_50;
    int unknown_54;
    int unknown_58[0x48];
    int unknown_178;
    int unknown_17c;
};

// Clears its words (+0x48 to -1) and the table at +0x58.
Object_00024CF0::Object_00024CF0(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    unknown_44 = 0;
    unknown_4c = 0;
    unknown_50 = 0;
    unknown_54 = 0;
    unknown_178 = 0;
    unknown_17c = 0;
    unknown_48 = -1;
    for (int i = 0; i < 0x48; i++) {
        unknown_58[i] = 0;
    }
}
