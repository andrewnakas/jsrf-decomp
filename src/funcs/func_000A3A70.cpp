struct Vector3 {
    float x;
    float y;
    float z;
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

double func_0017C61D(double value);

void func_001BAA00();
void func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

struct Node {
    Node *func_00011BD0();
};

// The camera's parent (the player): position 0xca4, angles 0xcc8, the routes from 0xe30, state 0xe58.
struct Player_000A3A70 {
    char unknown_000[0xca4];
    Vector3 position;
    char unknown_cb0[0x18];
    int angles[3];
    char unknown_cd4[0x15c];
    Path_00050860 *routes[10];
    int state;
};

struct Object_000A4D80 {
    char unknown_000[0xf4];
    float time;
    char unknown_0f8[0x10c];
    int route;
    char unknown_208[4];
    Vector3 eye;
    Vector3 target;
    int value_224;
    char unknown_228[4];
    int fov;

    void func_000A3A70();
};

// A handler of the member-function table at data_00215570: sets up the player's frame (position, angles) and takes
// the view from the player's route chosen by the value at 0x204, at the whole part of the time at 0xf4, which then
// advances by 1.2; when there is no such route, or the route ends, the player's state at 0xe58 becomes 3.
void Object_000A4D80::func_000A3A70()
{
    Player_000A3A70 *player = (Player_000A3A70 *)((Node *)this)->func_00011BD0();
    func_001BAA00();
    func_001BAAA0(&player->position.x);
    func_001BB2E0(player->angles[0]);
    func_001BB380(player->angles[2]);
    func_001BB330(player->angles[1] + 0x8000);
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
    Path_00050860 *path = player->routes[route];
    if (path) {
        func_0005DC90(&view, path, (float)func_0017C61D(time), &result);
        if (func_0005DF50(path, &time, 1.2f, 1)) {
            player->state = 3;
        }
    } else {
        result = view;
        player->state = 3;
    }
    func_001BAA50();
    eye.x = result.eye.x;
    eye.y = result.eye.y;
    eye.z = result.eye.z;
    target.x = result.target.x;
    target.y = result.target.y;
    target.z = result.target.z;
    fov = result.unknown_1c;
    value_224 = result.unknown_18;
}
