/* sym: ?func_00011C90@Object_000C7910@@UAEXXZ = 0x000C9280 */
struct Node {
    virtual ~Node();
    virtual void func_00011C90();

    char unknown_04[0x40];
};

// The second base (table 0x1CE1B8), two slots.
struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Angles_000C9280 {
    int x;
    int y;
    int z;
};

struct Object_00047470 {
    void func_00047970(void *motion, int frame);
};

struct Object_0003E750 {
    void func_0003F410(int handle, int on);
};

extern Object_0003E750 data_002314B0;

struct Object_000C1440 {
};

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 : Object_000C1440 {
    void func_000C1EA0(int handle);
};

extern Object_00157F10 *data_00257CE8;

// The camera object at data_00257CE4: its position at 0x7c.
struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 position;
};

extern Object_000C1270 *data_00257CE4;

// The three points turned into 0x108, 0x114 and 0x120.
extern Vector3 data_002162D0;
extern Vector3 data_002162DC;
extern Vector3 data_002162E8;

float __fastcall func_0014C530(const Vector3 *a, const Vector3 *b);
void func_001BA9C0();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAA50();

// The class whose tables are at 0x1CE1C8 (Node) and 0x1CE1C0 (Object_000C60C0 at +0x44).
struct Object_000C7910 : Node, Object_000C60C0 {
    virtual void func_00011C90();

    Vector3 position;
    Angles_000C9280 angles;
    char unknown_060[0x14];
    float distance;
    char unknown_078[0x18];
    unsigned int flags;
    char unknown_094[0x28];
    int mode;
    char unknown_0c0[0x10];
    Vector3 point;
    char unknown_0dc[0x2c];
    Vector3 ends[3];
    char unknown_12c[0x10];
    int value_13c;
    char unknown_140[0x44];
    Object_00047470 *model;
    char unknown_188[0x14];
    void *first;
    char unknown_1a0[0x1c];
    int state;
    char unknown_1c0[0x1f8];
    int sound;
    char unknown_3bc[8];
    void (Object_000C7910::**moves)();

    void func_000C8D30();
    void func_000C9420();
    void func_000C9BB0();
    void func_000CAC10();
};

// Each frame: the distance to the camera at 0x74, the move handler for the mode at 0xbc (table at 0x3c4) and the
// motion state machine (func_000CAC10), the base frame step unless the state is 4, and 0x13c cleared to -1 outside
// mode 0x17. Unless flag 0x2000 is set: func_000C8D30, then on a fresh matrix moved to 0xd0 and turned by the angles
// (y + 0x8000 first; with flag 0x2000000 outside mode 0x17 also turning the three points into 0x108-0x120) the model
// is posed with the motion at 0x19c and drawn (func_000C9420, or func_000C9BB0 in mode 0x17). The sound at 0x3b8, when
// there is one and flags 0x1001 are clear, is switched on with flag 0x8000 within 100 of the camera (and handed to
// func_000C1EA0), else off.
void Object_000C7910::func_00011C90()
{
    distance = func_0014C530(&position, &data_00257CE4->position);
    (this->*moves[mode])();
    func_000CAC10();
    if (state != 4) {
        Node::func_00011C90();
    }
    if (value_13c >= 0 && mode != 0x17) {
        value_13c = -1;
    }
    if (flags & 0x2000) {
        return;
    }
    func_000C8D30();
    func_001BA9C0();
    func_001BAAA0(&point.x);
    func_001BB330(angles.y + 0x8000);
    if (mode != 0x17) {
        if (flags & 0x2000000) {
            func_001BB2E0(angles.x);
            func_001BB380(angles.z);
            func_001BAB20(&ends[0], &data_002162D0);
            func_001BAB20(&ends[1], &data_002162DC);
            func_001BAB20(&ends[2], &data_002162E8);
        }
        model->func_00047970(first, 0);
        func_000C9420();
    } else {
        func_001BB2E0(angles.x);
        func_001BB380(angles.z);
        model->func_00047970(first, 0);
        func_000C9BB0();
    }
    if (sound != -1 && !(flags & 0x1001)) {
        if ((flags & 0x8000) && distance < 100.0f) {
            data_002314B0.func_0003F410(sound, 1);
            data_00257CE8->func_000C1EA0(sound);
        } else {
            data_002314B0.func_0003F410(sound, 0);
        }
    }
    func_001BAA50();
}
