/* sym: ?func_00011C80_4@Object_000667D0@@UAEXH@Z = 0x00066660 */
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
    char unknown_34[0x10];
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
    virtual long __stdcall slot31(long state, float first, float second);
    virtual void __stdcall slot32();
    virtual void __stdcall slot33(float value);
};

extern Device_00251D6C *data_00251D6C;
extern float data_001FB8C0[3];

void func_001BA8A0();
void __fastcall func_001BAAA0(float *vector);

struct Motion_0005F060;

struct Model_00066660 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(Motion_0005F060 *motion, float time);
};

// The class whose table is at 0x1CB0A8 (destructor 0x663E0): overrides slot 15 here.
struct Object_000667D0 : Node {
    virtual void func_00011C80_4(int argument);

    char unknown_44[0x60];
    unsigned int flags;
    char unknown_a8[0xc];
    Model_00066660 **models;
    Motion_0005F060 *motion;
    float time;
};

// Slot 15: with flag 8 and without flag 2, draws the first model posed by the motion (+0xb8, time +0xbc) and the
// second unposed at 0x1FB8C0, with device state 33 at -22.5 (back to 0 after) and slot 31 for state 0x222 (1000,
// 1300).
void Object_000667D0::func_00011C80_4(int)
{
    if ((flags & 8) && !(flags & 2)) {
        data_00251D6C->slot33(-22.5f);
        func_001BA8A0();
        data_00251D6C->slot31(0x222, 1000.0f, 1300.0f);
        func_001BAAA0(data_001FB8C0);
        models[0]->slot5(motion, time);
        models[1]->slot5(0, 0);
        data_00251D6C->slot33(0);
    }
}
