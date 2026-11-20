/* sym: ??0Object_000E6E80@@QAE@PAUNode@@HIHHH@Z = 0x000E69E0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ??1Object_000E6E80@@UAE@XZ = 0x000E6C30 */
/* sym: ?func_00011C90@Object_000E6E80@@UAEXXZ = 0x000E7470 */
/* sym: ?func_00011C90_1@Object_000E6E80@@UAEXXZ = 0x000E7540 */
/* sym: ?func_00011C80@Object_000E6E80@@UAEXH@Z = 0x000E7550 */
/* sym: ?func_00011C80_3@Object_000E6E80@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000E6E80@@UAEXH@Z = 0x000B3DE0 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Vector3 {
    float x;
    float y;
    float z;
};

// Three angles.
struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

struct Mesh_00017F60;

struct Object_00016200 {
    Mesh_00017F60 *func_00019680(const Mesh_00017F60 *mesh);
};

struct Object_00066980 {
    float func_00066950();
};

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 {
    void func_000C1F20(Angles_000C1300 *angles, Vector3 *direction, int flags);
};

struct Model_000E69E0;

// What func_00025700 (5, 7) returns: its models first.
struct Bank_000E69E0 {
    Model_000E69E0 **models;
};

// A 0x44-byte block (kind 0x3f) at 0x544.
struct Block_000E69E0 {
    int kind;
    char unknown_04[0x40];
};

extern Object_00016200 data_0022FCE8;
extern Object_00066980 data_00251F28;
extern Object_00157F10 *data_00257CE8;
extern Mesh_00017F60 data_00218E28;
extern Vector3 data_00218E40;
extern const float data_001CED98;

void *func_00025700(unsigned int index, int first, int second, int third);
void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
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

    char unknown_04[0x40];
};

// The child of Node whose table is at 0x1CEDA0 (0x5b0 bytes); slots 12, 15 hold folded thunks.
struct Object_000E6E80 : Node {
    Object_000E6E80(Node *owner, int id, unsigned int flags, int first, int second, int third);
    virtual ~Object_000E6E80();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    Vector3 origin;
    Vector3 position;
    Vector3 start;
    Vector3 previous;
    Vector3 direction;
    int value_80;
    Angles_000C1300 angles;
    Angles_000C1300 angles_90;
    int state;
    unsigned int flags_a0;
    int value_a4;
    Vector3 points[95];
    int value_51c;
    int value_520;
    int value_524;
    int time;
    int value_52c;
    float scale;
    Model_000E69E0 *models[4];
    Block_000E69E0 block;
    int value_588;
    int value_58c;
    Mesh_00017F60 *mesh;
    int stopped;
    char unknown_598[0x14];
    int handle;
};

// Starts at the position `first` points to, heading along `second` (angles from func_000C1F20), with the value `third`:
// a time from data_00251F28 (func_00066950 scaled), the point 0x218E40 turned by the angles and moved to the position
// as all 95 points of the trail, models 2, 4, 5 and 6 of bank (5, 7), block kind 0x3f and the mesh at 0x218E28.
Object_000E6E80::Object_000E6E80(Node *owner, int id, unsigned int flags, int first, int second, int third)
    : Node(owner, id, flags)
{
    previous = *(Vector3 *)first;
    start = *(Vector3 *)first;
    position = *(Vector3 *)first;
    origin = *(Vector3 *)first;
    direction = *(Vector3 *)second;
    value_80 = 0;
    data_00257CE8->func_000C1F20(&angles, (Vector3 *)second, 0x8000);
    angles_90 = angles;
    state = 0;
    flags_a0 = 0;
    value_a4 = 0;
    value_51c = 0;
    value_520 = 0;
    value_524 = 0;
    time = (int)(data_00251F28.func_00066950() * data_001CED98);
    value_52c = third;
    scale = 1.0f;
    Vector3 point;
    func_001BAA00();
    func_001BAAA0(&origin.x);
    func_001BB330(angles.y + 0x8000);
    func_001BB2E0(angles.x);
    func_001BB380(angles.z);
    func_001BAB20(&point, &data_00218E40);
    func_001BAA50();
    for (int i = 0; i < 95; i++) {
        points[i] = point;
    }
    Bank_000E69E0 *bank = (Bank_000E69E0 *)func_00025700(5, 7, 0, 0);
    models[0] = bank->models[2];
    models[1] = bank->models[4];
    models[2] = bank->models[5];
    models[3] = bank->models[6];
    memset(&block, 0, sizeof block);
    block.kind = 0x3f;
    mesh = data_0022FCE8.func_00019680(&data_00218E28);
    stopped = 0;
    value_588 = 2;
    value_58c = 1;
    handle = -1;
}
