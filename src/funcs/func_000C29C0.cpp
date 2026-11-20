struct Vector3 {
    float x;
    float y;
    float z;
};

struct Sphere_0005BCE0 {
    Vector3 center;
    float radius;
};

void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
float func_0014C7F0(float value);

struct Device_00251D6C {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8();
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12();
    virtual void __stdcall slot13();
    virtual void __stdcall slot14();
    virtual void __stdcall slot15();
    virtual void __stdcall slot16();
    virtual void __stdcall slot17();
    virtual void __stdcall slot18();
    virtual void __stdcall slot19();
    virtual void __stdcall slot20();
    virtual void __stdcall slot21();
    virtual void __stdcall slot22();
    virtual void __stdcall slot23();
    virtual void __stdcall slot24();
    virtual void __stdcall slot25();
    virtual void __stdcall slot26();
    virtual void __stdcall slot27();
    virtual void __stdcall slot28();
    virtual void __stdcall slot29();
    virtual void __stdcall slot30();
    virtual void __stdcall slot31();
    virtual void __stdcall slot32();
    virtual void __stdcall slot33();
    virtual void __stdcall slot34();
    virtual void __stdcall slot35();
    virtual void __stdcall slot36();
    virtual void __stdcall slot37();
    virtual void __stdcall slot38();
    virtual int __stdcall slot39(const Sphere_0005BCE0 *sphere);
};

extern Device_00251D6C *data_00251D6C;

// The frame at 0xc of a model: its bounding sphere at 0x54.
struct Frame_000C29C0 {
    char unknown_00[0x54];
    Sphere_0005BCE0 bounds;
};

struct Object_00047470 {
    virtual ~Object_00047470();

    char unknown_04[8];
    Frame_000C29C0 *frame;
};

// The base whose table is at 0x1CDCF8 (constructor func_000C2420, destructor func_000C2470).
struct Object_000C2420 {
    virtual void func_000C2630();

    char unknown_04[0x2c];
    unsigned int flags;
    char unknown_34[0x14];
    float depth;

    int func_000C29C0(Object_00047470 *model);
};

// The model's bounding sphere seen from the camera: its depth (func_0014C7F0 of the transformed centre's z) goes
// to 0x48, and flag 0x10 is set (clearing flag 1) the first time. Within 400 and visible (slot 39 of
// data_00251D6C), sets flag 1 and returns 1 up to 15, 2 below 300, else 3; otherwise 0.
int Object_000C2420::func_000C29C0(Object_00047470 *model)
{
    Sphere_0005BCE0 sphere;
    sphere = model->frame->bounds;
    int kind = 0;
    func_001BAB20(&sphere.center, &sphere.center);
    depth = func_0014C7F0(sphere.center.z);
    if (!(flags & 0x10))
        flags = flags & ~1 | 0x10;
    if (depth < 400.0f && data_00251D6C->slot39(&sphere)) {
        flags |= 1;
        if (depth <= 15.0f)
            kind = 1;
        else if (depth < 300.0f)
            kind = 2;
        else
            kind = 3;
    }
    return kind;
}
