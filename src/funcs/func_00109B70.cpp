/* sym: ?func_00011C80@Object_00109B60@@UAEXH@Z = 0x00109B70 */
struct Vector3 {
    float x;
    float y;
    float z;
};

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


struct Motion_0005F060;

struct Light_00046920 {
    int unknown_00;
    unsigned int color_04;
    unsigned int color_08;
    int unknown_0c;
    Vector3 direction;
    char unknown_1c[0x24];
    unsigned int color_40;
    int unknown_44;
    unsigned int color_48;
    int unknown_4c;
    int value_50;
    char unknown_54[0x1c];
};

struct Object_00046670 {
    void func_000466D0();
    void func_00046740(Light_00046920 *light);
    void func_00046940(int enable);
    void func_00046A30();
};

extern Object_00046670 data_001F93C8;
extern Light_00046920 *data_001F963C;
void __fastcall func_001BAAA0(float *vector);
unsigned int func_0014C690(float value);
void func_001BB230(float x, float y, float z);
void __fastcall func_001BAAE0(float *matrix);
void func_001BB650(float distance);
void func_001BB670(float angle);
void func_001BA9C0();
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
    virtual void __stdcall slot28();
    virtual void __stdcall slot29();
    virtual void __stdcall slot30();
    virtual void __stdcall slot31();
    virtual void __stdcall slot32();
    virtual void __stdcall slot33(float value);
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
    virtual void __stdcall slot71();
    virtual void __stdcall slot72();
    virtual void __stdcall slot73(int value);
};
extern Device_00251D6C *data_00251D6C;
extern int data_001FA1D0;

void func_001BAA00();

struct Game {
    void *func_000128C0(int id);
    int func_000127E0(int index);
};
extern Game *data_0022FCE0;

// A frame of the model's mesh: two matrices at 0x14 and 0x54.
struct Frame_0010FA60 {
    char unknown_00[0x14];
    float first[16];
    float second[16];
};

// A model; slot 5 draws it, func_00047F40 sets its colour, 0x58 its alpha.
struct Model_00133370 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(void *motion, float time);

    void *surface;
    Frame_0010FA60 *frames;
    char unknown_0c[0x4c];
    float alpha;

    void func_00047F40(int value);
};

// The offsets of each view: four per player count.
extern Vector3 data_00220B90[][4];

// The owner: its flags at 0x16ac.
struct Owner_00109B70 {
    char unknown_0000[0x16ac];
    unsigned int flags;
};

// A direct child of Node (table 0x1D2060, constructor func_00109900, destructor func_00109B60).
struct Object_00109B60 : Node {
    virtual ~Object_00109B60();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();

    char unknown_040[4];
    Model_00133370 *models[11];
    Model_00133370 *frame;
    int order;
    char unknown_078[4];
    int index;
    int special;
    int view;
    char unknown_088[4];
    unsigned int kind;
    char unknown_090[4];
    float alpha;
    float frameAlpha;
    float grow;
    char unknown_0a0[4];
    float scale;
    Vector3 position;
    int ownerId;
};

// Slot 3: on 0, 3, 5 and 8, while the owner's flag 0x8000000 is set, draws at the position at 0xa8 under a white
// light (render state data_001FA1D0 at 1, device slot 33 at -24), moved to the view's offset (data_00220B90) when
// the scale at 0xa4 is above 1: the frame model at 0x70 and the model of the index (0x80 for kind 8, else 0x7c),
// each faded by its alpha, and for kinds 3 and 4 a copy grown by 0x9c that fades as it grows. On 2 and 7, depth 0.8.
void Object_00109B60::func_00011C80(int argument)
{
    Owner_00109B70 *owner = (Owner_00109B70 *)data_0022FCE0->func_000128C0(ownerId);
    switch (argument) {
    case 0:
    case 3:
    case 5:
    case 8: {
        if (!(owner->flags & 0x8000000)) {
            break;
        }
        int saved = data_001FA1D0;
        if (saved != 1) {
            data_001FA1D0 = 1;
            data_00251D6C->slot73(1);
        }
        data_00251D6C->slot33(-24.0f);
        func_001BAA00();
        func_001BAAA0(&position.x);
        Light_00046920 light = *data_001F963C;
        light.direction.x = 0.0f;
        light.direction.y = 0.0f;
        light.direction.z = 1.0f;
        light.value_50 = 0;
        light.color_04 = 0xffffff;
        light.color_08 = 0xffffff;
        data_001F93C8.func_000466D0();
        data_001F93C8.func_00046740(&light);
        data_001F93C8.func_00046940(0);
        if (scale > 1.0f) {
            func_001BAAA0(&data_00220B90[data_0022FCE0->func_000127E0(0xc)][view].x);
        }
        if (order >= 0 || kind == 8) {
            if (frame) {
                func_001BA9C0();
                if (frameAlpha < 1.0f) {
                    frame->func_00047F40(func_0014C690(frameAlpha * 255.0f) << 24 | 0xffffff);
                }
                if (scale > 1.0f) {
                    func_001BAAA0(frame->frames->first);
                    func_001BB230(scale, scale, scale);
                    func_001BAAE0(frame->frames->first);
                }
                frame->slot5(0, 0.0f);
                if (frameAlpha < 1.0f) {
                    frame->func_00047F40(-1);
                }
                func_001BAA50();
            }
            int i;
            if (kind != 8) {
                i = index;
            } else {
                i = special;
            }
            if (models[i]) {
                func_001BA9C0();
                if (alpha < 1.0f) {
                    models[i]->func_00047F40(func_0014C690(alpha * 255.0f) << 24 | 0xffffff);
                }
                if (scale > 1.0f) {
                    func_001BAAA0(models[i]->frames->first);
                    func_001BB230(scale, scale, scale);
                    func_001BAAE0(models[i]->frames->first);
                }
                models[i]->slot5(0, 0.0f);
                if (alpha < 1.0f) {
                    models[i]->func_00047F40(-1);
                }
                func_001BAA50();
                if (kind >= 3 && kind <= 4) {
                    data_00251D6C->slot33(-24.1f);
                    func_001BA9C0();
                    func_001BAAA0(models[i]->frames->first);
                    float size = (grow * 5.0f) * scale + 1.0f;
                    func_001BB230(size, size, scale);
                    func_001BAAE0(models[i]->frames->first);
                    if (grow < 1.0f) {
                        models[i]->func_00047F40(func_0014C690((1.0f - grow) * 255.0f) << 24 | 0xffffff);
                    }
                    models[i]->slot5(0, 0.0f);
                    if (grow < 1.0f) {
                        models[i]->func_00047F40(-1);
                    }
                    func_001BAA50();
                }
            }
        }
        data_001F93C8.func_00046A30();
        func_001BAA50();
        data_00251D6C->slot33(0.0f);
        if (data_001FA1D0 != saved) {
            data_001FA1D0 = saved;
            data_00251D6C->slot73(saved);
        }
        break;
    }
    case 2:
    case 7:
        depth = 0.8f;
        break;
    }
}
