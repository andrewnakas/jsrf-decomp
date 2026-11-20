// A surface the device gives: slot 7 clears it to a colour.
struct Surface_00120420 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7(int value);
};

// The device at data_00251D6C: slot 58 gives the surface of a texture.
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
    virtual void __stdcall slot58(int first, int second, int texture, int format, Surface_00120420 **surface);
};

struct Interface_00120510 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

struct Interface_00251D74 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5();
    virtual long __stdcall slot6();
    virtual long __stdcall slot7();
    virtual long __stdcall slot8();
    virtual long __stdcall slot9(int first, int second, Interface_00120510 **result);
};

struct Object_0006E130 {
    int func_0006E130(int id);
    int func_0006E360(int size);
    int func_0006E4E0(int size);
};

struct Object_00120420 {
    char unknown_000[0x904];
    int ids[2];
    char unknown_90c[0x254];
    Surface_00120420 *surfaces[2];

    void func_00120420();
};

extern Device_00251D6C *data_00251D6C;
extern Interface_00251D74 *data_00251D74;
extern Object_0006E130 data_00252790;
extern Interface_00120510 *data_00258C68;
extern Interface_00120510 *data_00258C6C;

// Makes two 0x400 textures (func_0006E4E0 and func_0006E360 of data_00252790) into the ids at 0x904, takes their
// surfaces into 0xb60 and 0xb64 (slot 58 of the device) and clears them to 0 and 0xff000000; then the two objects
// at data_00258C68 and data_00258C6C from slot 9 of data_00251D74 (cleared when that fails).
void Object_00120420::func_00120420()
{
    ids[0] = data_00252790.func_0006E4E0(0x400);
    data_00251D6C->slot58(0, 0, data_00252790.func_0006E130(ids[0]), 2, &surfaces[0]);
    surfaces[0]->slot7(0);
    ids[1] = data_00252790.func_0006E360(0x400);
    data_00251D6C->slot58(0, 0, data_00252790.func_0006E130(ids[1]), 2, &surfaces[1]);
    surfaces[1]->slot7(0xff000000);
    if (data_00251D74->slot9(1, 0, &data_00258C68) < 0) {
        data_00258C68 = 0;
        return;
    }
    if (data_00251D74->slot9(1, 0, &data_00258C6C) < 0) {
        data_00258C6C = 0;
    }
}
