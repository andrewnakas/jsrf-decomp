/* sym: ?func_00011C80@Object_0007C250@@UAEXH@Z = 0x0007DA30 */
struct Node {
    Node(Node *owner, int id, unsigned int flags);
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
    virtual void __stdcall slot31(unsigned int value, float first, float second);
    virtual void __stdcall slot32();
    virtual void __stdcall slot33(float value);
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
    virtual void __stdcall slot73();
    virtual void __stdcall slot74();
    virtual void __stdcall slot75();
    virtual void __stdcall slot76();
    virtual void __stdcall slot77();
    virtual void __stdcall slot78(int value);
};

struct Vector3 {
    float x;
    float y;
    float z;
};

extern Device_00251D6C *data_00251D6C;
extern int data_00251D84;
extern float data_0020D428;
extern Vector3 data_0020D410;
extern Vector3 data_0020D41C;

// Sets the render state at 0x251D84 when it changes.
inline void setState_0007DA30(int value)
{
    if (data_00251D84 != value) {
        data_00251D84 = value;
        data_00251D6C->slot78(value);
    }
}

void __fastcall func_001BAF70(Vector3 *eye, Vector3 *target, int roll);

// The class whose table is at 0x1CCEF8: overrides slots 1 (7D6E0), 3 (7DA30).
struct Object_0007C250 : Node {
    virtual ~Object_0007C250();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    int step;
    int state;
    int unknown_4c[5];
    int unknown_60;
    int unknown_64[3];
    int unknown_70;
    int unknown_74;
    int unknown_78;
    int unknown_7c;
    int unknown_80;
};

extern void (Object_0007C250::*data_0020D3E0[])();

// Slot 3: draws the current step (handler table at 0x20D3E0) with the view from 0x20D410 to 0x20D41C, with the
// render state at 0x251D84 off and the bias at 0x20D428, and restores both.
void Object_0007C250::func_00011C80(int argument)
{
    int saved = data_00251D84;
    setState_0007DA30(0);
    data_00251D6C->slot33(data_0020D428);
    data_00251D6C->slot31(0xb6, 1.0f, 4000.0f);
    func_001BAF70(&data_0020D410, &data_0020D41C, 0);
    (this->*data_0020D3E0[step])();
    data_00251D6C->slot33(0.0f);
    setState_0007DA30(saved);
}
