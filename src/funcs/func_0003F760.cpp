/* sym: ??1Object_0003F760@@UAE@XZ = 0x0003F760 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The hash table at 0x2314B0.
struct Object_0003E750 {
    void func_0003F280(int key);
};

extern Object_0003E750 data_002314B0;

// Object 0xe8.
struct Object_000607B0 {
    void func_000607B0(int index);
};

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

// The node class whose table is at 0x1CA558.
struct Object_0003F760 : Node {
    virtual ~Object_0003F760();

    char unknown_44[0x14];
    int key;
    char unknown_5c[0x130];
    int entry;
};

// Hands its key (+0x58) to func_0003F280 of 0x2314B0 and, when it holds an entry (+0x18c not negative), passes it to
// func_000607B0 of object 0xe8.
Object_0003F760::~Object_0003F760()
{
    data_002314B0.func_0003F280(key);
    if (entry >= 0) {
        Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (object) {
            object->func_000607B0(entry);
        }
    }
}
