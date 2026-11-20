/* sym: ??1Object_0004EF90@@UAE@XZ = 0x0004EF00 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_0004EF90@@UAEXXZ = 0x0004EF90 */
/* sym: ?func_00011C80@Object_0004EF90@@UAEXH@Z = 0x0004F9A0 */
/* sym: ?func_00011C90_2@Object_0004EF90@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_4@Object_0004EF90@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_6@Object_0004EF90@@UAEXXZ = 0x000AECC0 */
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

// The class whose table is at 0x1CAAF8: overrides slots 1 (4EF90), 3 (4F9A0), 4 (AECC0), 7 (AECC0), 10 (AECC0).
int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);
void func_00025740(unsigned int index, int argument);

struct Object_0004EF90 : Node {
    virtual ~Object_0004EF90();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();

    unsigned int state;
    void *unknown_48;
    int unknown_4c;
    char unknown_50[0x40];
    void *buffers[4];
};

// Frees the four buffers (VirtualFree, MEM_RELEASE) and releases handler 0x14 when +0x48 is set.
Object_0004EF90::~Object_0004EF90()
{
    for (int i = 0; i < 4; i++) {
        if (buffers[i]) {
            func_00145A5D(buffers[i], 0, 0x8000);
        }
    }
    if (unknown_48) {
        func_00025740(0x14, 0);
    }
}
