/* sym: ??0Object_00043950@@QAE@PAUNode@@HIH@Z = 0x00044660 */
/* sym: ??1Object_00043950@@UAE@XZ = 0x00043950 */
/* sym: ??0Object_00012170@@QAE@PAUNode@@HI@Z = 0x00012170 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
void *func_00025700(unsigned int index, int first, int second, int third);

struct Game {
    void func_00012710(int value);
};

extern Game *data_0022FCE0;

// Four words copied into new Object_00043950s.
struct Colour_00044660 {
    int unknown_00;
    int unknown_04;
    int unknown_08;
    int unknown_0c;
};

extern Colour_00044660 data_001F90EC;

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

    char unknown_44[0x40];
};

// The node class whose table is at 0x1CA708 (destructor 0x43950; 0xa8 bytes).
struct Object_00043950 : Object_00012170 {
    Object_00043950(Node *owner, int id, unsigned int flags, int value);
    virtual ~Object_00043950();

    Colour_00044660 colour;
    char unknown_94[4];
    void *unknown_98;
    int unknown_9c;
    int unknown_a0;
    int value;
};

// Copies the four words at 0x1F90EC to +0x84, takes +0x98 from func_00025700 (11, 0, 5, 1), clears +0x9c and +0xa0,
// keeps `value` at +0xa4 and runs func_00012710 (1) of the game.
Object_00043950::Object_00043950(Node *owner, int id, unsigned int flags, int value)
    : Object_00012170(owner, id, flags)
{
    colour = data_001F90EC;
    unknown_98 = func_00025700(11, 0, 5, 1);
    unknown_9c = 0;
    unknown_a0 = 0;
    this->value = value;
    data_0022FCE0->func_00012710(1);
}
