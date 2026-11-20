/* sym: ?func_00011C90_3@Object_00050FE0@@UAEXXZ = 0x00050FF0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Node {
    Node *func_00011BD0();
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

// A camera node (table 0x1C43D8 repeats Node's slots 1 to 15; mask 7): eye, target, field of view and roll.
struct Object_00012170 : Node {
    Object_00012170(Node *owner, int id, unsigned int flags);

    Vector3 eye;
    char unknown_50[0xc];
    Vector3 target;
    char unknown_68[0xc];
    unsigned int fov;
    int unknown_78;
    int roll;
    int unknown_80;
    int left;
    int top;
    int width;
    int height;
    int unknown_94;
};

// A view: eye, target and two words (0x40 bytes).
struct View_00050860 {
    Vector3 eye;
    Vector3 target;
    int unknown_18;
    int unknown_1c;
    char unknown_20[0x20];
};

struct Path_00050860;

void func_0005DC90(const View_00050860 *view, Path_00050860 *path, float time, View_00050860 *out);
int func_0005DF50(Path_00050860 *path, float *time, float step, int flag);

void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC50(int *angles, int order);
void func_001BB650(float scale);
void func_001BB3D0();

struct Owner_00050FF0 : Node {
    char unknown_44[8];
    Vector3 position;
    int angles[3];
    int angles_64[3];
    float scale;
};

// The class whose table is at 0x1CADA8: overrides slots 5 (50FF0), 6 (51130).
struct Object_00050FE0 : Object_00012170 {
    virtual ~Object_00050FE0();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);

    Path_00050860 *path;
    float time;
};

// Slot 5: sets up the parent's frame (position +0x4c, angles +0x58 and +0x64, scale +0x70) and takes its origin as the
// target; with a path (+0x98) the eye comes from the path at the time +0x9c (func_0005DC90), which then advances,
// otherwise a default view.
void Object_00050FE0::func_00011C90_3()
{
    Owner_00050FF0 *owner = (Owner_00050FF0 *)func_00011BD0();
    func_001BAA00();
    func_001BAAA0(&owner->position.x);
    func_001BAC50(owner->angles, 0);
    func_001BB650(owner->scale);
    func_001BAC50(owner->angles_64, 0);
    Vector3 origin;
    func_001BAB20(&origin, 0);
    func_001BB3D0();
    View_00050860 view;
    view.eye.x = 0.0f;
    view.eye.y = 0.0f;
    view.eye.z = 0.0f;
    view.target.x = 0.0f;
    view.target.y = 0.0f;
    view.target.z = 1.0f;
    view.unknown_18 = 0x3555;
    view.unknown_1c = 0;
    View_00050860 result;
    if (path) {
        func_0005DC90(&view, path, time, &result);
        func_0005DF50(path, &time, 1.0f, 0);
        result.target.x = origin.x;
        result.target.y = origin.y;
        result.target.z = origin.z;
    } else {
        result = view;
    }
    func_001BAA50();
    eye.x = result.eye.x;
    eye.y = result.eye.y;
    eye.z = result.eye.z;
    target.x = result.target.x;
    target.y = result.target.y;
    target.z = result.target.z;
    fov = result.unknown_1c;
    roll = result.unknown_18;
}
