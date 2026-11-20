/* sym: ??0Object_0001E140@@QAE@PAUNode@@HIPAX@Z = 0x0001E280 */
/* sym: ??1Object_0001E140@@UAE@XZ = 0x0001E140 */
/* sym: ??0Object_00012170@@QAE@PAUNode@@HI@Z = 0x00012170 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void func_00012710(int value);
};

extern Game *data_0022FCE0;

// Four words copied into new Object_0001E140s.
struct Colour_0001E280 {
    int unknown_00;
    int unknown_04;
    int unknown_08;
    int unknown_0c;
};

extern Colour_0001E280 data_001EBAD0;

// What the constructor is given: three vectors 0x10 apart.
struct Data_0001E280 {
    Vector3 first;
    char unknown_0c[4];
    Vector3 second;
    char unknown_1c[4];
    Vector3 third;
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

    char unknown_44[0x40];
};

// The node class whose table is at 0x1C45C8 (destructor 0x1E140; 0xd8 bytes): object 0x1ddf.
struct Object_0001E140 : Object_00012170 {
    Object_0001E140(Node *owner, int id, unsigned int flags, void *data);
    virtual ~Object_0001E140();

    Colour_0001E280 colour;
    char unknown_94[4];
    Vector3 third;
    Vector3 first;
    Vector3 second;
    int unknown_bc;
    int unknown_c0;
    int unknown_c4;
    float value;
    float speed;
    int state;
    unsigned int timer;
};

// Takes the three vectors of `data` (the third to +0x98, the first to +0xa4, the second to +0xb0), sets +0xc4, +0xbc
// and +0xc0, copies the four words at 0x1EBAD0 to +0x84, starts the fade (value 0, speed 1/90, state 0, timer 90) and
// runs func_00012710 (1) of the game.
Object_0001E140::Object_0001E140(Node *owner, int id, unsigned int flags, void *data)
    : Object_00012170(owner, id, flags)
{
    Data_0001E280 *source = (Data_0001E280 *)data;
    third = source->third;
    first = source->first;
    second = source->second;
    unknown_c4 = 0x471c;
    unknown_bc = 0x9be;
    unknown_c0 = -0xc83;
    colour = data_001EBAD0;
    value = 0.0f;
    speed = 1.0f / 90.0f;
    state = 0;
    timer = 90;
    data_0022FCE0->func_00012710(1);
}
