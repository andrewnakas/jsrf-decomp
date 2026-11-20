void *func_00025700(unsigned int index, int first, int second, int third);

struct Matrix_001BA950;
struct Motion_0005F060;

void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);

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
    virtual void __stdcall slot66(int value);
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

// The base of the tables at 0x1CA490, 0x1CAA8C and 0x1CC12C.
struct Object_00047470 {
    virtual ~Object_00047470();
    virtual void slot1();
    virtual void func_00047470();
    virtual void slot3();
    virtual void func_00047540();
    virtual void func_00047690(int first, int second);

    char unknown_04[0x1c];
    Matrix_001BA950 *matrices;

    void func_00047970(void *data, int argument);
};

struct Model_00020F10 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(Motion_0005F060 *motion, float time);
};

// What func_00025700 (5, ...) returns: its models (+0x0) and motions (+0x18).
struct Sprite_00020F10 {
    Model_00020F10 **models;
    char unknown_04[0x14];
    Motion_0005F060 **motions;
};

struct Items_00020F10 {
    Object_00047470 *items[1];
};

struct State_00020F10 {
    char unknown_00[0x9c];
    Items_00020F10 **items;
};

struct Info_00020F10 {
    int unknown_00;
    int slot;
};

struct Entry_00020F10 {
    char unknown_00[0x8];
    Info_00020F10 *info;
    char unknown_0c[0x58];
    float time;
    char unknown_68[0x18];
    int key;
};

struct Object_00022990 {
    char unknown_00[0xdc];
    State_00020F10 *state;
    Entry_00020F10 **entries;

    void func_00020F10(int index, int key, int first, int second);
};

// Kind 25 of the table at 0x1EBD60: when entry `index` holds `key`, hands the two values (or 0, 0 when the first is 0)
// to slot 5 of item 0 of its slot's items. For key 0xd, with the object func_00025700 (5, 0x11) finds: device state 66
// off and state 0x302 at 1, item 0 posed from the values (func_00047970) and its matrix loaded, model 3 of the object
// drawn with motion 1 at the entry's time (+0x64); then state 66 on and 0x302 at 0x303.
void Object_00022990::func_00020F10(int index, int key, int first, int second)
{
    Entry_00020F10 *entry = entries[index];
    Object_00047470 *item = state->items[entry->info->slot]->items[0];
    if (entry->key == key) {
        if (first)
            item->func_00047690(first, second);
        else
            item->func_00047690(0, 0);
    }
    if (key == 0xd) {
        Sprite_00020F10 *sprite = (Sprite_00020F10 *)func_00025700(5, 0x11, 0, 0);
        if (sprite) {
            Model_00020F10 *model = sprite->models[3];
            data_00251D6C->slot66(0);
            data_00251D6C->slot74(0x302, 1);
            item->func_00047970((void *)first, second);
            func_001BA8F0(item->matrices);
            model->slot5(sprite->motions[1], entry->time);
            data_00251D6C->slot66(1);
            data_00251D6C->slot74(0x302, 0x303);
        }
    }
}
