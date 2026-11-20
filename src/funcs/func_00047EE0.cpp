struct Vector3 {
    float x;
    float y;
    float z;
};

struct Sphere_00047EE0 {
    Vector3 center;
    float radius;
};

void __fastcall func_001BAAA0(float *matrix);
void __fastcall func_001BAB20(Vector3 *to, const Vector3 *from);

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
    virtual int __stdcall slot39(const Sphere_00047EE0 *sphere);
};

extern Device_00251D6C *data_00251D6C;

// A frame (0x6c bytes): its matrix at +0x14, bounding sphere at +0x54.
struct Frame_000479D0 {
    int unknown_00;
    char unknown_04[0x10];
    float matrix[16];
    Sphere_00047EE0 bounds;
    char unknown_64[8];
};

struct Object_00047470 {
    virtual ~Object_00047470();

    void *surface;
    Frame_000479D0 *frames;
    Frame_000479D0 *frame;

    void func_00047EE0();
};

// Passes the bounding sphere of the frame at +0xc (else the first frame), moved by the frame's matrix
// (func_001BAAA0, func_001BAB20), to slot 39 of the device.
void Object_00047470::func_00047EE0()
{
    Frame_000479D0 *chosen = frame;
    if (!chosen)
        chosen = frames;
    Sphere_00047EE0 sphere;
    sphere.center.x = chosen->bounds.center.x;
    sphere.center.y = chosen->bounds.center.y;
    sphere.center.z = chosen->bounds.center.z;
    sphere.radius = chosen->bounds.radius;
    func_001BAAA0(chosen->matrix);
    func_001BAB20(&sphere.center, &sphere.center);
    data_00251D6C->slot39(&sphere);
}
