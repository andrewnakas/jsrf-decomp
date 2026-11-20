/* sym: ?func_00011C80@Object_00104EE0@@UAEXH@Z = 0x00105070 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Node {
    Node *func_00011BD0();
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
    virtual void __stdcall slot31(unsigned int value, float first, float second);
    virtual void __stdcall slot32();
    virtual void __stdcall slot33(float value);
    virtual void __stdcall slot34();
    virtual void __stdcall slot35();
    virtual void __stdcall slot36(float *screen, Vector3 *point);
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
    virtual void __stdcall slot74();
    virtual void __stdcall slot75();
    virtual void __stdcall slot76();
    virtual void __stdcall slot77();
    virtual void __stdcall slot78();
    virtual void __stdcall slot79();
    virtual void __stdcall slot80();
    virtual void __stdcall slot81();
    virtual void __stdcall slot82();
    virtual void __stdcall slot83();
    virtual void __stdcall slot84();
    virtual void __stdcall slot85();
    virtual void __stdcall slot86();
    virtual void __stdcall slot87();
    virtual void __stdcall slot88();
    virtual void __stdcall slot89();
    virtual void __stdcall slot90();
    virtual void __stdcall slot91();
    virtual void __stdcall slot92();
    virtual void __stdcall slot93();
    virtual void __stdcall slot94();
    virtual void __stdcall slot95();
    virtual void __stdcall slot96();
    virtual void __stdcall slot97();
    virtual void __stdcall slot98();
    virtual void __stdcall slot99();
    virtual void __stdcall slot100();
    virtual void __stdcall slot101();
    virtual void __stdcall slot102();
    virtual void __stdcall slot103();
    virtual void __stdcall slot104();
    virtual void __stdcall slot105();
    virtual void __stdcall slot106();
    virtual void __stdcall slot107();
    virtual void __stdcall slot108();
    virtual void __stdcall slot109();
    virtual void __stdcall slot110(unsigned int stage, int kind, unsigned int value);
    virtual void __stdcall slot111(unsigned int stage, int kind, unsigned int *value);
};

extern Device_00251D6C *data_00251D6C;

void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAA50();


void func_001BAA00();
void __fastcall func_001BAF70(Vector3 *eye, Vector3 *target, int roll);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

struct Game {
    void *func_000128C0(int id);
};
extern Game *data_0022FCE0;

// The owner (the object's parent): its flags at 0x16ac and the id of its camera at 0x16b8.
struct Owner_00105070 {
    char unknown_0000[0x16ac];
    unsigned int flags;
    char unknown_16b0[8];
    int camera;
};

// The camera's subject: whether it shows (0x1020), the point to project (0x1024), the sprite to draw (0x1030) and the
// two values whose ratio fades it (0x1034/0x1038).
struct Subject_00105070 {
    char unknown_0000[0x1020];
    int shown;
    Vector3 point;
    int sprite;
    float value;
    float limit;
};

// The camera (Object_000A4D80): its subject (parent) at 0x24, eye at 0x44, target at 0x5c, roll at 0x7c and its
// render state at 0x22c.
struct Object_000A4D80 {
    char unknown_000[0x24];
    Subject_00105070 *subject;
    char unknown_028[0x1c];
    Vector3 eye;
    char unknown_050[0xc];
    Vector3 target;
    char unknown_068[0x14];
    int roll;
    char unknown_080[0x1ac];
    unsigned int state;

    int func_000A4C00();
};

struct Part_00047F40 {
    char unknown_00[0x10];
    unsigned int material;
};

struct Mesh_00047F40 {
    char unknown_00[0xc];
    Part_00047F40 *parts;
};

struct Model_00133370 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(void *sprite, float time);

    void *surface;
    void *frames;
    Mesh_00047F40 *mesh;
};

// A direct child of Node (table 0x1D1F58, constructor func_00104E00, destructor func_00104EE0).
struct Object_00104EE0 : Node {
    virtual ~Object_00104EE0();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();

    int unknown_040;
    int value_44;
    int value_48;
    Model_00133370 *sprites[3];
    void *sprite_58;
    Vector3 point;
    int value_68;
    int value_6c;
    int value_70;
    float screen[2];

    void func_00104EF0(Vector3 *out);
};

// Slot 3: on 0, 3, 5 and 8, while the owner's flag 0x200 is set: keeps func_000A4C00 of the owner's camera at 0x48
// and, when the camera's subject is shown, projects its point (0x1024) with the camera's view (device slot 36 into
// 0x74). When the point lies in front (depth above 1), draws the subject's sprite (0x1030) at the position at 0x5c
// moved by func_00104EF0, timed by 1 - 0x1034 / 0x1038 and tinted 0xffb40000 (device slots 111/110) from 0.7 on.
// On 2 and 7, depth 0.9.
void Object_00104EE0::func_00011C80(int argument)
{
    Owner_00105070 *owner = (Owner_00105070 *)func_00011BD0();
    Object_000A4D80 *camera = (Object_000A4D80 *)data_0022FCE0->func_000128C0(owner->camera);
    switch (argument) {
    case 0:
    case 3:
    case 5:
    case 8: {
        if (!(owner->flags & 0x200)) {
            break;
        }
        value_48 = camera->func_000A4C00();
        Subject_00105070 *subject = camera->subject;
        if (!subject || !subject->shown) {
            break;
        }
        int visible = 0;
        func_001BAA00();
        data_00251D6C->slot31(camera->state, 1.0f, 4000.0f);
        func_001BAF70(&camera->eye, &camera->target, camera->roll);
        Vector3 view;
        func_001BAB20(&view, &subject->point);
        if (view.z > 1.0f) {
            visible = 1;
        }
        data_00251D6C->slot36(screen, &view);
        data_00251D6C->slot31(0x222, 1.0f, 4000.0f);
        func_001BAA50();
        if (!visible) {
            break;
        }
        data_00251D6C->slot33(-25.0f);
        func_001BAA00();
        func_001BAAA0(&point.x);
        func_00104EF0(&view);
        view.z = 0.0f;
        func_001BAAA0(&view.x);
        float time = 1.0f - subject->value / subject->limit;
        unsigned int colors[2];
        if (time >= 0.7f) {
            data_00251D6C->slot111(sprites[subject->sprite]->mesh->parts->material, 1, &colors[0]);
            colors[1] = 0xffb40000;
            data_00251D6C->slot110(sprites[subject->sprite]->mesh->parts->material, 1, colors[1]);
        }
        sprites[subject->sprite]->slot5(sprite_58, time);
        if (time >= 0.7f) {
            data_00251D6C->slot110(sprites[subject->sprite]->mesh->parts->material, 1, colors[0]);
        }
        func_001BAA50();
        data_00251D6C->slot33(0.0f);
        break;
    }
    case 2:
    case 7:
        depth = 0.9f;
        break;
    }
}
