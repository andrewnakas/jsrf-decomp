extern "C" void *memcpy(void *destination, const void *source, unsigned int size);

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

// The child of Node whose table is at 0x1D1BA8 (destructor func_000FD9B0); slot 16 is its own.
struct Object_000FDDC0 : Node {
    Object_000FDDC0(Node *owner, int id, unsigned int flags, int kind, int value, int first, const char *text,
                    int second, int third);
    virtual void func_000FDDC0();

    char unknown_40[0x50];
};

// The camera node (constructor func_00012170).
struct Object_00012170 : Node {
    char unknown_040[0x58];
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

// Object 0x1165 (constructor func_000FE740, destructor func_000FDF30).
struct Object_000FDF30 : Object_00012170 {
    char unknown_098[0xc];
    int ids[7];
    int pending[7];
    Entry_000FDF30 entries[7];

    void func_000FE8A0(int index, int value, int first, const char *text, int second, int third);
};

extern Game *data_0022FCE0;

void func_00116810();

// Unless `index` is 6, takes out entry 6's child (after func_00116810) and drops its pending text. Then, when entry
// `index` has no child, creates one (an Object_000FDDC0 with the values); otherwise keeps the values as pending for
// it, with a copy of the text up to its first "$r", and calls the child's slot 16.
void Object_000FDF30::func_000FE8A0(int index, int value, int first, const char *text, int second, int third)
{
    if (index != 6) {
        if (ids[6] != -1) {
            Node *node = (Node *)data_0022FCE0->func_000128C0(ids[6]);
            if (node) {
                func_00116810();
                node->func_00011BE0(node);
                node->func_00011C20(node->child);
            }
            ids[6] = -1;
        }
        if (pending[6] != -1) {
            if (entries[6].text) {
                operator delete(entries[6].text);
                entries[6].text = 0;
            }
            pending[6] = -1;
        }
    }
    if (ids[index] == -1) {
        ids[index] = data_0022FCE0->func_000128E0(0x1208, 0x1288);
        new Object_000FDDC0(this, ids[index], 0x100, index, value, first, text, second, third);
    } else {
        pending[index] = index;
        entries[index].value = value;
        entries[index].first = first;
        if (entries[index].text) {
            operator delete(entries[index].text);
            entries[index].text = 0;
        }
        unsigned int length = 0;
        for (;;) {
            if (text[length++] != '$') {
                continue;
            }
            if (text[length++] != 'r') {
                continue;
            }
            if (text[length++] != 0) {
                continue;
            }
            break;
        }
        entries[index].text = (char *)operator new(length);
        memcpy(entries[index].text, text, length);
        entries[index].second = second;
        entries[index].third = third;
        if (ids[index] != -1) {
            Object_000FDDC0 *child = (Object_000FDDC0 *)data_0022FCE0->func_000128C0(ids[index]);
            if (child) {
                child->func_000FDDC0();
            }
        }
    }
}
