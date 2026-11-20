/* cflags: /Oy- */
/* sym: ?func_00011C80@Object_000C39E0@@UAEXH@Z = 0x000C3A60 */
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
    char unknown_34[0x10];
};

struct Item_000C39E0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();

    char unknown_04[0x2c];
    unsigned int flags;
    char unknown_34[0x14];
    float value_48;
    int kind;
    char unknown_50[0x78];
    Item_000C39E0 *next;
};

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
    virtual void __stdcall slot74(int first, int second);
};

extern Device_00251D6C *data_00251D6C;

void func_001BA9C0();
void func_001BAA50();

// The Node class whose table is at 0x1cdd60 (stored by its constructor): overrides Node's slots 1 to 3.
struct Object_000C39E0 : Node {
    virtual void func_00011C80(int argument);

    Item_000C39E0 *items;
};

// Node slot 3, the message handler: on 7, depth 20. Otherwise draws every item of the list at 0x44 (slot 12), then
// with render state 0x306 (device slot 74) those of kind 2 (at 0x4c) without bit 1 at 0x30 (slot 14), then with
// 0x302/0x303 those of them whose value at 0x48 is at most 50 (slot 15), each between func_001BA9C0 and
// func_001BAA50.
void Object_000C39E0::func_00011C80(int argument)
{
    if (argument == 7) {
        depth = 20.0f;
        return;
    }
    Item_000C39E0 *item;
    for (item = items; item; item = item->next) {
        func_001BA9C0();
        item->slot12();
        func_001BAA50();
    }
    item = items;
    data_00251D6C->slot74(0x306, 0);
    for (; item; item = item->next) {
        if (!(item->flags & 2) && item->kind == 2) {
            func_001BA9C0();
            item->slot14();
            func_001BAA50();
        }
    }
    data_00251D6C->slot74(0x302, 0x303);
    for (item = items; item; item = item->next) {
        if (!(item->flags & 2) && item->kind == 2 && item->value_48 <= 50.0f) {
            func_001BA9C0();
            item->slot15();
            func_001BAA50();
        }
    }
}
