struct Matrix_001BA950 {
    float m[4][4];
};

void func_001BA9C0();
void func_001BAA50();
void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);
float func_000B9C70(float value);

// A model drawn through its slot 5 (two words); its fade at 0x58 and a value at 0x5c.
struct Model_000B1440 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void draw(int first, int second);

    char unknown_04[0x54];
    float fade;
    int value_5c;
};

// One of the node's entries (0x1e0 bytes).
struct Entry_000B1440 {
    int unknown_000;
    int kind;
    char unknown_008[0x68];
    int value_070;
    char unknown_074[0x18];
    Model_000B1440 *model;
    int value_090;
    int unknown_094;
    int value_098;
    char unknown_09c[0x5c];
    Matrix_001BA950 matrix;
    int state;
    float time;
    char unknown_140[0xa0];
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

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD838).
struct Object_000B1130 : Node {
    char unknown_040[4];
    Entry_000B1440 *entries;
    unsigned int count;

    void func_000B1440(int index);
};

// Draws entry `index` with its matrix (func_001BA8F0) and model slot 5 (0, 0) while its fade is not zero; entries not
// of kind 1 skip states 2 and 3 and, in state 1, take the fade from func_000B9C70 of the time at 0x13c and reset it
// to -1 afterwards.
void Object_000B1130::func_000B1440(int index)
{
    if (entries[index].kind != 1 && (entries[index].state == 2 || entries[index].state == 3)) {
        return;
    }
    if (!entries[index].model) {
        return;
    }
    if (entries[index].kind != 1 && entries[index].state == 1) {
        entries[index].model->fade = func_000B9C70(entries[index].time);
    }
    if (entries[index].model->fade != 0.0f) {
        func_001BA9C0();
        func_001BA8F0(&entries[index].matrix);
        entries[index].model->value_5c = entries[index].value_070;
        entries[index].model->draw(0, 0);
        func_001BAA50();
    }
    if (entries[index].kind != 1 && entries[index].state == 1) {
        entries[index].model->fade = -1.0f;
    }
}
