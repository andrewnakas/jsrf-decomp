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
    char unknown_064[0x10];
    float shadowAlpha;
    char unknown_078[4];
    Model_00133370 *model;
    void *motion;
    char unknown_084[8];
    float time;
    float alpha;
    char unknown_094[0x10];
    int view;
    float scale;

    void func_000FD190();
};

// Entries 0 and 1 of data_0021FDC0: under a white light from straight ahead draws the model at 0x7c with its motion
// (0x80, time 0x8c), faded by the alpha at 0x90 below 1, then the shadow at 0x60 while its alpha at 0x74 is above 0;
// with bit 30 of 0x44 each is moved to the view's offset (data_0021FDD0 by player count and 0xa4) and scaled by 0xa8.
void Object_000FBFD0::func_000FD190()
{
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
    if (model) {
        if (alpha < 1.0f) {
            model->func_00047F40(func_0014C690(alpha * 255.0f) << 24 | 0xffffff);
        }
        if (bits & 0x40000000) {
            func_001BAAA0(&data_0021FDD0[data_0022FCE0->func_000127E0(0xc)][view].x);
            func_001BAAA0(model->frames->first);
            func_001BAAA0(model->frames->second);
            func_001BB230(scale, scale, scale);
            func_001BAAE0(model->frames->second);
            func_001BAAE0(model->frames->first);
        }
        model->slot5(motion, time);
        if (alpha < 1.0f) {
            model->func_00047F40(-1);
        }
    }
    if (shadow && shadowAlpha > 0.0f) {
        if (shadowAlpha < 1.0f) {
            shadow->alpha = shadowAlpha;
        }
        if (bits & 0x40000000) {
            func_001BAAA0(&data_0021FDD0[data_0022FCE0->func_000127E0(0xc)][view].x);
            func_001BAAA0(shadow->frames->first);
            func_001BAAA0(shadow->frames->second);
            func_001BB230(scale, scale, scale);
            func_001BAAE0(shadow->frames->second);
            func_001BAAE0(shadow->frames->first);
        }
        shadow->slot5(0, 0.0f);
        if (shadowAlpha < 1.0f) {
            shadow->alpha = 1.0f;
        }
    }
    data_001F93C8.func_00046A30();
}
