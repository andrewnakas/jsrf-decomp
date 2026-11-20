/* sym: ??0Object_000947F0@@QAE@PAUNode@@HI@Z = 0x000947F0 */
/* sym: ??1Object_000947F0@@UAE@XZ = 0x000948F0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
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

// Marks every key unused and clears every value.
Object_000947F0::Object_000947F0(Node *owner, int id, unsigned int flags)
    : Node(owner, id, flags)
{
    keys[0] = -1;
    keys[1] = -1;
    keys[2] = -1;
    keys[3] = -1;
    keys[4] = -1;
    keys[5] = -1;
    keys[6] = -1;
    keys[7] = -1;
    keys[8] = -1;
    keys[9] = -1;
    keys[10] = -1;
    keys[11] = -1;
    keys[12] = -1;
    keys[13] = -1;
    keys[14] = -1;
    keys[15] = -1;
    keys[16] = -1;
    keys[17] = -1;
    keys[18] = -1;
    keys[19] = -1;
    keys[20] = -1;
    values[0] = 0;
    values[1] = 0;
    values[2] = 0;
    values[3] = 0;
    values[4] = 0;
    values[5] = 0;
    values[6] = 0;
    values[7] = 0;
    values[8] = 0;
    values[9] = 0;
    values[10] = 0;
    values[11] = 0;
    values[12] = 0;
    values[13] = 0;
    values[14] = 0;
    values[15] = 0;
    values[16] = 0;
    values[17] = 0;
    values[18] = 0;
    values[19] = 0;
    values[20] = 0;
}
