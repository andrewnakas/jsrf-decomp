/* sym: ?func_00011C90@Object_00097350@@UAEXXZ = 0x000972C0 */
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

    Node *func_00011BD0();
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    void func_000606C0(int key, Vector3 *value);
    void func_00060730(int key, Vector3 *value);
    int func_000609A0(int key);
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

// The player: its points (0xce0, 12 bytes each) and a direction at 0xddc.
struct Object_000A1C50 : Node {
    char unknown_040[0xca0];
    Vector3 points[21];
    Vector3 direction;
};

// The child of Node whose table is at 0x1CD420 (constructor func_00097190, destructor func_00097250): a mark of
// node 0xe8 (key at 0x44, kind at 0x4c) that follows a point (0x48) of the player it hangs under.
struct Object_00097350 : Node {
    Object_00097350(Node *owner, int id, unsigned int flags, int kind, int point);
    virtual ~Object_00097350();
    virtual void func_00011C90();
    virtual void func_00011C90_2();

    int unknown_040;
    int key;
    int point;
    int kind;
};

// Slot 1: when the mark has run out (func_000609A0 of node 0xe8 says 1) removes itself and everything below it;
// otherwise moves the mark to the player's point (func_000606C0), and for kind 0x12 also turns it to the player's
// direction (func_00060730).
void Object_00097350::func_00011C90()
{
    Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    Object_000A1C50 *player = (Object_000A1C50 *)func_00011BD0();
    if (player && object) {
        if (object->func_000609A0(key) == 1) {
            func_00011BE0(this);
            func_00011C20(child);
            return;
        }
        object->func_000606C0(key, &player->points[point]);
        if (kind == 0x12) {
            object->func_00060730(key, &player->direction);
        }
    }
}
