/* sym: ?func_00011C90@Object_000D0680@@UAEXXZ = 0x000D0800 */
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

struct Motion_000E1240;

// What func_0005E110 gives.
struct Pose_000E1240 {
    Vector3 position;
    int angles[3];
    Vector3 scale;
};

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);
void func_0005E110(Motion_000E1240 *motion, float time, int flags, Pose_000E1240 *out);

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

// Slot 1: plays the motion at 0x6c (unlinking the node and its children when it ends) and takes the scale at 0x50
// from its pose; over its last 15 frames the fade at 0x54 falls by 1/30. Gives the second model the next of the
// eight frame values, turns the angle at 0x5c by 0x111 and, while the fade is above 0.3, draws the item at 0x74 with
// its mesh scaled.
void Object_000D0680::func_00011C90()
{
    if (func_0005E030(motion, &time, 0.5f, 1)) {
        func_00011BE0(this);
        func_00011C20(child);
    }
    Pose_000E1240 pose;
    func_0005E110((Motion_000E1240 *)motion, time, 0, &pose);
    scale = pose.scale.x;
    if (motion->frames - 15.0f <= time) {
        fade -= 0.033333335f;
    }
    model_64->frame->value_04 = table->values[index];
    if (++index >= 8) {
        index = 0;
    }
    angle += 0x111;
    if (fade > 0.3f) {
        float size = data_00216718.scale * scale;
        item.mesh->scale = size;
        item.mesh->part->scale = size;
        data_0022FCE8.func_000162A0(&item);
    }
}
