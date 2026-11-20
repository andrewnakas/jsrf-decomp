/* sym: ?func_00011C80@Object_000FBFD0@@UAEXH@Z = 0x000FC370 */
struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C90_5();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C90_9();
    virtual void func_00011C80_4(int argument);

    unsigned int flags;
    int id;
    unsigned int mask;
    float depth;
    int sortKey;
    char unknown_18[0xc];
    Node *parent;
    Node *child;
    Node *previous;
    Node *next;
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
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
    virtual void __stdcall slot30();
    virtual void __stdcall slot31();
    virtual void __stdcall slot32();
    virtual void __stdcall slot33(float value);
};

extern Device_00251D6C *data_00251D6C;

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Light_00046920 {
    int unknown_00;
    unsigned int color_04;
    unsigned int color_08;
    int unknown_0c;
    Vector3 direction;
    char unknown_1c[0x24];
    unsigned int color_40;
    int unknown_44;
    unsigned int color_48;
    int unknown_4c;
    int value_50;
    char unknown_54[0x1c];
};

struct Object_00046670 {
    void func_000466D0();
    void func_00046740(Light_00046920 *light);
    void func_00046940(int enable);
    void func_00046A30();
};

extern Object_00046670 data_001F93C8;
extern Light_00046920 *data_001F963C;

void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void func_001BB650(float scale);

// The class whose constructor func_000FBFD0 runs entry `mode` (at 0x58) of the member-function table at 0x21FDA8
// on itself (table 0x1D1B68).
struct Object_000FBFD0 : Node {
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    int unknown_040;
    unsigned int bits;
    float position[3];
    int kind;
    int mode;
    unsigned int flags_5c;
};

extern void (Object_000FBFD0::*data_0021FDC0[])();

// Slot 3: unless bit 29 of 0x5c is set, message 0, 3, 5 or 8 draws at the position (kind 0x2c with a white light from
// straight ahead, bit 31 of 0x5c scaled by 8) through the handler of data_0021FDC0 for the mode; message 7 sets the
// depth to 0.9.
void Object_000FBFD0::func_00011C80(int argument)
{
    if (flags_5c & 0x20000000) {
        return;
    }
    switch (argument) {
    case 0:
    case 3:
    case 5:
    case 8:
        data_00251D6C->slot33(-25.0f);
        func_001BAA00();
        if (kind == 0x2c) {
            Light_00046920 light = *data_001F963C;
            light.direction.x = 0.0f;
            light.direction.y = 0.0f;
            light.direction.z = 1.0f;
            light.value_50 = 0;
            light.color_04 = 0xffffff;
            light.color_08 = 0;
            data_001F93C8.func_000466D0();
            data_001F93C8.func_00046740(&light);
            data_001F93C8.func_00046940(0);
        }
        func_001BAAA0(position);
        if (flags_5c & 0x80000000) {
            func_001BB650(8.0f);
        }
        (this->*data_0021FDC0[mode])();
        if (kind == 0x2c) {
            data_001F93C8.func_00046A30();
        }
        func_001BAA50();
        data_00251D6C->slot33(0.0f);
        break;
    case 7:
        depth = 0.9f;
        break;
    }
}
