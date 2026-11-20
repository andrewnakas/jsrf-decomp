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
    virtual void __stdcall slot73(int value);
    virtual void __stdcall slot74(int source, int destination);
};

extern Device_00251D6C *data_00251D6C;
extern int data_001FA1D0;

struct Info_0001FED0 {
    int unknown_00;
    int slot;
    char unknown_08[0x2c];
    int animated;
};

struct Entry_0001FED0 {
    char unknown_00[8];
    Info_0001FED0 *info;
    char unknown_0c[0x48];
    int motion;
    char unknown_58[4];
    int argument;
    char unknown_60[8];
    int kind;
};

struct State_0001FED0 {
    char unknown_00[0x60];
    void **motions;
    char unknown_64[4];
    int *active;
    char unknown_6c[4];
    int *kinds;
};

// Node child with the table at 0x1C4BA8 (destructor 0x22990).
struct Object_00022990 {
    char unknown_00[0xdc];
    State_0001FED0 *state;
    Entry_0001FED0 **entries;

    void func_00021320(unsigned int index, int pass);
};

// The handlers by an entry's kind.
extern void (Object_00022990::*data_001EBD60[])(unsigned int index, int pass, void *motion, int argument);

// Sets the 0x1FA1D0 flag (device slot 73), and for an entry whose slot is active runs the handler of its kind (+0x68)
// from the table at 0x1EBD60 with the pass, its motion (+0x54, when its info at +0x34 says so) and its +0x5c; passes 8
// and 0xd run with blending (device slot 74: 0x302, 1 for slot kind 3, else 0x302, 0x303) and restore it after.
void Object_00022990::func_00021320(unsigned int index, int pass)
{
    Entry_0001FED0 *entry = entries[index];
    State_0001FED0 *state = this->state;
    void *motion = 0;
    if (data_001FA1D0 != 1) {
        data_001FA1D0 = 1;
        data_00251D6C->slot73(1);
    }
    if (entries[index]->info->animated && entry->motion != -1)
        motion = state->motions[entry->motion];
    int slot = entry->info->slot;
    if (state->active[slot]) {
        if (pass == 8 || pass == 0xd) {
            if (state->kinds[slot] == 3)
                data_00251D6C->slot74(0x302, 1);
            else
                data_00251D6C->slot74(0x302, 0x303);
        }
        (this->*data_001EBD60[entry->kind])(index, pass, motion, entry->argument);
        if (pass == 8 || pass == 0xd)
            data_00251D6C->slot74(0x302, 0x303);
    }
}
