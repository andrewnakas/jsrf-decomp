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

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

struct Object_00047470 {
    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

void func_001BA9C0();
void func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

extern Vector3 data_002191F4[3];

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
};

// The object func_000E7F50 builds; this is a handler of the member pointers at 0x2584C8 its slot 0 (func_000EA6A0)
// runs, filled in by the dynamic initializer func_0018C000.
struct Object_000E7F50 {
    char unknown_000[4];
    Object_000C5B50 *owner;
    int state;
    char unknown_00c[4];
    int timer;
    char unknown_014[0xf0];
    int effects[3];
    char unknown_110[4];
    Object_00047470 *model;
    char unknown_118[0x10];
    void *data_128;

    void func_000E9E90();
};

// Entry 9 of the handlers at 0x2584C8: after five calls, with object 0xe8 there, poses the model at 0x114 placed and
// turned like the owner and starts kind 0x3c of object 0xe8 at each of the three points of data_002191F4 in it
// (handles at 0x104); then state 0xa.
void Object_000E7F50::func_000E9E90()
{
    if (++timer > 5) {
        Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (object) {
            func_001BA9C0();
            func_001BAAA0(&owner->position.x);
            func_001BB330(owner->angles.y + 0x8000);
            func_001BB2E0(owner->angles.x);
            func_001BB380(owner->angles.z);
            model->func_00047970(data_128, 0);
            model->func_000480C0(0);
            for (unsigned int i = 0; i < 3; i++) {
                float point[4];
                func_001BAB20((Vector3 *)point, &data_002191F4[i]);
                effects[i] = object->func_000651E0(0x3c, point, 0);
            }
            func_001BAA50();
        }
        state = 0xa;
    }
}
