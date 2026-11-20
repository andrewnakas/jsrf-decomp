/* sym: ?func_00011C80@Object_000AE220@@UAEXH@Z = 0x000AE560 */
struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAC50(int *angles, int zero);
void __fastcall func_001BB270(float *scale);

// A model drawn through its slot 5 (two words); a value at 0x5c.
struct Model_00101A70 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void draw(int first, int second);

    char unknown_04[0x58];
    int value_5c;
};

unsigned int func_000B9B50(Model_00101A70 *model, float *time);

struct Object_00015D50 {
    void func_00015F90();
};

struct Object_0006A960 {
    int func_0006AC10(int key);
};

extern Object_0006A960 data_0020C6C0;

struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);

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

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD730).
struct Object_000AE220 : Node {
    virtual void func_00011C80(int argument);

    char unknown_040[0x98];
    int key;
    int value_dc;
    int seen;
    int value_e4;
    char unknown_0e8[8];
    Model_00101A70 *model;
    Object_00015D50 *part;
    Vector3 position;
    int angles[3];
    Vector3 scale;
    char unknown_11c[0x68];
    unsigned int state;
    float time;
};

// Slot 3 (the pass), when data_0020C6C0 knows the key at 0xd8: marks the node seen (0xe0), then poses it (pass 2:
// position, angles and scale, the model's state from func_000B9B50, the time as the node's depth) or, unless that
// state is 2 or 3, draws its part (pass 3: func_00015F90, the model taking the value at 0xdc).
void Object_000AE220::func_00011C80(int argument)
{
    if (key == -1 || !data_0020C6C0.func_0006AC10(key)) {
        return;
    }
    seen = 1;
    switch (argument) {
    case 2:
        func_001BA9C0();
        func_001BAAA0(&position.x);
        func_001BAC50(angles, 0);
        func_001BB270(&scale.x);
        state = func_000B9B50(model, &time);
        if (state != 2 && state != 3) {
            value_e4 = 1;
        }
        func_001BAA50();
        depth = time;
        break;
    case 3:
        if (state == 2 || state == 3) {
            break;
        }
        if (!part) {
            break;
        }
        if (model) {
            model->value_5c = value_dc;
        }
        func_001BA9C0();
        part->func_00015F90();
        func_001BAA50();
        break;
    }
}
