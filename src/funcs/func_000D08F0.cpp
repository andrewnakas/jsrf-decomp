/* sym: ?func_00011C80@Object_000D0680@@UAEXH@Z = 0x000D08F0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// The part a mesh copy points to first.
struct Part_000D0680 {
    char unknown_00[0xc];
    float scale;
};

struct Mesh_00017F60 {
    Part_000D0680 *part;
    char unknown_04[0x10];
    float scale;
};

// The item at 0x74 (kind, count, mesh).
struct Item_000162A0 {
    int kind;
    int count;
    Mesh_00017F60 *mesh;
    int unknown_0c;
};

struct Object_00016200 {
    void func_000162A0(Item_000162A0 *item);
    Mesh_00017F60 *func_00019680(const Mesh_00017F60 *mesh);
    void func_00019570(Mesh_00017F60 *mesh, const Mesh_00017F60 *source);
};

extern Object_00016200 data_0022FCE8;
extern Mesh_00017F60 data_00216718;

struct Motion_0005F060 {
    short unknown_00;
    short frames;
};

// What the models at 0x60 and 0x64 point to.
struct Frame_000D0680 {
    char unknown_00[4];
    int value_04;
};

struct Sub_000D0680 {
    char unknown_00[0x60];
    float scale;
};

// The two models at 0x60 and 0x64; slot 5 draws.
struct Model_000D0680 {
    virtual void func_0();
    virtual void func_1();
    virtual void func_2();
    virtual void func_3();
    virtual void func_4();
    virtual void func_5(int first, int second);

    char unknown_04[8];
    Sub_000D0680 *sub;
    char unknown_10[0x48];
    float fade;
    char unknown_5c[4];
    Frame_000D0680 *frame;
};

// The eight frame values at 0xc.
struct Table_000D0680 {
    char unknown_00[0xc];
    int values[8];
};

// Three angles (x, y, z).
struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

struct Game {
    char unknown_0000[0x87f0];
    int value_87f0;

    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The object in data_00257CE8.
struct Object_00157F10 {
    void func_000C1F20(Angles_000C1300 *angles, Vector3 *direction, int step);
};

extern Object_00157F10 *data_00257CE8;

void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void func_001BB2B0(float scale);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);

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


// The node func_000128C0 gives for the game's 0x87f0.
struct Target_000D08F0 {
    char unknown_00[0x44];
    Vector3 position;
};

// The class whose table is at 0x1CE400 (0x98 bytes; destructor 0xD07A0): overrides slots 1 and 3 of Node; slots 12
// and 15 hold folded thunks.
struct Object_000D0680 : Node {
    Object_000D0680(Node *owner, int id, unsigned int flags, Vector3 *position);
    virtual ~Object_000D0680();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    Vector3 position;
    float scale;
    float fade;
    unsigned int index;
    int angle;
    Model_000D0680 *model_60;
    Model_000D0680 *model_64;
    Table_000D0680 *table;
    Motion_0005F060 *motion;
    float time;
    Item_000162A0 item;
    char unknown_84[0x14];
};

// Slot 3: places the matrix at the position; on pass 0xc keeps the depth of the point there at 0x10; on pass 0xd
// turns toward the node the game names at 0x87f0 (func_000C1F20), by the angle at 0x5c and the scale at 0x50, and
// draws the two models with the fade at 0x54.
void Object_000D0680::func_00011C80(int argument)
{
    func_001BAAA0(&position.x);
    switch (argument) {
    case 0xc: {
        Vector3 point;
        func_001BAB20(&point, 0);
        depth = point.z;
        break;
    }
    case 0xd: {
        Target_000D08F0 *target = (Target_000D08F0 *)data_0022FCE0->func_000128C0(data_0022FCE0->value_87f0);
        Angles_000C1300 angles = {0};
        if (target) {
            Vector3 direction;
            func_0014C4C0(&direction, &target->position, &position);
            data_00257CE8->func_000C1F20(&angles, &direction, 0x8000);
        }
        func_001BB330(angles.y + 0x8000);
        func_001BB2E0(angles.x);
        func_001BB380(angle);
        func_001BB2B0(scale);
        model_60->fade = fade;
        model_60->func_5(0, 0);
        model_64->fade = fade;
        model_64->func_5(0, 0);
        break;
    }
    }
}
