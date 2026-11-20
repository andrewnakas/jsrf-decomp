struct Frame_000479D0;

struct Object_0006E130 {
    int func_0006E130(int id);
};

extern Object_0006E130 data_00252790;

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
    virtual void __stdcall slot71(int value);
    virtual void __stdcall slot72();
    virtual void __stdcall slot73();
    virtual void __stdcall slot74();
    virtual void __stdcall slot75();
    virtual void __stdcall slot76();
    virtual void __stdcall slot77();
    virtual void __stdcall slot78();
    virtual void __stdcall slot79();
    virtual void __stdcall slot80();
    virtual void __stdcall slot81(int stage, int texture);
    virtual void __stdcall slot82(int stage, int value);
    virtual void __stdcall slot83();
    virtual void __stdcall slot84();
    virtual void __stdcall slot85(int first, int second);
};

extern Device_00251D6C *data_00251D6C;

extern int data_001FA1CC;
extern int data_00251D48;
extern int data_00251D58;

// The model base class (table 0x1CAA8C): frames (+0x8) and a texture id at +0x44.
struct Object_00047470 {
    virtual ~Object_00047470();

    void *surface;
    Frame_000479D0 *frames;
    char unknown_0c[0x38];
    int texture;

    void func_000479D0(Frame_000479D0 *frames, int kind);
    void func_000496E0(int data, int frame);
};

#define SET_STAGE(cache, stage, value) \
    if (cache != (value)) { \
        cache = (value); \
        data_00251D6C->slot81(stage, (value)); \
    }

// Handler 6 of the table at 0x1F97B4 (its arguments are not used): slot 71 of the device off, slot 82 (1, 2), the
// texture +0x44 (func_0006E130 of 0x252790) in stage 1 (cached in 0x251D58), then the frames posed for kind 4 between
// slot 85 (1, 0) and (1, 1), and stage 1 cleared.
void Object_00047470::func_000496E0(int, int)
{
    if (data_001FA1CC != 0) {
        data_001FA1CC = 0;
        data_00251D6C->slot71(0);
    }
    if (data_00251D48 != 2) {
        data_00251D48 = 2;
        data_00251D6C->slot82(1, 2);
    }
    SET_STAGE(data_00251D58, 1, data_00252790.func_0006E130(texture));
    data_00251D6C->slot85(1, 0);
    func_000479D0(frames, 4);
    data_00251D6C->slot85(1, 1);
    SET_STAGE(data_00251D58, 1, -1);
}
