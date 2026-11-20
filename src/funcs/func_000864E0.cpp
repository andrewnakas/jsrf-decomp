/* sym: ?func_00011C90@Object_00086960@@UAEXXZ = 0x000864E0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *matrix);
int func_00119540(int group, int index, void *position);

struct Mesh_00017F60;

// A collision body (0x24 bytes): its kinds and its mesh.
struct Item_000162A0 {
    int kind;
    int mask;
    Mesh_00017F60 *mesh;
    char unknown_0c[0x18];
};

// The collision world (data_0022FCE8).
struct Object_00016200 {
    void func_000162A0(Item_000162A0 *item);
    void func_00019570(Mesh_00017F60 *mesh, const Mesh_00017F60 *source);
};

extern Object_00016200 data_0022FCE8;
extern Mesh_00017F60 data_0020DA78;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Object 0xe8: the effects.
struct Object_000607B0 {
    int func_000651E0(int kind, void *position, Vector3 *direction);
};

struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
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
    char unknown_34[0x10];
};

// The family of tables at 0x1CD120, 0x1CD170, 0x1CD1C0 and 0x1CD210 (constructor 0x862B0, destructor 0x86460).
struct Object_00086960 : Node {
    virtual void func_00011C90();
    virtual void func_00086940();

    Vector3 start;
    char unknown_050[0x44];
    unsigned int counter;
    unsigned int state;
    char unknown_09c[0x98];
    Item_000162A0 otherBody;
};

// Slot 1 of the tables at 0x1CD120, 0x1CD170, 0x1CD1C0 and 0x1CD210, by the state at +0x98: 0 runs slot 16; 1 places
// the second mesh at the start position (func_00019570 with 0x20DA78), starts effect 0x14 there (func_000651E0 of
// object 0xe8) and sound 10/0x15 (func_00119540) and goes on to 2; 2 queues the second body (func_000162A0) and moves
// to 3 after 0x24 frames; 3 takes the object out (func_00011BE0, func_00011C20).
void Object_00086960::func_00011C90()
{
    switch (state) {
    case 0:
        func_00086940();
        return;
    case 1: {
        state = 2;
        counter = 0;
        func_001BA9C0();
        func_001BAAA0(&start.x);
        data_0022FCE8.func_00019570(otherBody.mesh, &data_0020DA78);
        func_001BAA50();
        Object_000607B0 *effects = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (effects) {
            effects->func_000651E0(0x14, &start, 0);
        }
        func_00119540(10, 0x15, &start);
    }
    case 2:
        data_0022FCE8.func_000162A0(&otherBody);
        counter++;
        if (counter > 0x23) {
            state = 3;
        }
        return;
    case 3:
        func_00011BE0(this);
        func_00011C20(child);
        return;
    }
}
