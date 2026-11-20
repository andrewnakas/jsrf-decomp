/* sym: ?func_00011C90_1@Object_000AF790@@UAEXXZ = 0x000AFA90 */
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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};
// Where func_000BAC60 places the object: position, angles, scale and a model code (bank << 10 | index).
struct Params_000BAC60 {
    Vector3 position;
    int angles[3];
    Vector3 scale;
    unsigned int model;
};

// A 0x40-byte entry (bank 6, table 5 of group 0xc): the number of records at 0xc, the key of an extra model at
// 0x34 (or -1) and a sound at 0x38.
struct Entry_000AF090 {
    char unknown_00[0xc];
    int count;
    char unknown_10[0x24];
    int extraKey;
    int sound;
    int unknown_3c;
};

// A part of the drawn shape: its place and a second point at 0x10.
struct Part_000AF860 {
    Vector3 position;
    int unknown_0c;
    Vector3 point;
};

struct Mesh_00017F60 {
    Part_000AF860 *parts;
    unsigned int count;
    float bounds[4];
};

// With an extra model: eight corner points and a centre at 0x60.
struct Mesh_000181F0 {
    Vector3 *points;
    unsigned int count;
    float bounds[4];
};

// One link of a draw item's contacts: taken while 0 at 0x0, a direction at 0x8, the next link at 0x38.
struct Link_000B2B60 {
    int taken;
    int unknown_04;
    Vector3 direction;
    char unknown_14[0x24];
    Link_000B2B60 *next;
};

// A draw-list item: flags, count, the mesh it draws and its contacts.
struct Item_000162A0 {
    unsigned int flags;
    int count;
    void *mesh;
    Link_000B2B60 *head;
    Item_000162A0 **tail;
    int unknown_14;
};

// A 0x20-byte record (bank 6, table 6): its kind (0, 2 or 7).
struct Record_000AF090 {
    int kind;
    int value;
    Vector3 shift;
    Vector3 turn;
};

struct Object_00066980 {
    float func_00066950();
};

extern Object_00066980 data_00257C80;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000A9760 {
    void func_000A9760(int index, int first, unsigned int flag, int second);
    void func_000A97C0(int index, int first, Vector3 *push);
};

struct Object_000ACD40 {
    void func_000ACCE0(int index, int first, unsigned int flag, int second);
    void func_000ACD40(int index, int first, Vector3 *push);
};

struct Object_000BCED0 {
    void func_000BCE60(int index, int first, unsigned int flag, int second);
    void func_000BCED0(int index, int first, Vector3 *push);
};

float __fastcall func_0014C6B0(const Vector3 *vector);
void __fastcall func_0014C370(Vector3 *out, const Vector3 *in, float scale);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);
void func_001BAA00();
int func_000BA800(int bank, int kind, int sound, void *position, int handle);

struct Object_00016200 {
    void func_00016320(Item_000162A0 *item);
    void func_000162A0(Item_000162A0 *item);
    void func_00017F60(Mesh_00017F60 *mesh);
    void func_000181F0(Mesh_000181F0 *mesh);
};

extern Object_00016200 data_0022FCE8;

struct Object_0006A960 {
    int func_0006AAA0(Vector3 *position, int index);
    float func_0006AC40(Vector3 *position, int index);
};

extern Object_0006A960 data_0020C6C0;

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC50(int *angles, int order);
void __fastcall func_001BB270(float *scale);

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD7B0).
struct Object_000AF790 : Node {
    virtual ~Object_000AF790();
    virtual void func_00011C90_1();

    int unknown_40;
    int unknown_44;
    int unknown_48;
    int state;
    Params_000BAC60 placement;
    Entry_000AF090 entry;
    int cell;
    float height;
    int visible;
    int ready;
    int bank;
    int handle;
    char unknown_0d0[4];
    Vector3 position;
    int angles[3];
    Vector3 size;
    Vector3 low;
    Vector3 high;
    Vector3 velocity;
    Record_000AF090 *records;
    int *ids;
    int id0;
    unsigned int count0;
    int id2;
    unsigned int count2;
    int id7;
    unsigned int count7;
    float radius;
    int alpha;
    char unknown_144[0x40];
    int unknown_184;
    int unknown_188;
    char unknown_18c[4];
    Vector3 *extra;
    Item_000162A0 firstItem;
    char unknown_1ac[0xc];
    Mesh_000181F0 firstMesh;
    Item_000162A0 secondItem;
    char unknown_1e8[0xc];
    Mesh_00017F60 secondMesh;
};

// Slot 2. In state 1 while 0xc0 and 0xc4 are set: the first free contact of the draw item (0x194 with an extra model,
// else 0x1d0) whose direction is longer than 0.01 breaks the object up: each record's piece (kinds 0, 2 and 7 go to
// the objects with ids at 0x124, 0x12c and 0x134, numbered by kind) is pushed along the direction turned by up to
// 22.5 degrees at random about each axis, at a random speed up to 2.5; then the sound at 0xb0 plays (func_000BA800)
// and the state becomes 10. Clears 0xc0 and 0xc4.
// Degrees to angle units.
inline int AngleFromDegrees(float degrees)
{
    return (int)(degrees * 182.04445f);
}

void Object_000AF790::func_00011C90_1()
{
    switch (state) {
    case 1:
        if (!visible || !ready) {
            break;
        }
        {
        Link_000B2B60 *link = (entry.extraKey != -1) ? firstItem.head : secondItem.head;
        for (; link; link = link->next) {
            if (!link->taken) {
                Vector3 *direction = &link->direction;
                if (func_0014C6B0(direction) > 0.01f) {
                    const int &sound = entry.sound;
                    int first = 0;
                    int second = 0;
                    int third = 0;
                    for (int i = 0; i < entry.count; i++) {
                        func_001BAA00();
                        func_001BB2E0(AngleFromDegrees((data_00257C80.func_00066950() - 0.5f) * 45.0f));
                        func_001BB330(AngleFromDegrees((data_00257C80.func_00066950() - 0.5f) * 45.0f));
                        func_001BB380(AngleFromDegrees((data_00257C80.func_00066950() - 0.5f) * 45.0f));
                        Vector3 push;
                        func_001BAC00(&push, direction);
                        func_001BAA50();
                        func_0014C370(&push, &push, data_00257C80.func_00066950() * 2.5f);
                        switch (records[i].kind) {
                        case 0: {
                            Object_000A9760 *object = (Object_000A9760 *)data_0022FCE0->func_000128C0(id0);
                            if (object) {
                                object->func_000A9760(first, 1, 0x20000000, 1);
                                object->func_000A97C0(first, 0, &push);
                            }
                            first++;
                            break;
                        }
                        case 2: {
                            Object_000ACD40 *object = (Object_000ACD40 *)data_0022FCE0->func_000128C0(id2);
                            if (object) {
                                object->func_000ACCE0(second, 1, 0x8000000, 1);
                                object->func_000ACD40(second, 0, &push);
                                second++;
                            }
                            break;
                        }
                        case 7: {
                            Object_000BCED0 *object = (Object_000BCED0 *)data_0022FCE0->func_000128C0(id7);
                            if (object) {
                                object->func_000BCE60(third, 1, 0x8000000, 1);
                                object->func_000BCED0(third, 0, &push);
                                third++;
                            }
                            break;
                        }
                        }
                    }
                    if (sound != -1) {
                        handle = func_000BA800(bank, 0, sound, &position, handle);
                    }
                    state = 10;
                }
                break;
            }
        }
        }
    }
    visible = 0;
    ready = 0;
}
