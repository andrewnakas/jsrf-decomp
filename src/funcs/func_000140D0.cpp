struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

struct Game {
    char unknown_0000[0x87f0];
    int frame;
};

extern Game *data_0022FCE0;

// A sphere in view space for the device's visibility test.
struct Sphere_000140D0 {
    Vector3 center;
    float radius;
};

// The Direct3D device.
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
    virtual int __stdcall slot39(const Sphere_000140D0 *sphere);
};

extern Device_00251D6C *data_00251D6C;

// One trail: the frame it was made in and its points.
struct Trail_00014370 {
    int frame;
    int start;
    int end;
    int last;
    Vector3 *points;
};

// The trail drawer (table 0x1C4500, constructor 0x141E0, destructor 0x14280): its place and size, then up to eight
// live trails at +0x70 (count at +0xb0) and eight fading ones at +0x90.
struct Object_00014280 {
    char unknown_00[0x44];
    Vector3 position;
    float radius;
    unsigned int length;
    char unknown_58[0x18];
    Trail_00014370 *trails[8];
    Trail_00014370 *others[8];
    unsigned int trailCount;
    unsigned int otherCount;
    void *buffer;
    int enabled;

    void func_000140D0();
};

// When enabled and its sphere is in view, adds its place (moved by the current matrix) as the latest point of the
// trail made in the current frame, or starts a new trail (up to eight) with room for +0x54 points.
void Object_00014280::func_000140D0()
{
    if (enabled) {
        Sphere_000140D0 sphere;
        sphere.radius = radius;
        func_001BAB20(&sphere.center, &position);
        if (data_00251D6C->slot39(&sphere)) {
            for (unsigned int i = 0; i < trailCount; i++) {
                if (trails[i]->frame == data_0022FCE0->frame) {
                    Trail_00014370 *trail = trails[i];
                    func_001BAB20(&trail->points[trail->end], &position);
                    trail->last = trail->end;
                    return;
                }
            }
            if (trailCount < 8) {
                Trail_00014370 *trail = new Trail_00014370;
                trails[trailCount] = trail;
                trail->frame = data_0022FCE0->frame;
                trail->start = 0;
                trail->end = 0;
                trail->points = new Vector3[length];
                trail->last = 0;
                func_001BAB20(&trail->points[trail->end], &position);
                trailCount++;
            }
        }
    }
}
