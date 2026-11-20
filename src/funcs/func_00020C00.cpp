struct Matrix_001BA950 {
    float m[4][4];
};

struct Motion_0005F060 {
    short unknown_00;
    short frames;
};

void *func_00025700(unsigned int index, int first, int second, int third);
void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);
void __fastcall func_001BAAA0(float *vector);

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
    virtual void __stdcall slot74(int source, int destination);
};

extern Device_00251D6C *data_00251D6C;
extern float data_001EBEE4[3];

// An effect (constructor 0x15420, size 0x118).
struct Object_00015D50 {
    virtual ~Object_00015D50();

    void func_00015F90();
};

// The slot's objects: slot 5 starts a motion, slot 6 follows another object.
struct Item_00020A90 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);
    virtual void slot6(Item_00020A90 *item);

};

struct Items_00020A90 {
    Item_00020A90 *body;
    char unknown_04[0x10];
    Item_00020A90 *first;
    char unknown_18[8];
    Item_00020A90 *second;
    Item_00020A90 *third;
};

// A part of the object func_00025700 finds: slot 5 draws a motion at a time.
struct Part_00020A90 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(Motion_0005F060 *motion, float time);
};

// What func_00025700 (5, ...) returns: its parts at +0 and motions at +0x18.
struct Sprite_00020A90 {
    Part_00020A90 **parts;
    char unknown_04[0x14];
    Motion_0005F060 **motions;
};

struct Info_0001FED0 {
    int unknown_00;
    int slot;
};

struct Entry_0001FED0 {
    char unknown_00[8];
    Info_0001FED0 *info;
    char unknown_0c[0x68];
    Object_00015D50 *first;
    Object_00015D50 *second;
};

struct State_0001FED0 {
    char unknown_00[0x80];
    int *active;
    char unknown_84[0x18];
    Items_00020A90 **items;
    Item_00020A90 **others;
};

// Node child with the table at 0x1C4BA8 (destructor 0x22990); 0x21320 runs the member-pointer table at 0x1EBD60
// by each entry's kind.
struct Object_00022990 {
    char unknown_00[0x48];
    Matrix_001BA950 matrix;
    char unknown_88[0x44];
    float times[4];
    State_0001FED0 *state;
    Entry_0001FED0 **entries;

    void func_00020C00(int index, unsigned int message, int first, int second);
};

// Kind 24 of the table at 0x1EBD60, when func_00025700 (5, 20) finds its object: for message 8, starts the motion
// (first, second; or 0, 0) of the slot's body (item 0), has items 5, 8 and 9 follow it, runs func_00015F90 of the
// entry's two effects and draws the object's four parts with motions 0 to 3 at the times at +0xcc under the matrix
// at +0x48 moved to 0x1EBEE4, blended (device slot 74); for 0xf and 0x10, gives 0, 0 to slot 5 of the slot's other
// item (+0xa0) when the slot is active and has one.
void Object_00022990::func_00020C00(int index, unsigned int message, int first, int second)
{
    Entry_0001FED0 *entry = entries[index];
    State_0001FED0 *state = this->state;
    Sprite_00020A90 *sprite = (Sprite_00020A90 *)func_00025700(5, 0x14, 0, 0);
    if (!sprite)
        return;
    int slot = entry->info->slot;
    switch (message) {
    case 8: {
        Item_00020A90 *body = state->items[slot]->body;
        if (first)
            body->slot5(first, second);
        else
            body->slot5(0, 0);
        state->items[slot]->first->slot6(body);
        state->items[slot]->second->slot6(body);
        state->items[slot]->third->slot6(body);
        func_001BAA50();
        entry->first->func_00015F90();
        entry->second->func_00015F90();
        func_001BA9C0();
        data_00251D6C->slot74(0x302, 0x303);
        func_001BA9C0();
        func_001BA8F0(&matrix);
        func_001BAAA0(data_001EBEE4);
        for (int i = 0; i < 4; i++)
            sprite->parts[i]->slot5(sprite->motions[i], times[i]);
        func_001BAA50();
        break;
    }
    case 0xf:
    case 0x10:
        if (state->active[slot] && state->others[slot])
            state->others[slot]->slot5(0, 0);
        break;
    }
}
