struct Vector3 {
    float x;
    float y;
    float z;
};

// The device at data_00251D6C: slot 33 takes a float.
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
    virtual void __stdcall slot33(float value);
};

struct Model_00111C60 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);
};

struct Frame_00111C60 {
    char unknown_00[0x80];
    float matrix[16];
};

struct Holder_00111C60 {
    char unknown_00[8];
    Frame_00111C60 *frame;
};

struct Object_001118F0 {
    char unknown_000[0x98];
    Holder_00111C60 *holder;
    char unknown_09c[0x10];
    Model_00111C60 *head;
    char unknown_0b0[0xc];
    Model_00111C60 *link;
    char unknown_0c0[0x68];
    float scale;
    char unknown_12c[0x44];
    int visible;
    char unknown_174[4];
    int limit;
    int count;
    Vector3 *points;

    void func_00111C60();
};

extern Device_00251D6C *data_00251D6C;

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *position);
void __fastcall func_001BAAE0(float *matrix);
void func_001BB230(float x, float y, float z);
void __fastcall func_001BB330(int angle);
int func_0014C7D0(float x, float z);

// When shown (+0x170) with points (+0x180): in the frame of the holder at +0x98 (its +8, +0x80), with slot 33 of
// the device at 0, draws the model at +0xbc at each point but the last (scaled 1.5 times +0x128), then the model at
// +0xac at the last point turned along the way to the next one (wrapping at +0x178) and scaled 0.7 times.
void Object_001118F0::func_00111C60()
{
    if (!visible || !points) {
        return;
    }
    func_001BA9C0();
    if (holder) {
        func_001BAAE0(holder->frame->matrix);
    }
    data_00251D6C->slot33(0.0f);
    for (int i = 0; i < count - 1; i++) {
        func_001BA9C0();
        func_001BAAA0(&points[i].x);
        float size = scale * 1.5f;
        func_001BB230(size, size, size);
        if (link) {
            link->slot5(0, 0);
        }
        func_001BAA50();
    }
    int next = count + 1;
    if (next >= limit) {
        next = 0;
    }
    Vector3 way;
    way.x = points[next].x - points[count].x;
    way.z = points[next].z - points[count].z;
    int angle = func_0014C7D0(way.x, way.z);
    if (head) {
        func_001BA9C0();
        func_001BAAA0(&points[count].x);
        func_001BB330(angle + 0x8000);
        float size = scale * 0.7f;
        func_001BB230(size, size, size);
        head->slot5(0, 0);
        func_001BAA50();
    }
    func_001BAA50();
}
