/* sym: ?func_00011C80@Object_000EAD20@@UAEXH@Z = 0x000EAE40 */
struct Vector3 {
    float x;
    float y;
    float z;
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
    virtual void __stdcall slot74(int source, int destination);
    virtual void __stdcall slot75();
    virtual void __stdcall slot76();
    virtual void __stdcall slot77();
    virtual void __stdcall slot78();
    virtual void __stdcall slot79();
    virtual void __stdcall slot80();
    virtual void __stdcall slot81(int stage, int texture);
};

extern Device_00251D6C *data_00251D6C;

// The shader object at 0x548 of data_00251D7C.
struct Shader_000EAE40 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual int __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5(int index, float *values, int count);
};

struct Context_00251D7C {
    char unknown_000[0x548];
    Shader_000EAE40 *shader;
};

extern Context_00251D7C *data_00251D7C;

// Whether the device state needs resetting before the next draw, and the texture last given to the device.
extern int data_001FA1CC;
extern int data_00251D54;

struct Surface_000EAE40 {
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
    virtual void __stdcall slot16(int frame);
};

struct Part_000EAE40 {
    char unknown_00[0xc];
    unsigned int texture;
};

struct Frame_000EAE40 {
    int frame;
    char unknown_04[0x8];
    Part_000EAE40 *part;
};

struct Object_00047470 {
    virtual ~Object_00047470();

    Surface_000EAE40 *surface;
    Frame_000EAE40 *frame;

    int func_000476C0(unsigned int texture);
};

void __fastcall func_001BAAA0(float *vector);

struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C90_5();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C90_9();
    virtual void func_00011C80_4(int argument);

    unsigned int flags;
    int id;
    unsigned int mask;
    float depth;
    int sortKey;
    char unknown_18[0xc];
    Node *parent;
    Node *child;
    Node *previous;
    Node *next;
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};

// The class whose table is at 0x1CEE90 (0x84 bytes; built by func_000EB160): overrides slots 1, 3 of Node; slots 12,
// 15 hold folded thunks.
struct Object_000EAD20 : Node {
    virtual ~Object_000EAD20();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_40[4];
    Vector3 position;
    float time;
    float alpha;
    char unknown_58[4];
    Object_00047470 *object;
};

// Slot 3: in pass 11, with the shader of data_00251D7C, draws the object at 0x5c at the position: shader constants
// 0 (0, 0, 0, the time at 0x50), 1 (1, 1, 1, the alpha at 0x54), 2 and 6, additive blending (device slot 74 0x302
// / 1) while the frame is drawn with its texture (slot 81 when it changed), then the usual blending (0x302 / 0x303).
void Object_000EAD20::func_00011C80(int pass)
{
    if (pass == 11) {
        Shader_000EAE40 *shader = data_00251D7C->shader;
        if (data_001FA1CC) {
            data_001FA1CC = 0;
            data_00251D6C->slot71(0);
        }
        func_001BAAA0(&position.x);
        if (shader->slot3() >= 0) {
            float low[4];
            float high[4];
            low[0] = 0.0f;
            low[1] = 0.0f;
            low[2] = 0.0f;
            low[3] = time;
            high[0] = 1.0f;
            high[1] = 1.0f;
            high[2] = 1.0f;
            high[3] = alpha;
            shader->slot5(0, low, 1);
            shader->slot5(1, high, 1);
            shader->slot5(2, 0, 2);
            shader->slot5(6, 0, 3);
            data_00251D6C->slot74(0x302, 1);
            if (data_00251D54 != object->func_000476C0(object->frame->part->texture)) {
                data_00251D54 = object->func_000476C0(object->frame->part->texture);
                data_00251D6C->slot81(0, object->func_000476C0(object->frame->part->texture));
            }
            object->surface->slot16(object->frame->frame);
            data_00251D6C->slot74(0x302, 0x303);
            shader->slot4();
        }
    }
}
