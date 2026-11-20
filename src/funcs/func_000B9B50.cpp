struct Vector3 {
    float x;
    float y;
    float z;
};

struct Sphere_000B9B50 {
    Vector3 center;
    float radius;
};

// The device in data_00251D6C: slot 39 tells whether a sphere can be seen.
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
    virtual int __stdcall slot39(const Sphere_000B9B50 *sphere);
};

extern Device_00251D6C *data_00251D6C;

void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
float func_0014C7F0(float value);

// A part of the model: its bounding sphere at 0x54.
struct Part_000B9B50 {
    char unknown_00[0x54];
    Sphere_000B9B50 bounds;
};

// The model: the parts at 0x8 and 0xc.
struct Model_00101A70 {
    char unknown_00[8];
    Part_000B9B50 *second;
    Part_000B9B50 *first;
};

unsigned int func_000B9B50(Model_00101A70 *model, float *depth);

// Takes the bounding sphere of the model's part at 0xc (else the one at 0x8), moves its centre into view space
// (func_001BAB20) and stores the depth. 3 when the device does not see the sphere (slot 39); else 0 up to a depth of
// 400, 1 below 500, 2 beyond 500, and at 500 exactly the depth is made positive (func_0014C7F0) and the answer is 3.
unsigned int func_000B9B50(Model_00101A70 *model, float *depth)
{
    Sphere_000B9B50 sphere;
    Part_000B9B50 *part = model->first;
    if (part || (part = model->second)) {
        sphere = part->bounds;
    }
    func_001BAB20(&sphere.center, &sphere.center);
    *depth = sphere.center.z;
    if (data_00251D6C->slot39(&sphere)) {
        if (*depth <= 400.0f) {
            return 0;
        }
        if (*depth < 500.0f) {
            return 1;
        }
        if (*depth > 500.0f) {
            return 2;
        }
        *depth = func_0014C7F0(*depth);
    }
    return 3;
}
