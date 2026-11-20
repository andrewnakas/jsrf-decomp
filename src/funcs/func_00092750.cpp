struct Vector3 {
    float x;
    float y;
    float z;
};

struct Node {
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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};

// The player.
struct Object_000A1C50 : Node {
    char unknown_040[0xdc];
    int value_11c;
    char unknown_120[0x2bc];
    Vector3 first_3dc;
    Vector3 velocity;
    Vector3 second_3f4;
    int value_400;
    Vector3 first_404;
    Vector3 second_410;
    int value_41c;
    char unknown_420[0x838];
    int counter;
    char unknown_c5c[0x48];
    Vector3 position;
    Vector3 previous_cb0;
    char unknown_cbc[0x194];
    int value_e50;
    char unknown_e54[4];
    int value_e58;
    char unknown_e5c[0x280];
    Vector3 first_10dc;
    Vector3 second_10e8;

    void func_0007EB90(unsigned int color, float step);
    void func_0009BEB0();
    int func_00092750();
};

// Called by func_00080340: state 0xb with value 0xf, counter 60, value 0x80 at 0x11c, a black fade over 1/60 (camera),
// the velocity as the last move of the position; after func_0009BEB0 keeps the two points at 0x3dc and 0x3f4.
int Object_000A1C50::func_00092750()
{
    value_e58 = 0xb;
    counter = 0x3c;
    value_11c = 0x80;
    func_0007EB90(0xff000000, 1.0f / 60.0f);
    value_e50 = 0xf;
    velocity.x = position.x - previous_cb0.x;
    velocity.y = position.y - previous_cb0.y;
    velocity.z = position.z - previous_cb0.z;
    func_0009BEB0();
    first_10dc = first_3dc;
    second_10e8.x = second_3f4.x;
    second_10e8.y = second_3f4.y;
    second_10e8.z = second_3f4.z;
    return 1;
}
