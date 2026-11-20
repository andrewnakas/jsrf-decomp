/* sym: ?func_00011C80@Object_000E5380@@UAEXH@Z = 0x000E5030 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Matrix_001BA950;

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void func_001BB9A0(float scale);

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
    virtual void __stdcall slot25(int value);
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
    virtual void __stdcall slot66(int value);
    virtual void __stdcall slot67();
    virtual void __stdcall slot68();
    virtual void __stdcall slot69();
    virtual void __stdcall slot70();
    virtual void __stdcall slot71(int value);
    virtual void __stdcall slot72();
    virtual void __stdcall slot73(int value);
    virtual void __stdcall slot74(int first, int second);
    virtual void __stdcall slot75();
    virtual void __stdcall slot76(int value);
    virtual void __stdcall slot77(int value);
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
    virtual void __stdcall slot94(int value);
    virtual void __stdcall slot95(int first, int second, int third);
};

extern Device_00251D6C *data_00251D6C;
extern int data_001FA1CC;
extern int data_001FA1D0;

struct Light_00046920 {
    int unknown_00;
    unsigned int color_04;
    unsigned int color_08;
    int unknown_0c;
    Vector3 direction;
    char unknown_1c[0x14];
    Vector3 position;
    char unknown_3c[0x34];
};

struct Object_00046670 {
    void func_000466D0();
    void func_00046740(Light_00046920 *light);
    void func_00046940(int enable);
    void func_00046A30();
};

extern Object_00046670 data_001F93C8;
extern Light_00046920 *data_001F963C;

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);

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

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The model a glowing item draws (slot 5).
struct Model_000E5030 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);
};

struct Part_000E5030 {
    char unknown_00[0xc];
    Model_000E5030 *model;
};

// The list link of a glowing item (its second base, at 0x44): flags at 0x4c, the next item's link at 0x74.
struct Link_000E5030 {
    char unknown_00[0x4c];
    unsigned int flags;
    char unknown_50[0x24];
    Link_000E5030 *next;
};

// A glowing item: its mode at 0xbc, light point at 0xf4, scale at 0x100, matrix at 0x104 and part at 0x164.
struct Item_000E5030 : Node, Link_000E5030 {
    int mode;
    char unknown_c0[0x34];
    Vector3 point;
    float scale;
    char matrix[0x60];
    Part_000E5030 *part;
};

// The object the behaviour serves: its glowing items at 0xd0.
struct Owner_000E5030 {
    char unknown_00[0xd0];
    Link_000E5030 *items;
};

struct Interface_000E5380 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5();
    virtual long __stdcall slot6(void *data, int first, int second);
    virtual long __stdcall slot7();
    virtual long __stdcall slot8(float first, float second);
    virtual long __stdcall slot9();
    virtual long __stdcall slot10(int value);
};

extern char data_00218B70[];

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// The class whose table is at 0x1CED6C: holds a resource of data_00251D74 at 0x30.
struct Object_000E5380 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C80(int argument);
    virtual ~Object_000E5380();

    Owner_000E5030 *owner;
    char unknown_08[0x28];
    Interface_000E5380 *resource;
};

// Slot 2: on event 10 draws the served object's glowing items (list at 0xd0) through the resource at 0x30: each
// item without flags 0x1002000 is drawn twice (stages 2 and 1) with its matrix and scale, and in mode 2 also lights
// object 0x2c's passes 15 and 16 from its point; render state 0x1FA1D0 is 1 meanwhile.
void Object_000E5380::func_00011C80(int argument)
{
    if (argument != 10) {
        return;
    }
    resource->slot8(1.0f, 1.0f);
    resource->slot6(data_00218B70, 1, 0);
    Item_000E5030 *item = static_cast<Item_000E5030 *>(owner->items);
    Node *glow = (Node *)data_0022FCE0->func_000128C0(0x2c);
    int saved = data_001FA1D0;
    if (data_001FA1CC) {
        data_001FA1CC = 0;
        data_00251D6C->slot71(0);
    }
    if (data_001FA1D0 != 1) {
        data_001FA1D0 = 1;
        data_00251D6C->slot73(1);
    }
    Light_00046920 light = *data_001F963C;
    data_001F93C8.func_000466D0();
    data_00251D6C->slot94(1);
    data_00251D6C->slot76(0);
    for (; item; item = static_cast<Item_000E5030 *>(item->Link_000E5030::next)) {
        if (item->Link_000E5030::flags & 0x1002000) {
            continue;
        }
        data_00251D6C->slot25(2);
        data_00251D6C->slot74(0, 1);
        data_00251D6C->slot77(0x206);
        func_001BA9C0();
        func_001BA8F0((Matrix_001BA950 *)item->matrix);
        func_001BB9A0(item->scale);
        data_00251D6C->slot66(2);
        data_00251D6C->slot95(0x1e02, 0x207, 1);
        item->part->model->slot5(0, 0);
        data_00251D6C->slot66(1);
        data_00251D6C->slot95(0x1e03, 0x207, 1);
        item->part->model->slot5(0, 0);
        func_001BAA50();
        if (item->mode == 2) {
            func_001BAC00(&light.position, &item->point);
            data_001F93C8.func_00046740(&light);
            data_001F93C8.func_00046940(1);
            data_00251D6C->slot66(2);
            data_00251D6C->slot95(0x1e02, 0x205, 0);
            glow->func_00011C80(15);
            data_00251D6C->slot66(1);
            data_00251D6C->slot95(0x1e03, 0x205, 0);
            glow->func_00011C80(16);
        }
        data_00251D6C->slot77(0x203);
        data_00251D6C->slot95(0x1e00, 0x202, 1);
        data_00251D6C->slot74(0x302, 1);
        resource->slot10(1);
    }
    data_00251D6C->slot74(0x302, 0x303);
    data_00251D6C->slot76(1);
    data_00251D6C->slot94(0);
    data_001F93C8.func_00046A30();
    if (data_001FA1D0 != saved) {
        data_001FA1D0 = saved;
        data_00251D6C->slot73(saved);
    }
}
