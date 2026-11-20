/* sym: ?func_00011C90@Object_000CE9D0@@UAEXXZ = 0x000CDAC0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_00047470 {
    void func_00047970(void *motion, int frame);
    void func_000480C0(unsigned int flags);
};

// The models of a behaviour: the body first.
struct Models_000CDAC0 {
    Object_00047470 *body;
};

struct Object_000C1440 {
};

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 : Object_000C1440 {
    int func_000C1D40(int *effect, int *second, int *third);
};

extern Object_00157F10 *data_00257CE8;

// The object a behaviour serves: flags at 0xa4, its position at 0x44, its turn at 0x54 and a key at 0x9c.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    int unknown_50;
    int angle;
    char unknown_58[0x44];
    int key;
    char unknown_a0[4];
    unsigned int flags;

    void func_000C5AD0(int on);
    int func_000C5B10(int kind, void *data);
};

struct Object_0006DB80 {
    void func_0006DFC0(int sound, const Vector3 *position);
};

extern Object_0006DB80 data_00251F78;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    void func_000606C0(int key, Vector3 *point);
    void func_00060730(int key, Vector3 *direction);
};

// The point the shot leaves from, in the body's frame.
extern Vector3 data_002165D4;

void func_000FEC30(int key, const Vector3 *position);
void func_001BA9C0();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB330(int angle);
void func_001BB2B0(float scale);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAA50();

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual ~Object_000CC600() {}
};

// The behaviour func_000CE9D0 builds (0x140 bytes, table 0x1CE3A0); 0x4 holds the object it serves.
struct Object_000CE9D0 : Object_000CC600 {
    virtual void func_00011C90();

    Object_000C5B50 *owner;
    int state;
    char unknown_0c[4];
    int value_10;
    char unknown_14[0x44];
    Models_000CDAC0 *models;
    char unknown_5c[0x1c];
    void *frame;
    char unknown_7c[0x94];
    int effect;
    float level;
    int value_118;
    int sound;
    int fresh;
    char unknown_124[0x10];
    int key;
    int burst;
    unsigned int bursts;
};

// Slot 1 (the frame), unless the owner's flag 0x8000000 is set: once the effect at 0x110 is over (func_000C1D40) sets
// that flag, state 0x1b, clears 0x10, switches the owner on (func_000C5AD0) and marks the sound for a restart (0x120);
// otherwise func_000FEC30 of the owner's key and position, and as the level at 0x114 passes 0.7, 0.4 and 0.1 the owner
// starts effects 0x47 / 0x48 / 0x47 (up to three in all, counted at 0x13c; the first kept at 0x138). With a sound at
// 0x11c, plays it at the body's origin (posed at the owner, func_0006DFC0); with a key at 0x134 tells object 0xe8 the
// point data_002165D4 and the direction (0, 0, -1) in the body's frame.
void Object_000CE9D0::func_00011C90()
{
    if (owner->flags & 0x8000000) {
        return;
    }
    if (data_00257CE8->func_000C1D40(&effect, &value_118, (int *)&level)) {
        owner->flags |= 0x8000000;
        state = 0x1b;
        value_10 = 0;
        owner->func_000C5AD0(1);
        fresh = 1;
    } else {
        func_000FEC30(owner->key, &owner->position);
        if (level > 0.7f && bursts < 3) {
            bursts++;
            burst = owner->func_000C5B10(0x47, &owner->position);
        } else if (level > 0.4f && bursts < 2) {
            bursts++;
            owner->func_000C5B10(0x48, &owner->position);
        } else if (level > 0.1f && bursts < 1) {
            bursts++;
            owner->func_000C5B10(0x47, &owner->position);
        }
    }
    if (sound != -1) {
        Vector3 origin;
        func_001BA9C0();
        func_001BAAA0(&owner->position.x);
        func_001BB330(owner->angle + 0x8000);
        func_001BB2B0(2.0f);
        models->body->func_00047970(frame, 0);
        models->body->func_000480C0(9);
        func_001BAB20(&origin, 0);
        func_001BAA50();
        data_00251F78.func_0006DFC0(sound, &origin);
    }
    if (key >= 0) {
        Vector3 direction;
        direction.x = 0.0f;
        direction.y = 0.0f;
        direction.z = -1.0f;
        func_001BA9C0();
        models->body->func_000480C0(8);
        Vector3 point;
        func_001BAB20(&point, &data_002165D4);
        func_001BAC00(&direction, &direction);
        func_001BAA50();
        Object_000607B0 *target = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (target) {
            target->func_000606C0(key, &point);
            target->func_00060730(key, &direction);
        }
    }
}
