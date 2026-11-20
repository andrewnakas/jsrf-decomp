/* sym: ??0Object_000239D0@@QAE@PAUNode@@HIH@Z = 0x00024150 */
/* sym: ??1Object_000239D0@@UAE@XZ = 0x000239D0 */
/* sym: ??0Object_00012170@@QAE@PAUNode@@HI@Z = 0x00012170 */
/* sym: ??0Object_000461B0@@QAE@PAUNode@@HIH@Z = 0x000461B0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
extern "C" void *memset(void *destination, int value, unsigned int size);
void func_00118780(int value);

struct Vector3 {
    float x;
    float y;
    float z;
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

// A node with no virtual functions of its own (table 0x1C43D8 repeats Node's slots 1 to 15) and mask 7.
struct Object_00012170 : Node {
    Object_00012170(Node *owner, int id, unsigned int flags);

    char unknown_44[0x54];
};

// The node class whose table is at 0x1CA7D8 (constructor 0x461B0, destructor 0x46310; 0x44 bytes).
struct Object_000461B0 {
    Object_000461B0(Node *owner, int id, unsigned int flags, int value);

    char unknown_00[0x44];
};

// The object 0x1ddc (table 0x1C4C88): made by 0x24240.
struct Object_000239D0 : Object_00012170 {
    Object_000239D0(Node *owner, int id, unsigned int flags, int unused);
    virtual ~Object_000239D0();

    union {
        int words[0x19];
        struct {
            char unknown_098[0x40];
            float first[3];
            float second[3];
            char unknown_0f0[4];
            int unknown_0f4;
        };
    };
};

// Clears +0x98 to +0xfc, sets +0xf4 to 0x3555, creates an Object_000461B0 under it (no id, flags 0, 100), runs
// func_00118780 (1), and clears the vectors at +0xd8 and +0xe4 but for the latter's y of 1. The last argument is not
// used.
Object_000239D0::Object_000239D0(Node *owner, int id, unsigned int flags, int unused)
    : Object_00012170(owner, id, flags)
{
    memset(words, 0, sizeof(words));
    unknown_0f4 = 0x3555;
    new Object_000461B0(this, -1, 0, 100);
    func_00118780(1);
    memset(first, 0, sizeof(first));
    memset(second, 0, sizeof(second));
    second[1] = 1.0f;
}
