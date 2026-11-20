/* sym: ?func_00011C90_3@Object_00051480@@UAEXXZ = 0x00051490 */
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
    char unknown_00[0x80];
    Vector3 position;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

void func_001BAA00();
void func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

// The class whose table is at 0x1CAE68: overrides slots 5 (51490), 6 (515B0).
struct Object_00051480 : Object_00012170 {
    virtual ~Object_00051480();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);

    int unknown_98;
};

// Slot 5: follows the player of the parent's object: the eye 18 up and 40 behind the player, looking at the
// player's focus point, or at the parent's mark when it exists. +0x98 says whether there was a player.
void Object_00051480::func_00011C90_3()
{
    unknown_98 = 0;
    Owner_00051490 *owner = (Owner_00051490 *)func_00011BD0();
    Object_00051490 *object = (Object_00051490 *)data_0022FCE0->func_000128C0(owner->info->id);
    if (object) {
        Object_000A1C50 *player = (Object_000A1C50 *)data_0022FCE0->func_000128C0(object->player);
        if (player) {
            unknown_98 = 1;
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
        }
    }
}
