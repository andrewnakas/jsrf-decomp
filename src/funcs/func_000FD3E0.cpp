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
};
extern Device_00251D6C *data_00251D6C;

struct Game {
    int func_000127E0(int index);
};
extern Game *data_0022FCE0;

// The offsets of each view: four per player count.
extern Vector3 data_0021FDD0[][4];

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

// The class whose constructor func_000FBFD0 runs entry `mode` (at 0x58) of the member-function table at 0x21FDA8
// on itself (table 0x1D1B68).
struct Object_000FBFD0 : Node {
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    int unknown_040;
    unsigned int bits;
    float position[3];
    int kind;
    int mode;
    unsigned int flags_5c;
    Model_00133370 *shadow;
    Model_00133370 *glow;
    Model_00133370 *ring;
    void *shadowMotion;
    float shadowTime;
    float shadowAlpha;
    char unknown_078[4];
    Model_00133370 *model;
    void *motion;
    char unknown_084[8];
    float time;
    float alpha;
    int state;
    char unknown_098[0xc];
    int view;
    float scale;

    void func_000FD3E0();
};

// Entry 2 of data_0021FDC0 (pushed back 5 unless the kind at 0x54 is 8): draws the model at 0x7c faded by the alpha at
// 0x90, then by the second alpha at 0x74 the ring at 0x68 (state 6 at 0x94 fades it), the shadow at 0x60 (a raised
// copy, for kind 0x2c only in state 3 and grown as it fades, then the shadow itself scaled by 0xa8 at depth -26) and
// the glow at 0x64, each moved to the view's offset with bit 30 of 0x44; device slot 33 ends at -25.5.
void Object_000FBFD0::func_000FD3E0()
{
    func_001BA9C0();
    if (kind != 8) {
        func_001BB650(5.0f);
    }
    if (model) {
        if (alpha < 1.0f) {
            model->func_00047F40(func_0014C690(alpha * 255.0f) << 24 | 0xffffff);
        }
        func_001BA9C0();
        if (bits & 0x40000000) {
            func_001BAAA0(&data_0021FDD0[data_0022FCE0->func_000127E0(0xc)][view].x);
        }
        model->slot5(motion, time);
        func_001BAA50();
        if (alpha < 1.0f) {
            model->func_00047F40(-1);
        }
    }
    if (ring && shadowAlpha > 0.0f) {
        if (state == 6 && shadowAlpha < 1.0f) {
            ring->alpha = shadowAlpha;
        }
        func_001BA9C0();
        if (bits & 0x40000000) {
            func_001BAAA0(&data_0021FDD0[data_0022FCE0->func_000127E0(0xc)][view].x);
        }
        ring->slot5(0, 0.0f);
        func_001BAA50();
        if (state == 6) {
            ring->alpha = 1.0f;
        }
    }
    if (shadow) {
        if (0.0f < shadowAlpha && shadowAlpha < 1.0f) {
            if (shadowAlpha < 1.0f) {
                shadow->alpha = shadowAlpha;
            }
            func_001BA9C0();
            func_001BB670(0.1f);
            if (bits & 0x40000000) {
                func_001BAAA0(&data_0021FDD0[data_0022FCE0->func_000127E0(0xc)][view].x);
            }
            if (kind != 0x2c) {
                shadow->slot5(shadowMotion, shadowTime);
            } else if (state == 3) {
                float size = (3.0f - (shadowAlpha + shadowAlpha)) * scale;
                func_001BAAA0(shadow->frames->first);
                func_001BAAA0(shadow->frames->second);
                func_001BB230(size, size, size);
                func_001BAAE0(shadow->frames->second);
                func_001BAAE0(shadow->frames->first);
                shadow->slot5(0, 0.0f);
            }
            func_001BAA50();
            shadow->alpha = 1.0f;
        }
        if (shadowAlpha > 0.0f) {
            if (kind != 0x2c) {
                if (state == 6 && shadowAlpha < 1.0f) {
                    shadow->alpha = shadowAlpha;
                }
            } else if (shadowAlpha < 1.0f) {
                shadow->alpha = shadowAlpha;
            }
            func_001BA9C0();
            if (bits & 0x40000000) {
                func_001BAAA0(&data_0021FDD0[data_0022FCE0->func_000127E0(0xc)][view].x);
                func_001BAAA0(shadow->frames->first);
                func_001BAAA0(shadow->frames->second);
                func_001BB230(scale, scale, scale);
                func_001BAAE0(shadow->frames->second);
                func_001BAAE0(shadow->frames->first);
            }
            data_00251D6C->slot33(-26.0f);
            shadow->slot5(0, 0.0f);
            data_00251D6C->slot33(-25.0f);
            func_001BAA50();
            if (state == 6) {
                shadow->alpha = 1.0f;
            }
        }
    }
    data_00251D6C->slot33(-25.5f);
    if (glow && shadowAlpha > 0.0f) {
        if (shadowAlpha < 1.0f) {
            glow->func_00047F40(func_0014C690(shadowAlpha * 255.0f) << 24 | 0xffffff);
        } else {
            glow->func_00047F40(-1);
        }
        func_001BA9C0();
        if (bits & 0x40000000) {
            func_001BAAA0(&data_0021FDD0[data_0022FCE0->func_000127E0(0xc)][view].x);
        }
        glow->slot5(0, 0.0f);
        func_001BAA50();
        if (shadowAlpha < 1.0f) {
            glow->func_00047F40(-1);
        }
    }
    func_001BAA50();
}
