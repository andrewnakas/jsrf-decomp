/* sym: ?func_000CD1E0@Object_000EA3B0@@UAEXXZ = 0x000EA6A0 */
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

struct Object_0006DB80 {
    void func_0006DFC0(int key, const Vector3 *position);
};

extern Object_0006DB80 data_00251F78;

struct Object_00047470 {
    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0x50];
    Angles_000C1300 angles;
    char unknown_5c[0x48];
    unsigned int flags;
};

// The part at 0x30 (built by func_000EB830).
struct Object_000EBB80 {
    void func_000EBB80(Object_00047470 *model);

    char unknown_00[0x6c];
};

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// The object func_000EA3B0 builds (0x1f4 bytes; table 0x1CEE78).
struct Object_000EA3B0 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000EA3B0();

    void func_000E9FE0();
    void func_000EA1B0();
    void func_000ED010();

    Object_000C5B50 *owner;
    int state;
    char unknown_00c[8];
    Vector3 position;
    char unknown_020[0x10];
    Object_000EBB80 part;
    char unknown_09c[0x78];
    Object_00047470 *model;
    char unknown_118[0x10];
    void *data_128;
    char unknown_12c[0xc0];
    int key;
};

// The class the handlers at 0x2584C8 belong to (as func_000E9D80.cpp names it); its member pointers are eight
// bytes (a function and a this adjustment), which takes a second base.
struct Link_000EA6A0 {
};

struct Object_000E7F50 : Object_000CC600, Link_000EA6A0 {
};

// The handlers slot 0 runs by the state at 0x8 (filled in by the dynamic initializer func_0018C000).
extern void (Object_000E7F50::*data_002584C8[])();

// Slot 0: runs the handler of the state and func_000ED010, places the matrix at 0x14 turned like the owner, poses
// the model at 0x114 with the data at 0x128 and draws the blocks (func_000E9FE0); unless the owner has the flag
// 0x2000000, runs func_000EA1B0, draws the part at 0x30 and, with a key at 0x1ec, hands it the point 20 below the
// model's frame 0 to data_00251F78.
void Object_000EA3B0::func_000CD1E0()
{
    (((Object_000E7F50 *)this)->*data_002584C8[state])();
    func_000ED010();
    func_001BAAA0(&position.x);
    func_001BB330(owner->angles.y + 0x8000);
    func_001BB2E0(owner->angles.x);
    func_001BB380(owner->angles.z);
    model->func_00047970(data_128, 0);
    func_000E9FE0();
    if (!(owner->flags & 0x2000000)) {
        func_000EA1B0();
        part.func_000EBB80(model);
        if (key != -1) {
            model->func_000480C0(0);
            Vector3 point;
            func_001BAB20(&point, 0);
            point.y -= 20.0f;
            data_00251F78.func_0006DFC0(key, &point);
        }
    }
}
