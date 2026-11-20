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
    virtual void __stdcall slot33(float value);
};

struct Model_00133370 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);

    char unknown_04[0xc];
    int mode;
    char unknown_14[0x10];
    unsigned int flags;

    void func_00047F40(int value);
};

struct Object_00120420 {
    char unknown_0000[0x2510];
    Model_00133370 *models[7];
    char unknown_252c[0x970];
    unsigned char shown[0x24];

    void func_00133370();
};

extern Device_00251D6C *data_00251D6C;

void func_001BA9C0();
void func_001BAA50();
void func_001BAA60(float x, float y, float z);

// Draws each shown model of the seven at +0x2510 (flags +0x2EBA on) at (2, 3, 102) with device slot 33 at -10:
// models 1 and 5 in mode 2 and visible, the others in mode 0 through func_00047F40 (-1) and hidden.
void Object_00120420::func_00133370()
{
    for (int i = 0x1e; i <= 0x24; i++) {
        if (shown[i]) {
            func_001BA9C0();
            func_001BAA60(2.0f, 3.0f, 102.0f);
            data_00251D6C->slot33(-10.0f);
            if (i != 0x1f && i != 0x23) {
                models[i - 0x1e]->mode = 0;
                models[i - 0x1e]->func_00047F40(-1);
                models[i - 0x1e]->flags &= ~1;
                models[i - 0x1e]->slot5(0, 0);
            } else {
                models[i - 0x1e]->mode = 2;
                models[i - 0x1e]->flags &= ~1;
                models[i - 0x1e]->flags |= 1;
                models[i - 0x1e]->slot5(0, 0);
            }
            data_00251D6C->slot33(0.0f);
            func_001BAA50();
        }
    }
}
