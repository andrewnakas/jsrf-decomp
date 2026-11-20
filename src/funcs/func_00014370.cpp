/* cflags: /Oy- */
extern "C" void *memcpy(void *, const void *, unsigned int);

struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_0014C300(Vector3 *out, const Vector3 *a, const Vector3 *b);
void __fastcall func_0014C370(Vector3 *out, const Vector3 *in, float scale);
void __fastcall func_0014C3B0(Vector3 *out, const Vector3 *a, const Vector3 *b);
void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);
float __fastcall func_0014C460(Vector3 *a, const Vector3 *b);
void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *a, const Vector3 *b);
void func_001BAA00();
void __fastcall func_001BAA50();

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
    virtual void __stdcall slot28(int first, int second);
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
    virtual void __stdcall slot39();
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
    virtual void __stdcall slot71(int value);
    virtual void __stdcall slot72();
    virtual void __stdcall slot73();
    virtual void __stdcall slot74(int first, int second);
    virtual void __stdcall slot75();
    virtual void __stdcall slot76();
    virtual void __stdcall slot77();
    virtual void __stdcall slot78();
    virtual void __stdcall slot79();
    virtual void __stdcall slot80();
    virtual void __stdcall slot81(int first, int second);
};

extern Device_00251D6C *data_00251D6C;

struct Buffer_00014370 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual int __stdcall slot4(void **data, int flags);
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8(int value);
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12();
    virtual void __stdcall slot13(int count);
};

struct Object_0006E130 {
    int func_0006E130(int id);
};

extern Object_0006E130 data_00252790;
extern int data_00251D54;
extern int data_001FA1CC;
extern unsigned char data_00231D40[];

// Sets stage `stage` of the texture state at 0x251D54 when it changes.
#define SET_STAGE(cache, stage, value) \
    if (cache != (value)) { \
        cache = (value); \
        data_00251D6C->slot81(stage, (value)); \
    }

// A ring of points from `start` to `end`.
struct Trail_00014370 {
    int unknown_00;
    int start;
    int end;
    int unknown_0c;
    Vector3 *points;
};

// A vertex of the strip: 0x18 bytes.
struct Vertex_00014370 {
    Vector3 position;
    unsigned int color;
    float u;
    float v;
};

struct Object_00014280 {
    char unknown_00[0x50];
    float width;
    unsigned int capacity;
    unsigned int color;
    int texture;
    float u0;
    float v0;
    float u1;
    float v1;
    char unknown_70[0x48];
    Buffer_00014370 *buffer;

    void func_00014370(Trail_00014370 *trail);
};

// Draws the ring of points as a strip `width` wide: two vertices per point, either side of the point across its
// direction to the next one, built in the scratch block at 0x231D40 and copied into the buffer
// (the pointer that walks the block also receives the buffer's address).
void Object_00014280::func_00014370(Trail_00014370 *trail)
{
    if (trail->start == trail->end) {
        return;
    }
    Vertex_00014370 *vertex = (Vertex_00014370 *)data_00231D40;
    int current = trail->start;
    unsigned int next = current + 1;
    int span = trail->end - current;
    float length = u1 - u0;
    if (span < 0) {
        span += capacity;
    }
    float step = length / span;
    if (next >= capacity) {
        next = 0;
    }
    int i;
    for (i = 0; i <= span; i++) {
        Vector3 side;
        Vector3 *point = &trail->points[current];
        if (i < span) {
            func_0014C4C0(&side, &trail->points[next], point);
            if (func_0014C460(&side, &side) > 0.0f) {
                Vector3 normal;
                func_0014C410(&normal, point);
                func_0014C3B0(&side, &side, &normal);
                func_0014C410(&side, &side);
            } else {
                side.x = 1.0f;
                side.y = 0.0f;
                side.z = 0.0f;
            }
            float scale = width;
            func_0014C370(&side, &side, scale);
        }
        func_0014C300(&vertex->position, point, &side);
        float offset = i * step;
        vertex->u = u1 - offset;
        vertex->v = v0;
        vertex->color = color;
        vertex++;
        func_0014C4C0(&vertex->position, point, &side);
        vertex->u = u1 - offset;
        vertex->v = v1;
        vertex->color = color;
        vertex++;
        current = next;
        next++;
        if (next >= capacity) {
            next = 0;
        }
    }
    if (buffer->slot4((void **)&vertex, 0) >= 0) {
        memcpy(vertex, data_00231D40, i * 2 * sizeof(Vertex_00014370));
        buffer->slot5();
    }
    if (data_001FA1CC != 0) {
        data_001FA1CC = 0;
        data_00251D6C->slot71(0);
    }
    SET_STAGE(data_00251D54, 0, data_00252790.func_0006E130(texture));
    func_001BAA00();
    data_00251D6C->slot74(0x302, 1);
    data_00251D6C->slot28(0, -1);
    buffer->slot9();
    buffer->slot8(0);
    buffer->slot13(i * 2 - 2);
    data_00251D6C->slot74(0x302, 0x303);
    func_001BAA50();
}
