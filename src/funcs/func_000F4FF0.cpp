/* sym: ?func_00011C80_3@Object_000F55E0@@UAEXH@Z = 0x000F4FF0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Motion_0005F060;

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

struct Sphere_0005BCE0 {
    Vector3 center;
    float radius;
};

// The frame a model is posed in: its origin at 0x54.
struct Frame_000F4FF0 {
    char unknown_00[0x54];
    Vector3 origin;
};

// A model: slot 5 draws it; its frame at 0xc, flags at 0x24, fade at 0x58.
struct Object_00047470 {
    virtual ~Object_00047470();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void draw(Motion_0005F060 *motion, float time);

    char unknown_04[8];
    Frame_000F4FF0 *frame;
    char unknown_10[0x14];
    unsigned int flags;
    char unknown_28[0x30];
    float fade;
    int value_5c;
    char unknown_60[0x14];
    int value_74;
    char unknown_78[4];
    int value_7c;
};

// The object in data_00257CE8.
struct Object_00157F10 {
    int func_000C1340(Object_00047470 *model, Sphere_0005BCE0 *sphere, float nearDepth, float middleDepth,
                      float farDepth);
};

extern Object_00157F10 *data_00257CE8;

// The object in data_00257CE4: an angle at 0xc8.
struct Object_000C1270 {
    char unknown_00[0xc8];
    int angle;
};

extern Object_000C1270 *data_00257CE4;

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
    virtual void __stdcall slot71();
    virtual void __stdcall slot72();
    virtual void __stdcall slot73();
    virtual void __stdcall slot74(int state, int value);
};

extern Device_00251D6C *data_00251D6C;

// The three depths the model is checked against (0x30, 0x34, 0x38).
struct Depths_000F4FF0 {
    char unknown_00[0x30];
    float nearDepth;
    float middleDepth;
    float farDepth;
};

// The motion set at 0x138: the motion at 0x3c.
struct MotionSet_000F4FF0 {
    char unknown_00[0x3c];
    Motion_0005F060 *motion;
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

// The child of Node whose table is at 0x1CF220 (constructor func_000F5E70, destructor func_000F60C0).
struct Object_000F55E0 : Node {
    virtual void func_00011C80_3(int argument);

    char unknown_040[8];
    Vector3 position;
    char unknown_054[4];
    int heading;
    char unknown_05c[0x1c];
    Sphere_0005BCE0 bounds;
    int value_88;
    char unknown_08c[4];
    unsigned int options;
    char unknown_094[0x74];
    int visible;
    char unknown_10c[4];
    float fade;
    char unknown_114[4];
    Depths_000F4FF0 *depths;
    char unknown_11c[0x14];
    Object_00047470 *model;
    Object_00047470 *shadow;
    MotionSet_000F4FF0 *motions;
    char unknown_13c[0x18];
    float time;
    char unknown_158[0x98];
    int value_1f0;
    int value_1f4;
};

// Slot 12 (from the node's position at 0x48): pass 7 keeps the z of the bounds' centre (0x78) taken through the
// model's frame origin as the node's depth. Pass 8 turns by the heading + 0x8000 and checks the model against the
// depths (func_000C1340, kept at 0x108): when visible, sets the model's flag 0x10 for results 1 and 2 (clears it
// otherwise), scales its fade, runs the motion set's motion at half speed on the time at 0x154 and draws the model
// (with 0x1f0 and 0x1f4 unless option bit 12 is set); for results 1 and 2 also draws the shadow at 0x134 turned by
// data_00257CE4's angle with device state 0x306 off.
void Object_000F55E0::func_00011C80_3(int argument)
{
    func_001BAAA0(&position.x);
    switch (argument) {
    case 7:
        func_001BAB20(&bounds.center, &model->frame->origin);
        depth = bounds.center.z;
        break;
    case 8:
        func_001BA9C0();
        func_001BB330(heading + 0x8000);
        visible = data_00257CE8->func_000C1340(model, &bounds, depths->nearDepth, depths->middleDepth,
                                                 depths->farDepth);
        if (!visible) {
            func_001BAA50();
            return;
        }
        if (visible == 1) {
            model->flags &= ~0x10;
            model->flags |= 0x10;
        } else if (visible == 2) {
            model->flags &= ~0x10;
            model->flags |= 0x10;
        } else {
            model->flags &= ~0x10;
        }
        model->fade = fade * model->fade;
        model->value_5c = value_88;
        func_0005E030(motions->motion, &time, 0.5f, 0);
        Object_00047470 *drawn = model;
        if (!(options & 0x1000)) {
            drawn->value_74 = value_1f0;
            drawn->value_7c = value_1f4;
        }
        drawn->draw(motions->motion, time);
        func_001BAA50();
        if (shadow && (visible == 1 || visible == 2)) {
            func_001BB330(data_00257CE4->angle);
            data_00251D6C->slot74(0x306, 0);
            shadow->draw(0, 0);
            data_00251D6C->slot74(0x302, 0x303);
        }
        break;
    }
}
