/* sym: ?func_00011C80@Object_000AA4B0@@UAEXH@Z = 0x000AAFB0 */
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

// An entry's model, drawn through its slot 5 (two words); its fade at 0x58 and a value at 0x5c.
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

// One placed copy (0x1bc bytes).
struct Item_000AAFB0 {
    int unknown_000[2];
    int kind;
    int seen;
    int value_010;
    char unknown_014[0x58];
    int key;
    int value_070;
    Model_00101A70 *model;
    char unknown_078[0x10];
    Vector3 position;
    int angles[3];
    Vector3 scale;
    char unknown_0ac[0x38];
    Matrix_001BA950 matrix;
    unsigned int state;
    float time;
    char unknown_12c[0x90];
};

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

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD658).
struct Object_000AA4B0 : Node {
    virtual void func_00011C80(int argument);

    char unknown_040[4];
    Item_000AAFB0 *items;
    unsigned int count;
};

// Slot 3 (the pass): for each item not of kind 4 whose key (0x6c) data_0020C6C0 knows, marks it seen (0xc) and draws
// it with its matrix (pass 3), poses it into its matrix keeping its time as the node's depth (pass 2) or poses and
// draws it in place (pass 1). The model's state comes from func_000B9B50; states 2 and 3 are not drawn, and in state
// 1 the fade comes from func_000B9C70 of the time and is reset to -1 after the draw.
void Object_000AA4B0::func_00011C80(int argument)
{
    for (unsigned int i = 0; i < count; i++) {
        if (items[i].kind == 4 || items[i].key == -1) {
            continue;
        }
        if (!data_0020C6C0.func_0006AC10(items[i].key)) {
            continue;
        }
        items[i].seen = 1;
        switch (argument) {
        case 3:
            if (items[i].state == 2 || items[i].state == 3) {
                break;
            }
            if (!items[i].model) {
                break;
            }
            items[i].model->value_5c = items[i].value_070;
            if (items[i].state == 1) {
                items[i].model->fade = func_000B9C70(items[i].time);
            }
            if (items[i].model->fade != 0.0f) {
                func_001BA9C0();
                func_001BA8F0(&items[i].matrix);
                items[i].model->draw(0, 0);
                func_001BAA50();
            }
            if (items[i].state == 1) {
                items[i].model->fade = -1.0f;
            }
            break;
        case 2:
            func_001BA9C0();
            func_001BAAA0(&items[i].position.x);
            func_001BAC50(items[i].angles, 0);
            func_001BB270(&items[i].scale.x);
            func_001BA950(&items[i].matrix);
            items[i].state = func_000B9B50(items[i].model, &items[i].time);
            if (items[i].state != 2 && items[i].state != 3) {
                items[i].value_010 = 1;
            }
            func_001BAA50();
            depth = items[i].time;
            break;
        case 1:
            func_001BA9C0();
            func_001BAAA0(&items[i].position.x);
            func_001BAC50(items[i].angles, 0);
            func_001BB270(&items[i].scale.x);
            items[i].state = func_000B9B50(items[i].model, &items[i].time);
            if (items[i].state != 2 && items[i].state != 3) {
                items[i].value_010 = 1;
                if (items[i].model) {
                    items[i].model->value_5c = items[i].value_070;
                    if (items[i].state == 1) {
                        items[i].model->fade = func_000B9C70(items[i].time);
                    }
                    if (items[i].model->fade != 0.0f) {
                        items[i].model->draw(0, 0);
                    }
                    if (items[i].state == 1) {
                        items[i].model->fade = -1.0f;
                    }
                }
            }
            func_001BAA50();
            break;
        }
    }
}
