/* sym: ?func_00011C90@Object_00106390@@UAEXXZ = 0x001063A0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The owner the id at 0x98 names.
struct Object_00107FE0 {
    int func_00107AB0();
    int func_00107DD0(int id);
};

// The sprite at 0x54: its frame count at 0x2.
struct Sprite_001067A0 {
    short unknown_00;
    short count;
};

struct Node {
    virtual ~Node();
    virtual void func_00011C90();

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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

// The child of Node whose table is at 0x1D1FD8 (destructor func_00106390).
struct Object_00106390 : Node {
    virtual void func_00011C90();

    char unknown_40[4];
    unsigned int mask;
    int state;
    int value_4c;
    void *unknown_50;
    Sprite_001067A0 *sprite;
    float frame;
    float frameStep;
    unsigned int color;
    float alpha;
    float alphaStep;
    Vector3 *target;
    Vector3 position;
    char unknown_7c[8];
    float size;
    unsigned int ticks;
    float value_8c;
    float value_90;
    float value_94;
    int ownerId;
};

// Slot 1 (the step) of a sprite node. State 0 takes func_00107AB0 of the owner (the id at 0x98) and grows in state 2:
// the size at 0x84 shrinks by 0.45 + 0.03 per tick and the alpha at 0x64 rises by its step until the size is down to
// 1 (then state 3, 15 ticks). State 3 moves the frame at 0x58 on by 0x5c and, once it reaches the sprite's frame count
// less 1, sets it to the count less itself. State 5 grows the size back to 10 as the alpha falls (then state 6),
// state 6 unlinks the node. While the top bit of 0x44 is clear it follows the target at 0x6c as long as the owner's
// func_00107DD0 of its id gives 1, else goes to state 6.
void Object_00106390::func_00011C90()
{
    Object_00107FE0 *owner = (Object_00107FE0 *)data_0022FCE0->func_000128C0(ownerId);
    switch (state) {
    case 0:
        value_4c = owner->func_00107AB0();
        frame = 0.0f;
        ticks = 0;
        state = 2;
    case 2:
        size -= ticks++ * 0.03f + 0.45f;
        alpha += alphaStep;
        if (size <= 1.0f) {
            alpha = size = 1.0f;
            ticks = 15;
            state = 3;
        }
        break;
    case 3: {
        frame += frameStep;
        float count = sprite->count;
        if (frame >= count - 1.0f) {
            frame = count - frame;
        }
        break;
    }
    case 5:
        size = size + (ticks-- * 0.03f + 0.45f);
        alpha -= alphaStep;
        if (size >= 10.0f) {
            size = 10.0f;
            alpha = 0.0f;
            ticks = 0;
            state = 6;
        }
        break;
    case 6:
        func_00011BE0(this);
        func_00011C20(child);
        break;
    }
    if (!(mask & 0x80000000)) {
        if (owner->func_00107DD0(id) == 1) {
            if (target) {
                position.x = target->x;
                position.y = target->y;
                position.z = target->z;
            }
        } else {
            state = 6;
        }
    }
}
