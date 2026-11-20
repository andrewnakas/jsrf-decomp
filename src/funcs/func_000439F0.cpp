/* sym: ?func_00011C90_6@Object_00042A30@@UAEXXZ = 0x000439F0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
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

// A camera node (as in 0x1DAA0): eye at +0x44, target at +0x5c, field of view at +0x74, roll at +0x7c.
struct Object_00012170 : Node {
    Vector3 eye;
    char unknown_50[0xc];
    Vector3 target;
    char unknown_68[0xc];
    unsigned int fov;
    int unknown_78;
    int roll;
    int unknown_80;
    char unknown_84[0x14];
};

struct Object_00011CA0 {
    void func_00011CA0();
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Stage_000439F0 {
    char unknown_000[0x8d4];
    int player;
};

struct Object_000A1C50 {
    char unknown_000[0xca4];
    Vector3 position;
    char unknown_cb0[0x18];
    int angle_cc8;
    int angle_ccc;
    int angle_cd0;
};

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
int func_00119540(int first, int second, void *data);

void func_001BAA00();
void func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

// The node class whose table is at 0x1CA630 (constructor 0x42970, destructor 0x42A30).
struct Object_00042A30 : Object_00012170 {
    virtual ~Object_00042A30();
    virtual void func_00011C90_6();

    Path_00050860 *path;
    float time;
    int started;
    unsigned int index;
};

// Slot 10 (also of the table at 0x1CA708): the first time round starts sound 10/0x17; keeps the last view
// (func_00011CA0), then with the stage's player (object 0xc's +0x8d4) sets up the player's frame and runs the path
// (+0x98) at the time +0x9c from the default view; when the path ends the node takes itself out. Without a path the
// default view. The eye, target, field of view and roll come from the result.
void Object_00042A30::func_00011C90_6()
{
    if (!started) {
        func_00119540(10, 0x17, 0);
        started = 1;
    }
    ((Object_00011CA0 *)this)->func_00011CA0();
    Stage_000439F0 *stage = (Stage_000439F0 *)data_0022FCE0->func_000128C0(0xc);
    if (!stage)
        return;
    Object_000A1C50 *player = (Object_000A1C50 *)data_0022FCE0->func_000128C0(stage->player);
    if (!player)
        return;
    func_001BAA00();
    func_001BAAA0(&player->position.x);
    func_001BB2E0(player->angle_cc8);
    func_001BB380(player->angle_cd0);
    func_001BB330(player->angle_ccc + 0x8000);
    Path_00050860 *path = this->path;
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
        if (func_0005DF50(path, &time, 1.0f, 1)) {
            func_00011BE0(this);
            func_00011C20(child);
        }
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
