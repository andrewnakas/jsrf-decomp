/* sym: ?func_00011C90@Object_000BB710@@UAEXXZ = 0x000BB7B0 */
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

struct Vector3 {
    float x;
    float y;
    float z;
};

// Where func_000BAC60 places the object: position, angles, scale and a model code (bank << 10 | index).
struct Params_000BAC60 {
    Vector3 position;
    int angles[3];
    Vector3 scale;
    unsigned int model;
};


struct Sphere_00017EC0 {
    Vector3 center;
    float radius;
};

// The one part of the sphere mesh at 0x194.
struct Part_00017F60 {
    Sphere_00017EC0 sphere;
    Vector3 offset;
    char unknown_1c[8];
};

struct Mesh_00017F60 {
    Part_00017F60 *parts;
    unsigned int count;
    Sphere_00017EC0 bounds;
};

// What func_000162A0 takes: flags, kind and the mesh it stands for.
struct Item_000162A0 {
    unsigned int flags;
    int kind;
    Mesh_00017F60 *mesh;
    char unknown_0c[0x18];
};

struct Item_00016200 {
    int unknown_00;
};

// What func_0001D950 registered (0x1b0): how many touch it at 0x5c.
struct Frame_000BB7B0 {
    char unknown_00[0x5c];
    unsigned int count;
};

struct Object_00016200 {
    void func_00016240(Item_00016200 *item);
    void func_00017F60(Mesh_00017F60 *mesh);
    void func_0001D940(void **handle);
};

extern Object_00016200 data_0022FCE8;

struct Object_0006A960 {
    int func_0006AAA0(Vector3 *position, int hint);
    int func_0006AC10(int key);
};

extern Object_0006A960 data_0020C6C0;

int func_000BA800(int bank, int kind, int sound, void *position, int handle);
void func_001BA9C0();
void func_001BA8A0();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAC50(int *angles, int order);
void __fastcall func_001BAA50();

// An entry of table 7 of bank 7 (0x20 bytes, copied to 0x70): its sound at 0xc.
struct Entry_000BB4C0 {
    int unknown_00;
    int model;
    char unknown_08[4];
    int sound;
    char unknown_10[0x10];
};

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CDA60; constructor
// func_000BB4C0).
struct Object_000BB710 : Node {
    virtual void func_00011C90();

    char unknown_040[4];
    unsigned int flags_44;
    Params_000BAC60 record;
    Entry_000BB4C0 entry;
    int key;
    int set;
    int sound;
    char unknown_09c[0x30];
    Vector3 position;
    int angles[3];
    Vector3 scale;
    Vector3 center;
    Vector3 start;
    Vector3 offset;
    int alpha;
    char unknown_118[0x40];
    int value_158;
    int value_15c;
    int value_160;
    int state;
    char unknown_168[8];
    Item_000162A0 item;
    Mesh_00017F60 mesh;
    void *source;
    Frame_000BB7B0 *handle;
    Item_00016200 touch;
};

// Slot 1. State 0 places it at the record (position, angles, scale; the sphere's centre and start at the position,
// no offset, opaque), registers the sphere mesh (func_00017F60, item 0x800 kind 3), poses the handle's frame twice
// (func_0001D940) and finds its floor zone (0x90); state 1 then, while the zone is known to data_0020C6C0, sets bit
// 30 of 0x44 while something touches the frame (else clears it); states 1 and 3 pass the touch item at 0x1b4 to
// func_00016240. State 4 fades it out by 4 a step and ends in state 0; state 10 unlinks it.
void Object_000BB710::func_00011C90()
{
    switch (state) {
    case 0:
        state = 1;
        position.x = record.position.x;
        position.y = record.position.y;
        position.z = record.position.z;
        angles[0] = record.angles[0];
        angles[1] = record.angles[1];
        angles[2] = record.angles[2];
        scale.x = record.scale.x;
        scale.y = record.scale.y;
        scale.z = record.scale.z;
        center.x = record.position.x;
        center.y = record.position.y;
        center.z = record.position.z;
        start.x = record.position.x;
        start.y = record.position.y;
        start.z = record.position.z;
        offset.x = 0;
        offset.y = 0;
        offset.z = 0;
        alpha = 0xff;
        value_160 = 0;
        value_158 = 0;
        value_15c = 0;
        data_0022FCE8.func_00017F60(&mesh);
        mesh.parts->sphere.center.x = center.x;
        mesh.parts->sphere.center.y = center.y;
        mesh.parts->sphere.center.z = center.z;
        mesh.parts->offset = offset;
        item.kind = 3;
        item.flags = 0x800;
        item.mesh = &mesh;
        func_001BA9C0();
        func_001BA8A0();
        func_001BAAA0(&position.x);
        func_001BAC50(angles, 0);
        data_0022FCE8.func_0001D940((void **)handle);
        data_0022FCE8.func_0001D940((void **)handle);
        func_001BAA50();
        key = data_0020C6C0.func_0006AAA0(&position, key);
    case 1:
        if (key == -1) {
            break;
        }
        if (!data_0020C6C0.func_0006AC10(key)) {
            break;
        }
        if (handle->count > 0) {
            flags_44 |= 0x40000000;
            if (!(flags_44 & 0x40000000) && entry.sound != -1) {
                sound = func_000BA800(set, 0, entry.sound, &position, sound);
            }
        } else {
            flags_44 &= ~0x40000000;
        }
    case 3:
        data_0022FCE8.func_00016240(&touch);
        break;
    case 4:
        alpha -= 4;
        if (alpha < 0) {
            alpha = 0;
            state = 0;
        }
        break;
    case 10:
        func_00011BE0(this);
        func_00011C20(child);
        break;
    }
}
