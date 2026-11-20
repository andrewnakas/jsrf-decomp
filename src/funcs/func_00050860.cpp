/* sym: ?func_00011C90@Object_00050850@@UAEXXZ = 0x00050860 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// A camera view (0x40 bytes).
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
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

struct Game {
    void *func_000128C0(int id);
    int func_000127E0(int index);
};

extern Game *data_0022FCE0;

struct Node {
    virtual ~Node();
    virtual void func_00011C90();

    char unknown_04[0x40];
};

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

// Object 0x12ac: the ids at +0x88c (with their count) and the slots they stand for at +0x894.
struct Object_0004FC40 {
    char unknown_000[0x88c];
    int *ids;
    unsigned int count;
    int *slots;
};

// Objects 0xc and on: the object they hold at +0x8d4.
struct Member_000504E0 {
    char unknown_000[0x8d4];
    int holder;
};

// What a member holds: where it is (+0xca4), its angles (+0xcc8) and the camera path it brings (+0xe28).
struct Holder_000504E0 {
    char unknown_000[0xca4];
    Vector3 position;
    char unknown_cb0[0x18];
    int angle_cc8;
    int angle_ccc;
    int angle_cd0;
    char unknown_cd4[0x154];
    Path_00050860 *path;
};

// The camera node class whose table is at 0x1CAC60.
struct Object_00050850 : Object_00012170 {
    virtual void func_00011C90();

    int found;
    float time;
};

// Slot 1: for every slot of object 0x12ac whose id is the game's value 0x1ac and whose member (object slot + 0xc)
// holds something, notes it (+0x98) and takes the view along that one's path (+0xe28, at the time +0x9c, stepped by
// 1 and looping) from where it is and how it is turned, or the default view without a path. The eye, target, field of
// view and roll come from the result.
void Object_00050850::func_00011C90()
{
    Object_0004FC40 *list = (Object_0004FC40 *)data_0022FCE0->func_000128C0(0x12ac);
    int current = data_0022FCE0->func_000127E0(0x1ac);
    found = 0;
    if (!list) {
        return;
    }
    for (unsigned int i = 0; i < list->count; i++) {
        if (list->ids[i] != current) {
            continue;
        }
        Member_000504E0 *member = (Member_000504E0 *)data_0022FCE0->func_000128C0(list->slots[i] + 0xc);
        if (!member) {
            continue;
        }
        int held = member->holder;
        Holder_000504E0 *holder = (Holder_000504E0 *)data_0022FCE0->func_000128C0(held);
        if (!holder) {
            continue;
        }
        found = 1;
        func_001BAA00();
        func_001BAAA0(&holder->position.x);
        func_001BB2E0(holder->angle_cc8);
        func_001BB380(holder->angle_cd0);
        func_001BB330(holder->angle_ccc + 0x8000);
        Path_00050860 *path = holder->path;
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
            func_0005DF50(path, &time, 1.0f, 1);
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
}
