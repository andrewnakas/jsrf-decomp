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

    Node *func_00011BD0();
};

// The entry the player's parent follows (0x8d0): a word at 8 and two points from 0xc.
struct Entry_000A61C0 {
    int unknown_00[2];
    int value_08;
    Vector3 first;
    Vector3 second;
};

// The player's parent: the entry at 0x8d0.
struct Owner_00091C30 {
    char unknown_000[0x8d0];
    Entry_000A61C0 *entry;
};

// What the player keeps at 0xc90: a value at 0x48.
struct State_00091C30 {
    char unknown_00[0x48];
    int value_48;
};

// What the player keeps at 0x101c: a value at 0x44.
struct Link_00091C30 {
    char unknown_00[0x44];
    int value_44;
};

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
    char unknown_c5c[0x34];
    State_00091C30 *state;
    char unknown_c94[0x10];
    Vector3 position;
    char unknown_cb0[0x1a0];
    int value_e50;
    char unknown_e54[4];
    int value_e58;
    char unknown_e5c[0xb8];
    int value_f14;
    char unknown_f18[0x104];
    Link_00091C30 *link;

    void func_0007EB90(unsigned int kind, float step);
    void func_0007FD20();
    void func_000836F0(Entry_000A61C0 *entry, int value);
    void func_00089E00();
    void func_00092FF0(int first, int second, int third, int fourth);
    void func_000A1CF0();
    void func_00091C30();
};

// Moves the player by its velocity and steps it (func_00089E00, func_0007FD20); when the counter at 0xc58 runs out,
// hands the points at 0x404 and 0x410 to the parent's entry (func_000836F0 with the value at 0xf14), passes the
// value at 0x41c to the link at 0x101c, sets state 0x9f with value 0xe and calls func_0007EB90 (0, 1/60),
// func_000A1CF0 and func_00092FF0 with the value of the object at 0xc90.
void Object_000A1C50::func_00091C30()
{
    position.x += velocity.x;
    position.y += velocity.y;
    position.z += velocity.z;
    func_00089E00();
    func_0007FD20();
    if (--counter == 0) {
        Owner_00091C30 *owner = (Owner_00091C30 *)func_00011BD0();
        owner->entry->value_08 = 0;
        owner->entry->first.x = first_404.x;
        owner->entry->first.y = first_404.y;
        owner->entry->first.z = first_404.z;
        owner->entry->second.x = second_410.x;
        owner->entry->second.y = second_410.y;
        owner->entry->second.z = second_410.z;
        func_000836F0(owner->entry, value_f14);
        if (link) {
            link->value_44 = value_41c;
        }
        value_e58 = 3;
        value_11c = 0x9f;
        value_e50 = 0xe;
        func_0007EB90(0, 1.0f / 60.0f);
        func_000A1CF0();
        func_00092FF0(state->value_48, -1, 0, 0);
    }
}
