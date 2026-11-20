/* sym: ?func_000C31B0@Object_000C20A0@@UAEXXZ = 0x000C21B0 */
struct Data_000C2700;

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Pair_000C3100 {
    short first;
    short second;
};

struct Object_000607B0 {
    void func_000606C0(int key, Vector3 *value);
    void func_00060730(int key, Vector3 *value);
    void func_00060810(int key);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// A direction with a spare word (what func_0014CD50 fills).
struct Heading_000CFB70 {
    Vector3 vector;
    float w;
};

void __fastcall func_0014CD50(Vector3 *out, const Vector3 *in);

// The base whose table is at 0x1CDCF8 (constructor func_000C2420, destructor func_000C2470); slot 9 is the
// destructor.
struct Object_000C2420 {
    Object_000C2420(Data_000C2700 *data);
    virtual void func_000C2630();
    virtual void func_000C2700();
    virtual void func_000C3800();
    virtual void func_000C30C0();
    virtual void func_000C3100();
    virtual void func_000C3140();
    virtual void func_000C31B0();
    virtual void func_000C3350();
    virtual void func_000C33C0();
    virtual ~Object_000C2420();
    virtual void func_000C2480();
    virtual void func_000C36F0();
    virtual void func_000C2FE0();
    virtual void func_000C2500();
    virtual void func_000C2560();
    virtual void func_000C25D0();
    virtual int func_000C2AA0();

    void func_000C2EF0(Pair_000C3100 *pair, float *time);

    Vector3 position;
    char unknown_10[0x18];
    float speed;
    float rise;
    unsigned int flags;
    unsigned int state;
    char unknown_38[0x18];
    Vector3 point;
    char unknown_5c[0x20];
    Pair_000C3100 *pair;
    float time;
    char unknown_84[0x48];
    int handle;
};

// The class whose table is at 0x1CDC60 (constructor func_000C2010, destructor func_000C2030): overrides slots 5,
// 6, 11 and 16 of its base, and slots 14 and 15 with empty functions.
struct Object_000C20A0 : Object_000C2420 {
    Object_000C20A0(Data_000C2700 *data);
    virtual void func_000C3140();
    virtual void func_000C31B0();
    virtual ~Object_000C20A0();
    virtual void func_000C36F0();
    virtual void func_000C2560();
    virtual void func_000C25D0();
    virtual int func_000C2AA0();
};

// Overrides slot 6. Without flag 1: state 0, and the key at 0xcc goes back to node 0xe8 (func_00060810) and becomes
// -1. With it: the rise at 0x2c grows by 5/36 up to 25/27, the position moves along the point at 0x50 by the speed
// (x and z) and by the rise (y), the pair steps (func_000C2EF0), and node 0xe8 gets the new position
// (func_000606C0) and the point's direction (func_0014CD50, func_00060730) under the key.
void Object_000C20A0::func_000C31B0()
{
    if (!(flags & 1)) {
        state = 0;
        if (handle != -1) {
            Object_000607B0 *node = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
            if (node) {
                node->func_00060810(handle);
                handle = -1;
            }
        }
        return;
    }
    rise += 0.13888889f;
    if (rise >= 0.92592591f) {
        rise = 0.92592591f;
    }
    position.x += speed * point.x;
    position.y += rise;
    position.z += point.z * speed;
    func_000C2EF0(pair, &time);
    if (handle != -1) {
        Object_000607B0 *node = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (node) {
            node->func_000606C0(handle, &position);
            Heading_000CFB70 direction;
            func_0014CD50(&direction.vector, &point);
            node->func_00060730(handle, &direction.vector);
        }
    }
}
