struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BA9C0();
void func_001BAA50();
void __fastcall func_001BADB0(Vector3 *position);

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
    virtual void __stdcall slot68(int value);
    virtual void __stdcall slot69();
    virtual void __stdcall slot70();
    virtual void __stdcall slot71(int texture);
};

extern Device_00251D6C *data_00251D6C;
extern int data_001FA1CC;
extern int data_00251D80;

// Hands `value` to the device slot when the cached state differs.
#define SET_STATE(cache, slot, value) \
    if (cache != (value)) { \
        cache = (value); \
        data_00251D6C->slot(value); \
    }

// A part (0x50 bytes): where it stands, the model it shows and a value for the model.
struct Part_0006BA80 {
    Vector3 position;
    char unknown_0c[0x34];
    int model;
    int kind;
    char unknown_48[4];
    int unknown_4c;
};

// An entry of the list at +0x24.
struct Item_0006A7C0 {
    Part_0006BA80 *part;
    char unknown_04[8];
    Item_0006A7C0 *next;
};

struct Model_0006BA80 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);

    char unknown_04[0x58];
    int unknown_5c;
};

// A record of the model table at +0x14 (0x14 bytes).
struct Record_0006BA80 {
    char unknown_00[8];
    int texture;
    Model_0006BA80 *model;
    char unknown_10[4];
};

struct Object_0006A720 {
    char unknown_00[0x14];
    Record_0006BA80 *records;
    char unknown_18[0xc];
    Item_0006A7C0 *items;

    void func_0006A7C0();
};

// Draws the parts of the list at +0x24 with device state 68 on: each model (with its texture through slot 71 and
// the part's +0x4c at its +0x5c) through slot 5, moved to the part.
void Object_0006A720::func_0006A7C0()
{
    Item_0006A7C0 *item = items;
    SET_STATE(data_001FA1CC, slot71, 0);
    SET_STATE(data_00251D80, slot68, 1);
    for (; item; item = item->next) {
        func_001BA9C0();
        func_001BADB0(&item->part->position);
        if (records[item->part->model].model) {
            SET_STATE(data_001FA1CC, slot71, records[item->part->model].texture);
            records[item->part->model].model->unknown_5c = item->part->unknown_4c;
            records[item->part->model].model->slot5(0, 0);
        }
        func_001BAA50();
    }
    SET_STATE(data_00251D80, slot68, 0);
}
