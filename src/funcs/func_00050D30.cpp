/* sym: ?func_00011C80_1@Object_00050D20@@UAEXH@Z = 0x00050D30 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Node {
    Node *func_00011BD0();
    Node(Node *owner, int id, unsigned int flags);
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
    char unknown_34[0x10];
};

// A camera node (table 0x1C43D8 repeats Node's slots 1 to 15; mask 7): eye, target, field of view and roll.
struct Object_00012170 : Node {
    Object_00012170(Node *owner, int id, unsigned int flags);

    Vector3 eye;
    char unknown_50[0xc];
    Vector3 target;
    char unknown_68[0xc];
    unsigned int fov;
    int unknown_78;
    int roll;
    int unknown_80;
    int left;
    int top;
    int width;
    int height;
    int unknown_94;
};

struct Info_00051490 {
    int unknown_00;
    int unknown_04;
    int id;
};

struct Owner_00051490 : Node {
    int unknown_44;
    Info_00051490 *info;
    int target;
};

struct Object_00051490 {
    char unknown_000[0x8d4];
    int player;
};

struct Object_000A1C50 {
    char unknown_000[0xca4];
    Vector3 position;
    char unknown_cb0[0x18];
    int angle_cc8;
    int angle_ccc;
    int angle_cd0;
    char unknown_cd4[0x30];
    Vector3 focus;
};

struct Mark_00051490 {
    char unknown_00[0x6c];
    Vector3 position;
};


void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

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
    virtual void __stdcall slot30(const void *settings);
    virtual void __stdcall slot31(unsigned int value, float first, float second);
};

extern Device_00251D6C *data_00251D6C;

struct Object_0006A960 {
    void func_0006A970(Vector3 *position);
};

struct Object_00046670 {
    void func_00046670(Vector3 *position);
    void func_00046940(int enable);
};

struct Game {
    void *func_000128C0(int id);
    void func_00012750();
};

extern Object_0006A960 data_0020C6C0;
extern Object_00046670 data_001F93C8;
extern Game *data_0022FCE0;

void __fastcall func_001BAF70(Vector3 *eye, Vector3 *target, int roll);

// The class whose table is at 0x1CAD20: overrides slots 6 (50D30).
struct Object_00050D20 : Object_00012170 {
    virtual ~Object_00050D20();
    virtual void func_00011C80_1(int argument);

    int unknown_98;
};

// Slot 6: follows the player of the parent's object as slot 5 of 0x1CAE68 does (the eye 18 up and 40 behind it,
// looking at its focus point or at the parent's mark), then in pass 0x13 sets the view as slot 3 of 0x1CAC60 does.
void Object_00050D20::func_00011C80_1(int argument)
{
    unknown_98 = 0;
    Owner_00051490 *owner = (Owner_00051490 *)func_00011BD0();
    Object_00051490 *object = (Object_00051490 *)data_0022FCE0->func_000128C0(owner->info->id);
    if (object) {
        Object_000A1C50 *player = (Object_000A1C50 *)data_0022FCE0->func_000128C0(object->player);
        if (player) {
            func_001BAA00();
            func_001BAAA0(&player->position.x);
            func_001BB2E0(player->angle_cc8);
            func_001BB380(player->angle_cd0);
            func_001BB330(player->angle_ccc + 0x8000);
            Vector3 offset;
            offset.x = 0.0f;
            offset.y = 18.0f;
            offset.z = 40.0f;
            func_001BAB20(&eye, &offset);
            target.x = player->focus.x;
            target.y = player->focus.y;
            target.z = player->focus.z;
            fov = 0x2000;
            roll = 0xaaa;
            func_001BAA50();
            Mark_00051490 *mark = (Mark_00051490 *)data_0022FCE0->func_000128C0(owner->target);
            if (mark) {
                target.x = mark->position.x;
                target.y = mark->position.y;
                target.z = mark->position.z;
            }
            unknown_98 = 1;
        }
    }
    if (unknown_98 && argument == 0x13) {
        data_00251D6C->slot30(0);
        data_00251D6C->slot31(fov, 1.0f, 5000.0f);
        func_001BAF70(&eye, &target, roll);
        data_0020C6C0.func_0006A970(&eye);
        data_001F93C8.func_00046670(&eye);
        data_001F93C8.func_00046940(0);
        data_0022FCE0->func_00012750();
    }
}
