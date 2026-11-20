struct Frame_000479D0;
struct Matrix_001BA950 {
    float m[4][4];
};

struct Motion_0005F060 {
    short unknown_00;
    short frames;
};

void *func_00025700(unsigned int index, int first, int second, int third);
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
    virtual void __stdcall slot66(int value);
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

// The model base class (table 0x1CAA8C): slot 5 starts a motion.
struct Object_00047470 {
    virtual ~Object_00047470();
    virtual void func_00048190(void *first, void *second, void *frame);
    virtual void func_00047470(void *first, void *second, Frame_000479D0 *frame);
    virtual void func_00048390(void *first, void *second, void *frame);
    virtual void func_00047540();
    virtual void func_00047690(int value, int argument);

    char unknown_04[0x1c];
    Matrix_001BA950 *matrices;
    unsigned int flags;

    void func_00047970(void *data, int argument);
};

// A part of the object func_00025700 finds: slot 5 draws a motion.
struct Part_00020D70 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(Motion_0005F060 *motion, int argument);
};

// What func_00025700 (5, ...) returns: its parts at +0 and motions at +0x18.
struct Sprite_00020D70 {
    Part_00020D70 **parts;
    char unknown_04[0x14];
    Motion_0005F060 **motions;
};

struct Items_00020D70 {
    Object_00047470 *body;
    Object_00047470 *other;
};

struct Info_0001FED0 {
    int unknown_00;
    int slot;
};

struct Entry_0001FED0 {
    char unknown_00[8];
    Info_0001FED0 *info;
    char unknown_0c[0x58];
    int argument;
};

struct State_0001FED0 {
    char unknown_00[0x80];
    int *active;
    char unknown_84[0x18];
    Items_00020D70 **items;
};

// Node child with the table at 0x1C4BA8 (destructor 0x22990); 0x21320 runs the member-pointer table at 0x1EBD60
// by each entry's kind.
struct Object_00022990 {
    char unknown_00[0xdc];
    State_0001FED0 *state;
    Entry_0001FED0 **entries;

    void func_00020D70(int index, unsigned int message, int first, int second);
};

// Kind 23 of the table at 0x1EBD60: clears flag 0x10 of the slot's body, then for message 8 starts its motion
// (first, second; or 0, 0); for 0xd, draws the body blended (device slots 66 and 74) and part 2 of the object
// func_00025700 (5, 2) finds with its motion 4; for 0xf and 0x10, moves to (0, 6, 0) (func_001BAAA0), clears flag
// 0x10 of the slot's other item and, when the slot is active, gives it 0, 0 by slot 5.
void Object_00022990::func_00020D70(int index, unsigned int message, int first, int second)
{
    State_0001FED0 *state = this->state;
    Entry_0001FED0 *entry = entries[index];
    int slot = entry->info->slot;
    Object_00047470 *body = state->items[slot]->body;
    body->flags &= ~0x10;
    switch (message) {
    case 8:
        if (first)
            body->func_00047690(first, second);
        else
            body->func_00047690(0, 0);
        break;
    case 0xd: {
        Sprite_00020D70 *sprite = (Sprite_00020D70 *)func_00025700(5, 2, 0, 0);
        if (!sprite)
            break;
        Part_00020D70 *part = sprite->parts[2];
        data_00251D6C->slot66(0);
        data_00251D6C->slot74(0x302, 1);
        body->func_00047970((void *)first, second);
        func_001BA8F0(body->matrices);
        part->slot5(sprite->motions[4], entry->argument);
        data_00251D6C->slot66(1);
        data_00251D6C->slot74(0x302, 0x303);
        break;
    }
    case 0xf:
    case 0x10: {
        float position[3];
        position[0] = 0.0f;
        position[1] = 6.0f;
        position[2] = 0.0f;
        func_001BAAA0(position);
        state->items[slot]->other->flags &= ~0x10;
        Object_00047470 *other = state->items[slot]->other;
        if (state->active[slot])
            other->func_00047690(0, 0);
        break;
    }
    }
}
