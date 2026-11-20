/* sym: ??1Object_000F55E0@@UAE@XZ = 0x000F60C0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
void func_0005DAA0(void *pointer);

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();

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

// The owner the chain serves, seen through its handle table.
struct Object_000C5B50 {
    void func_000C5B50(int *handle);
    int func_000C5B70(int handle);
};

struct Object_0006DB80 {
    void func_0006DF30(int handle);
};

extern Object_0006DB80 data_00251F78;

// The hash table at 0x2314B0.
struct Object_0003E750 {
    void func_0003F280(int key);
};

extern Object_0003E750 data_002314B0;

struct Object_00016200 {
    void func_00019760(void *pointer);
};

extern Object_00016200 data_0022FCE8;

struct Desc_000E5380;

// The link of a chain (the second base, at 0x44; table 0x1CE1B8): the object it serves at 0x6c.
struct Object_000C60C0 {
    virtual void func_000C6090(Object_000C60C0 *previous, Desc_000E5380 *owner, int index);
    virtual void func_000C60C0();

    char unknown_04[0x50];
    int handle;
    char unknown_58[0x14];
    Object_000C5B50 *owner;
    Object_000C60C0 *previous;
    Object_000C60C0 *next;
};

// The child of Node whose table is at 0x1CF220 (0x200 bytes; constructor func_000F5E70), a link of the chain at 0x44.
struct Object_000F55E0 : Node, Object_000C60C0 {
    virtual ~Object_000F55E0();

    char unknown_0bc[0x8c];
    void *blocks[3];
    char unknown_154[0x28];
    void *item;
    char unknown_180[0x6c];
    int key;
    char unknown_1f0[8];
    int handles[2];
};

// Frees both handles of the owner's table that are still live, the handle at 0x98 (data_00251F78), the key at
// 0x1ec and the item at 0x17c, then the three blocks at 0x148.
Object_000F55E0::~Object_000F55E0()
{
    if (owner->func_000C5B70(handles[0])) {
        owner->func_000C5B50(&handles[0]);
    }
    if (owner->func_000C5B70(handles[1])) {
        owner->func_000C5B50(&handles[1]);
    }
    if (handle != -1) {
        data_00251F78.func_0006DF30(handle);
    }
    if (key != -1) {
        data_002314B0.func_0003F280(key);
    }
    if (item) {
        data_0022FCE8.func_00019760(item);
    }
    func_0005DAA0(blocks[0]);
    func_0005DAA0(blocks[1]);
    func_0005DAA0(blocks[2]);
}
