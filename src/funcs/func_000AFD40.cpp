/* sym: ?func_00011C80@Object_000AF790@@UAEXH@Z = 0x000AFD40 */
struct Matrix_001BA950 {
    float m[4][4];
};

struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);
void __fastcall func_001BA950(Matrix_001BA950 *matrix);
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAC50(int *angles, int zero);
void __fastcall func_001BB270(float *scale);
float func_000B9C70(float value);

// The model, drawn through its slot 5 (two words); its fade at 0x58 and a value at 0x5c.
struct Model_00101A70 {
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

unsigned int func_000B9B50(Model_00101A70 *model, float *time);

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

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD7B0).
struct Object_000AF790 : Node {
    virtual void func_00011C80(int argument);

    char unknown_040[0xc];
    int kind;
    char unknown_050[0x68];
    int key;
    int value_bc;
    int seen;
    int value_c4;
    char unknown_c8[8];
    Model_00101A70 *model;
    Vector3 position;
    int angles[3];
    Vector3 scale;
    char unknown_0f8[0x4c];
    Matrix_001BA950 matrix;
    unsigned int state;
    float time;
};

// Slot 3 (the pass): when data_0020C6C0 knows the key at 0xb8, marks the object seen (0xc0); unless its kind (0x4c)
// is 10, draws the model with the matrix at 0x144 (passes 3 and 8) or poses it into that matrix keeping its time as
// the node's depth (passes 2 and 7). The model's state comes from func_000B9B50; states 2 and 3 are not drawn, and in
// state 1 the fade comes from func_000B9C70 of the time and is reset to -1 after the draw.
void Object_000AF790::func_00011C80(int argument)
{
    if (key == -1) {
        return;
    }
    if (!data_0020C6C0.func_0006AC10(key)) {
        return;
    }
    seen = 1;
    if (kind == 10) {
        return;
    }
    switch (argument) {
    case 3:
    case 8:
        if (state == 2 || state == 3) {
            break;
        }
        if (!model) {
            break;
        }
        model->value_5c = value_bc;
        if (state == 1) {
            model->fade = func_000B9C70(time);
        }
        if (model->fade != 0.0f) {
            func_001BA9C0();
            func_001BA8F0(&matrix);
            model->draw(0, 0);
            func_001BAA50();
        }
        if (state == 1) {
            model->fade = -1.0f;
        }
        break;
    case 2:
    case 7:
        func_001BA9C0();
        func_001BAAA0(&position.x);
        func_001BAC50(angles, 0);
        func_001BB270(&scale.x);
        func_001BA950(&matrix);
        state = func_000B9B50(model, &time);
        if (state != 2 && state != 3) {
            value_c4 = 1;
        }
        func_001BAA50();
        depth = time;
        break;
    }
}
