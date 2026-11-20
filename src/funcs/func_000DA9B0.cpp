/* sym: ?func_00011C90@Object_000DAB10@@UAEXXZ = 0x000DA9B0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

float __fastcall func_0014C530(const Vector3 *a, const Vector3 *b);

struct Node {
    Node(Node *owner, int id, unsigned int flags);
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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);

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

// The class whose table is at 0x1CE6E0: one point of the list func_000DAB10 builds.
struct Object_000DAAB0 {
    Object_000DAAB0(const Vector3 *point)
    {
        this->point = point;
        distance = 1000.0f;
        value_18 = 0;
        state = 0;
        next = 0;
        active = 1;
        value_14 = 0;
    }
    virtual void func_000DAA70();
    virtual void func_000DAAB0();
    virtual void func_000DAAE0();
    virtual void func_000DAB00();
    virtual ~Object_000DAAB0() {}
    virtual void func_000DAA40();

    const Vector3 *point;
    int state;
    float distance;
    int active;
    int value_14;
    int value_18;
    Object_000DAAB0 *next;
};

// What func_000DAB10 takes: count points of 12 bytes.
struct Params_000DAB10 {
    char unknown_00[0xc];
    unsigned int count;
    const Vector3 *points;
};

// The class whose table is at 0x1CE6A0: a list of points at 0x44, one for each point of its descriptor.
struct Object_000DAB10 : Node {
    Object_000DAB10(Node *owner, int id, unsigned int flags, Params_000DAB10 *desc);
    virtual ~Object_000DAB10();
    virtual void func_00011C90();

    Object_000DAAB0 *first;
};

// Runs each point (its slot 5); when one reaches state 2, every point closer than 30 to it gets 1 at 0x14. Once no
// point is active, the node unlinks itself and its children.
void Object_000DAB10::func_00011C90()
{
    int active = 0;
    for (Object_000DAAB0 *item = first; item; item = item->next) {
        item->func_000DAA40();
        if (item->state == 2) {
            for (Object_000DAAB0 *other = first; other; other = other->next) {
                if (func_0014C530(item->point, other->point) < 30.0f) {
                    other->value_14 = 1;
                }
            }
        }
        if (item->active == 1) {
            active++;
        }
    }
    if (!active) {
        func_00011BE0(this);
        func_00011C20(child);
    }
}
