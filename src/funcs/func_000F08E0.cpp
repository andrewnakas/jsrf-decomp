/* sym: ??0Object_000F08E0@@QAE@PAUNode@@HIPAUEntry_000F08E0@@@Z = 0x000F08E0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ??1Object_000F08E0@@UAE@XZ = 0x000F0A40 */
/* sym: ?func_00011C90@Object_000F08E0@@UAEXXZ = 0x000F0AC0 */
/* sym: ?func_00011C80@Object_000F08E0@@UAEXH@Z = 0x000F0B00 */
/* sym: ?func_00011C80_3@Object_000F08E0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000F08E0@@UAEXH@Z = 0x000B3DE0 */
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

    Node(Node *parent, int id, unsigned int mask);

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

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

struct Object_00046670 {
    float func_000466C0(Vector3 *position, int index);
};

extern Object_00046670 data_001F93C8;

struct Motion_0005F060;

// A model from func_00025700 (5, 0x15): slot 5 poses it with a motion, slot 6 with another model; a value at 0x5c.
struct Model_000F08E0 {
    virtual void func_00();

    char unknown_04[0x58];
    float value;
    char unknown_60[0x14];
    float value_74;
    char unknown_78[4];
    float value_7c;
};

// Two motions.
struct Pair_000F0AC0 {
    Motion_0005F060 *first;
    Motion_0005F060 *second;
};

// What func_00025700 (5, 0x15) gives: its models (+0x0) and motions (+0x18).
struct Resource_000F08E0 {
    Model_000F08E0 **models;
    char unknown_04[0x14];
    Pair_000F0AC0 *motions;
};

void *func_00025700(unsigned int index, int first, int second, int third);
void func_001BA9C0();
void func_001BAA00();
void func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

extern Vector3 data_0021A9B0;
extern Vector3 data_0021A9BC;

// What func_000F08E0 takes: a position and angles.
struct Entry_000F08E0 {
    Vector3 position;
    Angles angles;
};

// A direct child of Node (table 0x1CEFE8, made by func_000F0C30): the position at 0x44, the angles at 0x50, six
// models at 0x5c drawn with the value at 0x60, two motions at 0x64 with their times, two effect keys at 0x70.
struct Object_000F08E0 : Node {
    Object_000F08E0(Node *parent, int id, unsigned int mask, Entry_000F08E0 *entry);
    virtual ~Object_000F08E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    int unknown_40;
    Vector3 position;
    Angles angles;
    Model_000F08E0 **models;
    float value;
    Pair_000F0AC0 *motions;
    float firstTime;
    float secondTime;
    int firstKey;
    int secondKey;
};

// Takes the position and angles, the models and motions of resource 5/0x15 (model 3 gets 300 at 0x74 and 1 at 0x7c),
// two effects of object 0xe8 (0x80 and 0x81, at the points data_0021A9B0 and data_0021A9BC from the position) and the
// value data_001F93C8 gives at the position.
Object_000F08E0::Object_000F08E0(Node *parent, int id, unsigned int mask, Entry_000F08E0 *entry)
    : Node(parent, id, mask)
{
    position = entry->position;
    angles = entry->angles;
    Resource_000F08E0 *resource = (Resource_000F08E0 *)func_00025700(5, 0x15, 0, 0);
    models = resource->models;
    motions = resource->motions;
    secondTime = 0.0f;
    firstTime = 0.0f;
    Model_000F08E0 *model = models[3];
    model->value_74 = 300.0f;
    model->value_7c = 1.0f;
    Object_000607B0 *target = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (target) {
        Vector3 point;
        func_001BAA00();
        func_001BAAA0(&position.x);
        func_001BA9C0();
        func_001BAB20(&point, &data_0021A9B0);
        firstKey = target->func_000651E0(0x80, &point, 0);
        func_001BAA50();
        func_001BAB20(&point, &data_0021A9BC);
        secondKey = target->func_000651E0(0x81, &point, 0);
        func_001BAA50();
    }
    value = data_001F93C8.func_000466C0(&position, -1);
}
