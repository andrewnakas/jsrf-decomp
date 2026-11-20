struct Vector3 {
    float x;
    float y;
    float z;
};

struct Sphere_0005BCE0 {
    Vector3 center;
    float radius;
};

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

struct Object_00047470 {
    virtual ~Object_00047470();

    char unknown_04[0x54];
    float scale;
};

// The object in data_00257CE8.
struct Object_00157F10 {
    int func_000C1340(Object_00047470 *model, Sphere_0005BCE0 *sphere, float nearDepth, float middleDepth,
                      float farDepth);
};

// How a model's sphere (already in view space) is seen: 0 beyond farDepth or out of view (slot 39 of
// data_00251D6C); else 1 up to nearDepth, 2 below middleDepth (both with scale 1 at 0x58), or 3 with the scale
// fading from 1 at middleDepth to 0 at farDepth.
int Object_00157F10::func_000C1340(Object_00047470 *model, Sphere_0005BCE0 *sphere, float nearDepth,
                                   float middleDepth, float farDepth)
{
    float depth = sphere->center.z;
    int kind;
    if (depth > farDepth || !data_00251D6C->slot39(sphere))
        return 0;
    if (depth <= nearDepth) {
        kind = 1;
        model->scale = 1.0f;
    } else if (depth < middleDepth) {
        kind = 2;
        model->scale = 1.0f;
    } else {
        kind = 3;
        model->scale = (farDepth - depth) / (farDepth - middleDepth);
    }
    return kind;
}
