/* sym: ?func_00011C90@Object_000C6690@@UAEXXZ = 0x000C6A90 */
struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();

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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Mesh_00017F60;

struct Object_00016200 {
    void func_00019570(Mesh_00017F60 *mesh, const Mesh_00017F60 *source);
};

extern Object_00016200 data_0022FCE8;
extern Mesh_00017F60 data_001F9120;

void func_001BA9C0();
void func_001BAA50();
void __fastcall func_001BAAA0(float *matrix);
void __fastcall func_0014C300(Vector3 *out, const Vector3 *a, const Vector3 *b);

struct Body_000C6A90 {
    Vector3 position;
    char unknown_0c[0x2c];
    Mesh_00017F60 *mesh;
};

struct Target_000C6A90 {
    char unknown_00[0x44];
    Body_000C6A90 *body;
};

// The class whose table is at 0x1CE030 (constructor func_000C6690): overrides slots 1 (C6A90) and 2 (C6B50).
struct Object_000C6690 : Node {
    virtual void func_00011C90();

    int target_id;
    Vector3 position;
    Vector3 point;
    Vector3 offset;
    int state;
    char unknown_70[4];
    unsigned int timer;

    void func_000C67A0();
};

// Slot 1: state 2 (also when the object whose id is at 0x44 is gone) unlinks this node (func_00011BE0, then
// func_00011C20 on the child). State 0 counts to 1200 (then state 2); before that it moves the target's body to
// the position at 0x48, draws data_001F9120 into its mesh under that transform (func_00019570), sets 0x54 to the
// position plus the offset at 0x60 (func_0014C300) and runs func_000C67A0.
void Object_000C6690::func_00011C90()
{
    Target_000C6A90 *target = (Target_000C6A90 *)data_0022FCE0->func_000128C0(target_id);
    if (!target)
        state = 2;
    switch (state) {
    case 0:
        if (++timer < 1200) {
            target->body->position = position;
            func_001BA9C0();
            func_001BAAA0(&position.x);
            data_0022FCE8.func_00019570(target->body->mesh, &data_001F9120);
            func_001BAA50();
            func_0014C300(&point, &position, &offset);
            func_000C67A0();
        } else {
            state = 2;
        }
        break;
    case 2:
        func_00011BE0(this);
        func_00011C20(child);
        break;
    }
}
