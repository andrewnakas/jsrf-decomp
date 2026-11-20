int __stdcall func_00145560(void *counter);

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
    virtual void __stdcall slot11(void *viewport);
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
    virtual void __stdcall slot24(unsigned int value);
    virtual void __stdcall slot25(int value);
    virtual void __stdcall slot26();
    virtual void __stdcall slot27();
    virtual void __stdcall slot28();
    virtual void __stdcall slot29();
    virtual void __stdcall slot30(int value);
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
    virtual void __stdcall slot42(int value);
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
    virtual void __stdcall slot71();
    virtual void __stdcall slot72();
    virtual void __stdcall slot73(int value);
    virtual void __stdcall slot74();
    virtual void __stdcall slot75();
    virtual void __stdcall slot76();
    virtual void __stdcall slot77();
    virtual void __stdcall slot78();
    virtual void __stdcall slot79();
    virtual void __stdcall slot80();
    virtual void __stdcall slot81(unsigned int stage, int texture);
    virtual void __stdcall slot82();
    virtual void __stdcall slot83(int stage, int index);
};

extern Device_00251D6C *data_00251D6C;
extern int data_00251D88;
extern int data_00251D54;
extern int data_001FA1D0;
extern int data_00251D80;

struct Object_0006E910 {
    void func_0006E910(__int64 *out, __int64 start, __int64 end);
};

extern Object_0006E910 data_0020CC48;

struct Game {
    char unknown_0000[0x34];
    unsigned int clear;
    char unknown_0038[0x3c];
    int ready;
    char unknown_0078[4];
    char viewport[0x8744];
    __int64 time;

    void func_000131F0();
    void func_00013930();
};

// Starts a frame: resets the device's states (slots 42, 24, 30 and 25, no textures in the four stages, slots 73 and
// 68 off, stages 0 to 3 to their own coordinates by slot 83), runs func_000131F0 when +0x74 is clear, sets the
// viewport at +0x7c (slot 11) and keeps how long it took (QueryPerformanceCounter around it) at +0x87c0
// (func_0006E910 of 0x20CC48).
void Game::func_00013930()
{
    __int64 start;
    __int64 end;
    func_00145560(&start);
    data_00251D6C->slot42(-1);
    data_00251D88 = -1;
    data_00251D6C->slot24(clear);
    data_00251D6C->slot30(0);
    data_00251D6C->slot25(-1);
    for (unsigned int i = 0; i < 4; i++) {
        (&data_00251D54)[i] = -1;
        data_00251D6C->slot81(i, -1);
    }
    data_00251D6C->slot73(0);
    data_001FA1D0 = 0;
    data_00251D6C->slot68(0);
    data_00251D80 = 0;
    data_00251D6C->slot83(0, 0);
    data_00251D6C->slot83(1, 1);
    data_00251D6C->slot83(2, 2);
    data_00251D6C->slot83(3, 3);
    if (!ready)
        func_000131F0();
    data_00251D6C->slot11(viewport);
    func_00145560(&end);
    data_0020CC48.func_0006E910(&time, start, end);
}
