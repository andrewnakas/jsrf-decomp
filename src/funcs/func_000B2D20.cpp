/* sym: ?func_00011C80@Object_000B1130@@UAEXH@Z = 0x000B2D20 */
struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BA9C0();
void func_001BAA50();
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

// One of the node's entries (0x1e0 bytes).
struct Entry_000B2D20 {
    int used;
    int kind;
    char unknown_008[0x64];
    int key;
    int value_070;
    int visible;
    int dirty;
    char unknown_07c[0x10];
    Model_00101A70 *model;
    int value_090;
    int unknown_094;
    int value_098;
    char unknown_09c[0xc];
    Vector3 position;
    int angles[3];
    Vector3 scale;
    char unknown_0cc[0x24];
    int posed;
    char unknown_0f4[0x44];
    unsigned int state;
    float time;
    int unknown_140;
    int phase;
    char unknown_148[0x98];
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

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD838).
struct Object_000B1130 : Node {
    virtual void func_00011C80(int argument);

    char unknown_040[4];
    Entry_000B2D20 *entries;
    unsigned int count;

    void func_000B1330(int index);
    void func_000B1440(int index);
    void func_000B1530(int index);
    void func_000B1620(unsigned int index);
};

// Slot 3 (the pass): for each used entry whose key (0x6c) data_0020C6C0 knows, marks it seen (0x74) and, unless its
// phase (0x144) is 10, draws it (pass 3: func_000B1330, or func_000B1440 when posed at 0xf0), poses it (pass 2:
// func_000B1530 or func_000B1620, keeping its time as the node's depth) or poses and draws it in place (pass 1).
void Object_000B1130::func_00011C80(int argument)
{
    for (unsigned int i = 0; i < count; i++) {
        if (!entries[i].used || entries[i].key == -1) {
            continue;
        }
        if (!data_0020C6C0.func_0006AC10(entries[i].key)) {
            continue;
        }
        entries[i].visible = 1;
        if (entries[i].phase == 10) {
            continue;
        }
        switch (argument) {
        case 3:
            if (!entries[i].posed) {
                func_000B1330(i);
            } else {
                func_000B1440(i);
            }
            break;
        case 2:
            if (!entries[i].posed) {
                func_000B1530(i);
            } else {
                func_000B1620(i);
            }
            depth = entries[i].time;
            break;
        case 1:
            func_001BA9C0();
            func_001BAAA0(&entries[i].position.x);
            func_001BAC50(entries[i].angles, 0);
            func_001BB270(&entries[i].scale.x);
            entries[i].state = func_000B9B50(entries[i].model, &entries[i].time);
            if (entries[i].state == 0 || entries[i].state == 1) {
                entries[i].dirty = 1;
                if (entries[i].model) {
                    if (entries[i].kind != 1 && entries[i].state == 1) {
                        entries[i].model->fade = func_000B9C70(entries[i].time);
                    }
                    if (entries[i].model->fade != 0.0f) {
                        entries[i].model->value_5c = entries[i].value_070;
                        entries[i].model->draw(entries[i].value_090, entries[i].value_098);
                    }
                    if (entries[i].kind != 1 && entries[i].state == 1) {
                        entries[i].model->fade = -1.0f;
                    }
                }
            }
            func_001BAA50();
            break;
        }
    }
}
