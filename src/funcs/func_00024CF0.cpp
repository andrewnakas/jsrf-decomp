void func_00025740(unsigned int index, int argument);
void func_00026080();

/* sym: ??1Object_00024CF0@@UAE@XZ = 0x00024CF0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00024CF0@@UAEXXZ = 0x00025040 */
/* sym: ?func_00011C90_2@Object_00024CF0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_4@Object_00024CF0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_6@Object_00024CF0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_8@Object_00024CF0@@UAEXXZ = 0x000AECC0 */
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


// The class whose table is at 0x1C4D58: overrides slots 1 (25040), 4 (AECC0), 7 (AECC0), 10 (AECC0), 13 (AECC0).
struct Object_00024CF0 : Node {
    virtual ~Object_00024CF0();
    virtual void func_00011C90();
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();

    int unknown_44;
    int unknown_48;
    int unknown_4c;
    int unknown_50;
    int state;
    int unknown_58[0x48];
    int handle;
    int unknown_17c;
};

// Runs func_00026080 when its state (+0x54) is 3, clears handler 0x1f (func_00025740) and its +0x178.
Object_00024CF0::~Object_00024CF0()
{
    if (state == 3) {
        func_00026080();
    }
    func_00025740(0x1f, 0);
    handle = 0;
}
