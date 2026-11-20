/* sym: ??1Object_000947F0@@UAE@XZ = 0x000948F0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
struct Object_000607B0 {
    void func_000607B0(int key);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

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

// The node class whose table is at 0x1CD290 (0xec bytes; destructor 0x948F0, slot 2 0x94AB0): 21 keys of the game's
// object 0xe8 at 0x44, -1 while unused, and 21 values at 0x98.
struct Object_000947F0 : Node {
    Object_000947F0(Node *owner, int id, unsigned int flags);
    virtual ~Object_000947F0();

    int keys[21];
    int values[21];
};

// Frees every key in use from the game's object 0xe8 (when it exists).
Object_000947F0::~Object_000947F0()
{
    Object_000607B0 *table = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (table) {
        if (keys[0] >= 0) {
            table->func_000607B0(keys[0]);
        }
        if (keys[1] >= 0) {
            table->func_000607B0(keys[1]);
        }
        if (keys[2] >= 0) {
            table->func_000607B0(keys[2]);
        }
        if (keys[3] >= 0) {
            table->func_000607B0(keys[3]);
        }
        if (keys[4] >= 0) {
            table->func_000607B0(keys[4]);
        }
        if (keys[5] >= 0) {
            table->func_000607B0(keys[5]);
        }
        if (keys[6] >= 0) {
            table->func_000607B0(keys[6]);
        }
        if (keys[7] >= 0) {
            table->func_000607B0(keys[7]);
        }
        if (keys[8] >= 0) {
            table->func_000607B0(keys[8]);
        }
        if (keys[9] >= 0) {
            table->func_000607B0(keys[9]);
        }
        if (keys[10] >= 0) {
            table->func_000607B0(keys[10]);
        }
        if (keys[11] >= 0) {
            table->func_000607B0(keys[11]);
        }
        if (keys[12] >= 0) {
            table->func_000607B0(keys[12]);
        }
        if (keys[13] >= 0) {
            table->func_000607B0(keys[13]);
        }
        if (keys[14] >= 0) {
            table->func_000607B0(keys[14]);
        }
        if (keys[15] >= 0) {
            table->func_000607B0(keys[15]);
        }
        if (keys[16] >= 0) {
            table->func_000607B0(keys[16]);
        }
        if (keys[17] >= 0) {
            table->func_000607B0(keys[17]);
        }
        if (keys[18] >= 0) {
            table->func_000607B0(keys[18]);
        }
        if (keys[19] >= 0) {
            table->func_000607B0(keys[19]);
        }
        if (keys[20] >= 0) {
            table->func_000607B0(keys[20]);
        }
    }
}
