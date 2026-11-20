struct Game {
    int func_000127E0(int index);
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
    virtual void __stdcall slot30(const void *settings);
};

struct Settings_002155E8 {
    int values[4];
};

extern Game *data_0022FCE0;
extern Device_00251D6C *data_00251D6C;
extern Settings_002155E8 data_002155E8[];

struct Object_000A4D80 {
    char unknown_00[0x98];
    int value;

    void func_000A60D0();
};

// Passes entry value + 4 * setting 0xc (func_000127E0) of the 16-byte table at 0x2155e8 to slot 30 of the device
// in data_00251D6C. func_000A5070 (slot 1 of the camera node) computes the same entry from the index at 0x98; called
// on the object of func_000A4C00 (func_00110B40 at 0x110ecc, func_00107AE0).
void Object_000A4D80::func_000A60D0()
{
    const Settings_002155E8 *settings = &data_002155E8[value + data_0022FCE0->func_000127E0(0xc) * 4];
    data_00251D6C->slot30(settings);
}
