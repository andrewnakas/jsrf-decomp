struct Vector3 {
    float x;
    float y;
    float z;
};

struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C90_5();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C90_9();
    virtual void func_00011C80_4(int argument);

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


struct Motion_0005F060;

struct Game {
    int func_000127E0(int index);
};
extern Game *data_0022FCE0;

// A direct child of Node (table 0x1D1F58, constructor func_00104E00, destructor func_00104EE0).
struct Object_00104EE0 : Node {
    virtual ~Object_00104EE0();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();

    int unknown_040;
    int value_44;
    int value_48;
    void *sprites[3];
    void *sprite_58;
    Vector3 point;
    int value_68;
    int value_6c;
    int value_70;
    float screen[2];

    void func_00104EF0(Vector3 *out);
};

// Where the sprite goes on the screen for the projected point at 0x74: one fifth of the point's offset from its
// player's view (0x48 picks the quarter, half or third of the screen by the player count, func_000127E0(0xc)) and
// minus a fifth of its height (a tenth, stretched about the middle, for two players); a tenth with any other count.
void Object_00104EE0::func_00104EF0(Vector3 *out)
{
    switch (data_0022FCE0->func_000127E0(0xc)) {
    case 2:
        switch (value_48) {
        case 0:
            out->x = screen[0] * 0.2f;
            break;
        case 1:
            out->x = (screen[0] - 320.0f) * 0.2f;
            break;
        }
        if (screen[1] < 240.0f) {
            out->y = (screen[1] + screen[1] - 240.0f) * -0.1f;
        } else {
            out->y = ((screen[1] - 240.0f) + (screen[1] - 240.0f) + 240.0f) * -0.1f;
        }
        break;
    case 3:
        switch (value_48) {
        case 0:
            out->x = screen[0] * 0.2f;
            out->y = screen[1] * -0.2f;
            break;
        case 1:
            out->x = (screen[0] - 320.0f) * 0.2f;
            out->y = screen[1] * -0.2f;
            break;
        case 2:
            out->x = (screen[0] - 160.0f) * 0.2f;
            out->y = (screen[1] - 240.0f) * -0.2f;
            break;
        }
        break;
    case 4:
        switch (value_48) {
        case 0:
            out->x = screen[0] * 0.2f;
            out->y = screen[1] * -0.2f;
            break;
        case 1:
            out->x = (screen[0] - 320.0f) * 0.2f;
            out->y = screen[1] * -0.2f;
            break;
        case 2:
            out->x = screen[0] * 0.2f;
            out->y = (screen[1] - 240.0f) * -0.2f;
            break;
        case 3:
            out->x = (screen[0] - 320.0f) * 0.2f;
            out->y = (screen[1] - 240.0f) * -0.2f;
            break;
        }
        break;
    default:
        out->x = screen[0] * 0.1f;
        out->y = screen[1] * -0.1f;
        break;
    }
    out->z = 0.0f;
}
