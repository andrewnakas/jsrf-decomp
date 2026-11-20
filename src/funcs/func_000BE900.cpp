struct Node {
    virtual ~Node();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(int argument);

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

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Owner_000BE900 {
    char unknown_000[0x300];
    Vector3 position;
};

struct Object_000BE900 : Node {
    char unknown_040[4];
    Vector3 position;
    char unknown_050[0x24];
    int value_74;

    void func_000BE900();
};

// Takes the parent's position at 0x300 and sets the field at 0x74 to 0x71c.
void Object_000BE900::func_000BE900()
{
    Owner_000BE900 *owner = (Owner_000BE900 *)func_00011BD0();
    position.x = owner->position.x;
    position.y = owner->position.y;
    position.z = owner->position.z;
    value_74 = 0x71c;
}
