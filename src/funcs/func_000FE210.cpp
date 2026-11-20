/* sym: ??0Object_000FDDC0@@QAE@PAUNode@@HIHHHPBDHH@Z = 0x000FD870 */
struct Game {
    void *func_000128C0(int id);
    int func_000128E0(int first, int last);
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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

// The child of Node whose table is at 0x1D1BA8 (destructor func_000FD9B0): it keeps the value it was created with at
// 0x8c.
struct Object_000FDDC0 : Node {
    Object_000FDDC0(Node *owner, int id, unsigned int flags, int kind, int value, int first, const char *text,
                    int second, int third);

    char unknown_40[0x4c];
    int value;
};

// An entry of the list at 0xdc: what func_000FE370 passes to the child it creates.
struct Entry_000FDF30 {
    int value;
    int first;
    char *text;
    int second;
    int third;
    int unknown_14;
};

// The camera node (constructor func_00012170).
struct Object_00012170 : Node {
    char unknown_040[0x58];
};

// Object 0x1165 (constructor func_000FE740, destructor func_000FDF30).
struct Object_000FDF30 : Object_00012170 {
    char unknown_098[0xc];
    int ids[7];
    int pending[7];
    Entry_000FDF30 entries[7];

    void func_000FE210(int value);
};

extern Game *data_0022FCE0;

// For entry 0 only: takes out its child when it was created with `value` and clears the id; then, when entry 0 is
// pending, drops it if it holds `value`, else creates its child (kind 0) as func_000FE370 does; frees the text.
void Object_000FDF30::func_000FE210(int value)
{
    if (ids[0] != -1) {
        Object_000FDDC0 *child = (Object_000FDDC0 *)data_0022FCE0->func_000128C0(ids[0]);
        if (child && child->value == value) {
            child->func_00011BE0(child);
            child->func_00011C20(child->child);
            ids[0] = -1;
        }
    }
    if (pending[0] != -1) {
        if (entries[0].value == value) {
            if (entries[0].text) {
                operator delete(entries[0].text);
                entries[0].text = 0;
            }
            pending[0] = -1;
            return;
        }
        ids[0] = data_0022FCE0->func_000128E0(0x1208, 0x1288);
        new Object_000FDDC0(this, ids[0], 0x100, 0, entries[0].value, entries[0].first, entries[0].text,
                            entries[0].second, entries[0].third);
        pending[0] = -1;
        if (entries[0].text) {
            operator delete(entries[0].text);
            entries[0].text = 0;
        }
    }
}
