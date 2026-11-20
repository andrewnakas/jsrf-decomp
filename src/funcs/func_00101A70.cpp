/* const: 0x200000 */
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

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The owner (Object_00107FE0): its mask at 0x16ac.
struct Object_00107FE0 {
    char unknown_0000[0x16ac];
    unsigned int mask;
};

struct Motion_0005F060;

// The model at 0x58: slot 5 poses it, its alpha is at 0x58.
struct Model_00101A70 {
    virtual void func_00();
    virtual void func_04();
    virtual void func_08();
    virtual void func_0C();
    virtual void func_10();
    virtual void func_14(Motion_0005F060 *motion, float time);

    char unknown_04[0x54];
    float alpha;
};

struct Matrix_001BA950 {
    float m[4][4];
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);
void __fastcall func_001BA950(Matrix_001BA950 *matrix);
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAC50(int *angles, int order);
void __fastcall func_001BB270(float *scale);
unsigned int func_000B9B50(Model_00101A70 *model, float *depth);

// The child of Node whose table is at 0x1D1D48 (constructor func_00100F40, destructor func_00101100).
struct Object_00101180 : Node {
    void func_00101A70(int event);

    char unknown_040[0x10];
    unsigned int flags;
    int hidden;
    Model_00101A70 *model;
    Motion_0005F060 *motion;
    float time;
    char unknown_064[0x30];
    float position[3];
    int angles[3];
    float scale[3];
    char unknown_0b8[0x24];
    Matrix_001BA950 matrix;
    char unknown_11c[4];
    float alpha;
    char unknown_124[4];
    float distance;
    char unknown_12c[8];
    int ownerId;
};

// Entry 1 of data_0021FFB0 (slot 3 in state 1): while the owner's mask has bit 21, message 0, 3, 5 or 8 draws the model
// (with bit 31 of 0x50, an alpha above 0 and a model) through the matrix at 0xdc, with the alpha at 0x120 while it is
// below 1; message 2 or 7 places the matrix at 0xdc (position, angles, scale), sets 0x54 when func_000B9B50 gives 1 or
// less, and takes the depth it gives.
void Object_00101180::func_00101A70(int event)
{
    Object_00107FE0 *owner = (Object_00107FE0 *)data_0022FCE0->func_000128C0(ownerId);
    if (!(owner->mask & 0x200000)) {
        return;
    }
    switch (event) {
    case 0:
    case 3:
    case 5:
    case 8:
        if ((flags & 0x80000000) && alpha > 0.0f && model) {
            func_001BA9C0();
            func_001BA8F0(&matrix);
            if (alpha < 1.0f) {
                model->alpha = alpha;
            }
            model->func_14(motion, time);
            if (alpha < 1.0f) {
                model->alpha = 1.0f;
            }
            func_001BAA50();
        }
        break;
    case 2:
    case 7:
        func_001BA9C0();
        func_001BAAA0(position);
        func_001BAC50(angles, 0);
        func_001BB270(scale);
        func_001BA950(&matrix);
        if (func_000B9B50(model, &distance) <= 1) {
            hidden = 1;
        }
        func_001BAA50();
        depth = distance;
        break;
    }
}
