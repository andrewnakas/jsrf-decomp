struct Vector3 {
    float x;
    float y;
    float z;
};

struct Sphere_0005BCE0 {
    Vector3 center;
    float radius;
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *matrix);
void __fastcall func_001BAB20(Vector3 *to, const Vector3 *from);
void __fastcall func_001BAC00(Vector3 *to, const Vector3 *from);
float __fastcall func_0014C6B0(const Vector3 *vector);

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

// A frame (0x6c bytes): its matrix at +0x14, bounding sphere at +0x54.
struct Frame_000479D0 {
    int unknown_00;
    char unknown_04[0x10];
    float matrix[16];
    Vector3 center;
    float radius;
    char unknown_64[8];
};

// 1 when flag 8 is clear or the frame's bounding sphere, moved by its matrix (and with flag 0x80 its radius scaled by
// it), passes slot 39 of the device.
int func_0005BCE0(unsigned int flags, Frame_000479D0 *frame)
{
    if (flags & 8) {
        Sphere_0005BCE0 sphere;
        sphere.radius = frame->radius;
        func_001BA9C0();
        func_001BAAA0(frame->matrix);
        func_001BAB20(&sphere.center, &frame->center);
        if (flags & 0x80) {
            Vector3 extent;
            extent.x = 0.0f;
            extent.y = 0.0f;
            extent.z = sphere.radius;
            func_001BAC00(&extent, &extent);
            sphere.radius = func_0014C6B0(&extent);
        }
        func_001BAA50();
        if (!data_00251D6C->slot39(&sphere))
            return 0;
    }
    return 1;
}
