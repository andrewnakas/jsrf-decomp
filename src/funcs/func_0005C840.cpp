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
void func_001BAA50();
void __fastcall func_001BAAA0(float *matrix);
void __fastcall func_001BAB20(Vector3 *to, const Vector3 *from);

// A part of a frame (0x20 bytes): two words handed to the surface, its texture at +0xc, its own bounds at +0x1c.
struct Part_0005BE50 {
    int unknown_00;
    int unknown_04;
    int unknown_08;
    unsigned int texture;
    char unknown_10[0xc];
    Sphere_0005BCE0 *bounds;
};

// A frame (0x6c bytes): its word, its parts and their count, its matrix and bounding sphere.
struct Frame_000479D0 {
    int unknown_00;
    char unknown_04[8];
    Part_0005BE50 *parts;
    unsigned int count;
    float matrix[16];
    Sphere_0005BCE0 bounds;
    char unknown_64[8];
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
    virtual void __stdcall slot40();
    virtual void __stdcall slot41();
    virtual void __stdcall slot42();
    virtual void __stdcall slot43();
    virtual void __stdcall slot44();
    virtual void __stdcall slot45();
    virtual void __stdcall slot46();
    virtual void __stdcall slot47();
    virtual void __stdcall slot48();
    virtual void __stdcall slot49();
    virtual void __stdcall slot50();
    virtual void __stdcall slot51();
    virtual void __stdcall slot52();
    virtual void __stdcall slot53();
    virtual void __stdcall slot54();
    virtual void __stdcall slot55();
    virtual void __stdcall slot56();
    virtual void __stdcall slot57();
    virtual void __stdcall slot58();
    virtual void __stdcall slot59();
    virtual void __stdcall slot60();
    virtual void __stdcall slot61();
    virtual void __stdcall slot62();
    virtual void __stdcall slot63();
    virtual void __stdcall slot64();
    virtual void __stdcall slot65();
    virtual void __stdcall slot66();
    virtual void __stdcall slot67();
    virtual void __stdcall slot68();
    virtual void __stdcall slot69();
    virtual void __stdcall slot70();
    virtual void __stdcall slot71();
    virtual void __stdcall slot72();
    virtual void __stdcall slot73();
    virtual void __stdcall slot74();
    virtual void __stdcall slot75();
    virtual void __stdcall slot76();
    virtual void __stdcall slot77();
    virtual void __stdcall slot78();
    virtual void __stdcall slot79();
    virtual void __stdcall slot80();
    virtual void __stdcall slot81(int stage, int texture);
};

extern Device_00251D6C *data_00251D6C;

struct Surface_0005BE50 {
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
    virtual void __stdcall slot22(int frame, int first, int second);
};

struct Object_00047470 {
    virtual ~Object_00047470();

    Surface_0005BE50 *surface;
    char unknown_08[0x1c];
    unsigned int flags;

    int func_000476C0(unsigned int texture);
};

// Parts drawn, and the texture last given to the device.
extern int data_00251D40;
extern int data_00251D54;

// Handler 4 of 0x1FA1B0: when the device accepts the frame's bounding sphere (slot 39), loads its matrix and draws
// each part whose own bounds (when it has them) are accepted too, as handler 0 (0x5BE50) does.
void func_0005C840(Object_00047470 *object, Frame_000479D0 *frame)
{
    Sphere_0005BCE0 sphere;
    sphere.center.x = frame->bounds.center.x;
    sphere.center.y = frame->bounds.center.y;
    sphere.center.z = frame->bounds.center.z;
    sphere.radius = frame->bounds.radius;
    func_001BAB20(&sphere.center, &sphere.center);
    if (data_00251D6C->slot39(&sphere)) {
        Part_0005BE50 *part = frame->parts;
        func_001BA9C0();
        func_001BAAA0(frame->matrix);
        for (unsigned int i = 0; i < frame->count; i++, part++) {
            if (part->bounds) {
                Sphere_0005BCE0 bounds;
                bounds.center.x = part->bounds->center.x;
                bounds.center.y = part->bounds->center.y;
                bounds.center.z = part->bounds->center.z;
                bounds.radius = part->bounds->radius;
                func_001BAB20(&bounds.center, &bounds.center);
                if (!data_00251D6C->slot39(&bounds))
                    continue;
            }
            data_00251D40++;
            if (data_00251D54 != object->func_000476C0(part->texture)) {
                data_00251D54 = object->func_000476C0(part->texture);
                data_00251D6C->slot81(0, object->func_000476C0(part->texture));
            }
            object->surface->slot22(frame->unknown_00, part->unknown_00, part->unknown_04);
        }
        func_001BAA50();
    }
}
