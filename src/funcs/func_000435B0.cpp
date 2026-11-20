struct Vector3 {
    float x;
    float y;
    float z;
};

struct Sphere_000435B0 {
    Vector3 center;
    float radius;
};

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
    virtual int __stdcall slot39(const Sphere_000435B0 *sphere);
};

extern Device_00251D6C *data_00251D6C;

// The node class whose table is at 0x1CA678 (constructor 0x43C00, destructor 0x432E0). The same body is also called
// with `this` from the slot-3 functions of 0x1CA6C8 (0x445A0) and 0x1CA748 (0x44400).
struct Object_000432E0 {
    int func_000435B0(float *alpha);
};

// Called by slot 3 (0x43EC0; it does not use `this`): 0 when the origin, moved by the current matrix
// (func_001BAB20), is more than 500 deep or its sphere of radius 5 fails slot 39 of the device; otherwise 1, with
// `alpha` 1 nearer than 450 and fading by 0.02 a unit from there to 500.
int Object_000432E0::func_000435B0(float *alpha)
{
    Sphere_000435B0 sphere = {{0.0f, 0.0f, 0.0f}, 5.0f};
    func_001BAB20(&sphere.center, 0);
    if (!(sphere.center.z > 500.0f) && data_00251D6C->slot39(&sphere)) {
        if (sphere.center.z < 450.0f)
            *alpha = 1.0f;
        else
            *alpha = (500.0f - sphere.center.z) * 0.02f;
        return 1;
    }
    return 0;
}
