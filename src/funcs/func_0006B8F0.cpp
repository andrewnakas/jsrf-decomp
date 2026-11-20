void func_001BA9C0();
void func_001BAA50();

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
    virtual void __stdcall slot72();
    virtual void __stdcall slot73(int value);
};

extern Device_00251D6C *data_00251D6C;
extern int data_001FA1CC;
extern int data_001FA1D0;
extern int data_00251D80;
extern unsigned int data_0020C6C8[];

// Hands `value` to the device slot when the cached state differs.
#define SET_STATE(cache, slot, value) \
    if (cache != (value)) { \
        cache = (value); \
        data_00251D6C->slot(value); \
    }

// Whether bit `index` of the visibility mask at 0x20C6C8 is set.
inline int IsVisible(int index)
{
    return index >= 0 && (data_0020C6C8[index >> 5] & (1 << (index & 0x1f)));
}

// A part of a group (0x50 bytes): the model it shows and its kind.
struct Part_0006BA80 {
    char unknown_00[0x40];
    int model;
    int kind;
    char unknown_48[8];
};

struct Group_0006BA80 {
    Part_0006BA80 *parts;
    unsigned int count;
};

struct Scene_0006BA80 {
    Group_0006BA80 *groups;
    char unknown_04[4];
    unsigned int count;
};

struct Model_0006BA80 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);
};

// A record of the model table at +0x14 (0x14 bytes).
struct Record_0006BA80 {
    char unknown_00[8];
    int texture;
    Model_0006BA80 *model;
    char unknown_10[4];
};

struct Object_0006A720 {
    char unknown_00[0x10];
    Scene_0006BA80 *scene;
    Record_0006BA80 *records;

    void func_0006B8F0();
};

// With texture 0 and device states 73 and 68 on, draws the model of every kind-3 part of each visible group of the
// scene at +0x10 through slot 5 (with its texture through slot 71); state 68 off at the end.
void Object_0006A720::func_0006B8F0()
{
    SET_STATE(data_001FA1CC, slot71, 0);
    SET_STATE(data_001FA1D0, slot73, 1);
    SET_STATE(data_00251D80, slot68, 1);
    for (unsigned int i = 0; i < scene->count; i++) {
        if (IsVisible(i)) {
            for (unsigned int j = 0; j < scene->groups[i].count; j++) {
                Part_0006BA80 *part = &scene->groups[i].parts[j];
                if (part->kind == 3) {
                    func_001BA9C0();
                    if (records[part->model].model) {
                        SET_STATE(data_001FA1CC, slot71, records[part->model].texture);
                        records[part->model].model->slot5(0, 0);
                    }
                    func_001BAA50();
                }
            }
        }
    }
    SET_STATE(data_00251D80, slot68, 0);
}
