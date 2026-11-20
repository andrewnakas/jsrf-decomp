/* sym: ??1Object_000D5E60@@UAE@XZ = 0x000D5FA0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000D5E60@@UAEXXZ = 0x000D6020 */
/* sym: ?func_00011C90_1@Object_000D5E60@@UAEXXZ = 0x000D6090 */
/* sym: ?func_00011C80@Object_000D5E60@@UAEXH@Z = 0x000D6130 */
/* sym: ?func_00011C80_3@Object_000D5E60@@UAEXH@Z = 0x000D6190 */
/* sym: ?func_00011C80_4@Object_000D5E60@@UAEXH@Z = 0x000B3DE0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Angles {
    int x;
    int y;
    int z;
};

struct Vector4 {
    float x;
    float y;
    float z;
    float w;
};

struct Motion_0005F060;
struct Item_00017940;

struct Item_00016200 {
    Item_00017940 *handle;
    Item_00016200 *next;
};

// What the drawn item points at: a frame index at 0x18 and an offset at 0x2c.
struct Frame_000D5E60 {
    char unknown_00[0x18];
    int index;
    char unknown_1c[0x10];
    Vector3 offset;
};

struct Point_000D5E60 {
    Vector3 position;
    float scale;
    char unknown_10[0x14];
};

struct Mesh_00017F60 {
    Point_000D5E60 *entries;
};

struct Item_000162A0 {
    int flags;
    int value_04;
    Mesh_00017F60 *mesh;
    Frame_000D5E60 *frame;
};

struct Object_00016200 {
    void func_00016240(Item_00016200 *item);
    void func_00019570(Mesh_00017F60 *mesh, const Mesh_00017F60 *source);
    Mesh_00017F60 *func_00019680(const Mesh_00017F60 *mesh);
    int func_0001D950(void *source, int id);
    void func_000162A0(Item_000162A0 *item);
    void func_000178D0(Item_00017940 *item);
    void func_00019760(void *pointer);
};

extern Object_00016200 data_0022FCE8;
extern Mesh_00017F60 data_00216F00;

struct Object_00046670 {
    float func_000466C0(Vector3 *position, int index);
};

extern Object_00046670 data_001F93C8;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 position;

    int func_000C1160(int kind, int count, Vector3 *position);
};

extern Object_000C1270 *data_00257CE4;

void *func_00025700(unsigned int index, int first, int second, int third);
int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);
float __fastcall func_0014C530(const Vector3 *a, const Vector3 *b);
void __fastcall func_0014C730(Vector3 *target, Vector3 *direction, float scale);
void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC50(int *angles, int order);

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
    char unknown_34[0x10];
};

// What func_000D5E60 takes: a position and angles.
struct Entry_000D5E60 {
    Vector3 position;
    Angles angles;
};

// The model at 0x64: a scale at 0x5c and its slot 5 poses it.
struct Model_000D5E60 {
    virtual void func_00();
    virtual void func_04();
    virtual void func_08();
    virtual void func_0C();
    virtual void func_10();
    virtual void func_14(Motion_0005F060 *motion, float time);

    char unknown_04[0x58];
    float scale;
};

struct Source_000D5E60 {
    void *data;
};

struct Resource_000D5E60 {
    Model_000D5E60 **models;
    char unknown_04[0x14];
    Motion_0005F060 **motions;
    char unknown_1c[4];
    Source_000D5E60 *source;
};

// The class whose table is at 0x1CE5B0: a posed model at a position and angles; within 100 of the object in
// data_00257CE4 it is drawn. Slot 15 holds a folded thunk.
struct Object_000D5E60 : Node {
    Object_000D5E60(Node *owner, int id, unsigned int flags, Entry_000D5E60 *desc);
    virtual ~Object_000D5E60();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    Vector3 position;
    Angles angles;
    char unknown_5c[4];
    int delay;
    Model_000D5E60 *model;
    float scale;
    Motion_0005F060 *motion;
    float time;
    Item_00016200 link;
    Item_000162A0 item;
};

// Frees the mesh at 0x84 and the handle at 0x74 (data_0022FCE8).
Object_000D5E60::~Object_000D5E60()
{
    if (item.mesh) {
        data_0022FCE8.func_00019760(item.mesh);
    }
    if (link.handle) {
        data_0022FCE8.func_000178D0(link.handle);
    }
}
