/* sym: ?func_000D77D0@Object_000E0440@@UAEXXZ = 0x000E1450 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// Three angles (x, y, z).
struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

struct Motion_000E1240;

// What func_0005E110 gives: a position and angles.
struct Pose_000E1240 {
    Vector3 position;
    Angles_000C1300 angles;
    Vector3 unknown_18;
};

void func_0005E110(Motion_000E1240 *motion, float time, int flags, Pose_000E1240 *out);

struct Mesh_00017F60;

struct Item_000162A0 {
    int flags;
    int value_04;
    Mesh_00017F60 *mesh;
};

struct Object_00016200 {
    void func_000162A0(Item_000162A0 *item);
    void func_00019570(Mesh_00017F60 *mesh, const Mesh_00017F60 *source);
};

extern Object_00016200 data_0022FCE8;

struct Object_0003E750 {
    void func_0003F410(int key, int value);
};

extern Object_0003E750 data_002314B0;

struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 position;
};

extern Object_000C1270 *data_00257CE4;

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 {
    void func_000C1300(Angles_000C1300 *angles, Vector3 *direction);
    void func_000C1EA0(int key);
};

extern Object_00157F10 *data_00257CE8;

void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);
float __fastcall func_0014C460(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);
void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAC50(int *angles, int order);

// The object a behaviour serves: position at 0x44, angles at 0x50, a level at 0x70 and flags at 0xa4.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
    char unknown_5c[0x14];
    float level;
    char unknown_74[0x30];
    unsigned int flags;

    int func_000C5B10(int message, void *data);
    void func_000C5B40(int id, void *position);
    void func_000C5B50(int *handle);
    int func_000C5B70(int handle);
};

struct Params_000E1450 {
    char unknown_00[8];
    float range;
};

// The base of the behaviours the factories of the table at 0x215D68 build.
struct Object_000CD1E0 {
    virtual void func_000D77D0() = 0;

    Object_000C5B50 *owner;
    int state;
};

struct Object_000E0440 : Object_000CD1E0 {
    virtual void func_000D77D0();
    void func_000E19A0();

    char unknown_00c[0x80];
    Params_000E1450 *params;
    char unknown_090[0x10];
    int step;
    char unknown_0a4[0x1c];
    Motion_000E1240 *motion;
    char unknown_0c4[0x20];
    Mesh_00017F60 *mesh;
    const Mesh_00017F60 *source;
    Item_000162A0 item;
    char unknown_0f8[0x18];
    int sound;
    char unknown_114[0x14];
    int effect_128;
    int effect_12c;
};

// The step handlers of state 4.
extern void (Object_000E0440::*data_00217E20[])();

// Slot 8: in state 4, step 0 waits for the object at data_00257CE4 to come within the range (params at 0x8c, +8) on
// the ground plane and in front of the owner (cosine above 0.7) to move on to step 1; later steps run their handler
// from 0x217E20. Then func_000E19A0; with the owner's flag 0x1000000 the owner takes the position and angles of the
// motion at 0xc0. Draws the mesh (copied again from its source) at the owner, starts the sound at 0x110 below level
// 200 (else stops it), and keeps effect 0x24 (0x128) running at the owner outside state 3, effect 0x23 (0x12c) in
// it, stopping the other one.
void Object_000E0440::func_000D77D0()
{
    if (state == 4 && step == 0) {
        Vector3 offset;
        func_0014C4C0(&offset, &owner->position, &data_00257CE4->position);
        Params_000E1450 *limit = params;
        offset.y = 0.0f;
        if (func_0014C460(&offset, &offset) < limit->range) {
            Vector3 facing;
            data_00257CE8->func_000C1300(&owner->angles, &facing);
            facing.y = 0.0f;
            func_0014C410(&facing, &facing);
            if (func_0014C800(&offset, &facing) > 0.7f) {
                step = 1;
            }
        }
    } else {
        (this->*data_00217E20[step])();
    }
    func_000E19A0();
    func_001BAA00();
    if (owner->flags & 0x1000000) {
        Pose_000E1240 pose;
        func_0005E110(motion, 0.0f, 0, &pose);
        owner->position.x = pose.position.x;
        owner->position.y = pose.position.y;
        owner->position.z = pose.position.z;
        owner->angles = pose.angles;
    }
    func_001BAAA0(&owner->position.x);
    func_001BAC50(&owner->angles.x, 0);
    data_0022FCE8.func_00019570(mesh, source);
    item.mesh = mesh;
    data_0022FCE8.func_000162A0(&item);
    if (sound != -1 && !(owner->flags & 1)) {
        if (owner->level < 200.0f) {
            data_002314B0.func_0003F410(sound, 1);
            data_00257CE8->func_000C1EA0(sound);
        } else {
            data_002314B0.func_0003F410(sound, 0);
        }
    }
    func_001BAA50();
    if (state != 3) {
        if (owner->func_000C5B70(effect_12c)) {
            owner->func_000C5B50(&effect_12c);
        }
        if (!owner->func_000C5B70(effect_128)) {
            effect_128 = owner->func_000C5B10(0x24, &owner->position);
        } else {
            owner->func_000C5B40(effect_128, &owner->position);
        }
    } else {
        if (owner->func_000C5B70(effect_128)) {
            owner->func_000C5B50(&effect_128);
        }
        if (owner->func_000C5B70(effect_12c)) {
            owner->func_000C5B40(effect_12c, &owner->position);
        } else {
            effect_12c = owner->func_000C5B10(0x23, &owner->position);
        }
    }
}
