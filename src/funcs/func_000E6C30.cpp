/* sym: ??1Object_000E6E80@@UAE@XZ = 0x000E6C30 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000E6E80@@UAEXXZ = 0x000E7470 */
/* sym: ?func_00011C90_1@Object_000E6E80@@UAEXXZ = 0x000E7540 */
/* sym: ?func_00011C80@Object_000E6E80@@UAEXH@Z = 0x000E7550 */
/* sym: ?func_00011C80_3@Object_000E6E80@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000E6E80@@UAEXH@Z = 0x000B3DE0 */
struct Object_00016200 {
    void func_00019760(void *pointer);
};

extern Object_00016200 data_0022FCE8;

int func_001186D0(int handle);

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

// The child of Node whose table is at 0x1CEDA0; slots 12, 15 hold folded thunks.
struct Object_000E6E80 : Node {
    virtual ~Object_000E6E80();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_044[0x54c];
    void *mesh;
    char unknown_594[0x18];
    int handle;
};

// Hands the handle at 0x5ac to func_001186D0 and frees the mesh at 0x590 (data_0022FCE8).
Object_000E6E80::~Object_000E6E80()
{
    func_001186D0(handle);
    if (mesh) {
        data_0022FCE8.func_00019760(mesh);
    }
}
