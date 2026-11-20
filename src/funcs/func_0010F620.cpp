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

struct Owner_0010F620 : Node {
    char unknown_040[0xa0];
    int value_e0;
};

struct Object_0010F620 : Node {
    char unknown_040[0x28];
    int value_68;
    float timer;

    virtual void func_0010F620();
};

// Virtual (slot 1 of the vtable at data_001D24F0). Advances the timer at 0x6c by 1/60 and wraps it at 0.5;
// restarts it when the parent's field at 0xe0
// changes, keeping a copy at 0x68.
void Object_0010F620::func_0010F620()
{
    timer += 0.016666668f;
    if (timer >= 0.5f) {
        timer = 0.0f;
    }
    Owner_0010F620 *owner = (Owner_0010F620 *)func_00011BD0();
    if (owner && value_68 != owner->value_e0) {
        value_68 = owner->value_e0;
        timer = 0.0f;
    }
}
