// A rectangle in pixels.
struct Rect_001212C0 {
    int left;
    int top;
    int right;
    int bottom;
};

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
    virtual void __stdcall slot25(int value);
    virtual void __stdcall slot26();
    virtual void __stdcall slot27();
    virtual void __stdcall slot28();
    virtual void __stdcall slot29();
    virtual void __stdcall slot30(Rect_001212C0 *rect);
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
    virtual long __stdcall slot42(int texture);
    virtual void __stdcall slot43();
    virtual long __stdcall slot44();
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
    virtual void __stdcall slot73(int value);
    virtual void __stdcall slot74(int source, int destination);
    virtual void __stdcall slot75();
    virtual void __stdcall slot76();
    virtual void __stdcall slot77();
    virtual void __stdcall slot78();
    virtual void __stdcall slot79();
    virtual void __stdcall slot80();
    virtual void __stdcall slot81();
    virtual void __stdcall slot82(int stage, int value);
};

extern Device_00251D6C *data_00251D6C;

struct Object_0006E130 {
    int func_0006E130(int id);
};

extern Object_0006E130 data_00252790;

// Device state last set: slots 73 and 71, and stage 0's value for slot 82.
extern int data_001FA1D0;
extern int data_001FA1CC;
extern int data_00251D44;

// Each piece's size in pixels and where it starts on the screen.
struct Size_001212C0 {
    int width;
    int height;
};

struct Corner_00120F40 {
    float x;
    float y;
};

extern Size_001212C0 data_00225B4C[];
extern Corner_00120F40 data_00225B74[];

struct Object_00120420 {
    char unknown_0000[0x904];
    int textures[2];
    char unknown_090c[0x3790];
    int values[4];

    void func_00121480(int index);
    void func_00120F40(int index, int x, int y);
    void func_00121100(int index);
    void func_001209E0(int index);
    void func_00132290(int index);
};

// Renders piece `index` into the texture at 0x908 (device slot 42, then -1): over the piece's rectangle (slot 30)
// between slots 44 and 45, with slot 25 (-1), stage 0 set to 2 (slot 82, when it changed) and the usual
// blending, func_00132290, the quad (func_00120F40 with the value at 0x409c less 500 from 500 on, else
// func_00121100) and func_001209E0. First sets device slot 73 to 1 and slot 71 to 0 when they are not.
void Object_00120420::func_00121480(int index)
{
    if (data_001FA1D0 != 1) {
        data_001FA1D0 = 1;
        data_00251D6C->slot73(1);
    }
    if (data_001FA1CC) {
        data_001FA1CC = 0;
        data_00251D6C->slot71(0);
    }
    float x = data_00225B74[index].x;
    float y = data_00225B74[index].y;
    if (data_00251D6C->slot42(data_00252790.func_0006E130(textures[1])) >= 0) {
        Rect_001212C0 rect;
        rect.left = (int)x;
        rect.top = (int)y;
        rect.right = (int)(data_00225B4C[index].width + x);
        rect.bottom = (int)(data_00225B4C[index].height + y);
        data_00251D6C->slot30(&rect);
        if (data_00251D6C->slot44() >= 0) {
            data_00251D6C->slot25(-1);
            if (data_00251D44 != 2) {
                data_00251D44 = 2;
                data_00251D6C->slot82(0, 2);
            }
            data_00251D6C->slot74(0x302, 0x303);
            func_00132290(index);
            if (values[index] >= 500) {
                func_00120F40(index, values[index] - 500, 0);
            } else {
                func_00121100(index);
            }
            func_001209E0(index);
            data_00251D6C->slot30(0);
            data_00251D6C->slot45();
        }
        data_00251D6C->slot42(-1);
    }
}
