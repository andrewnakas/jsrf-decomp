/* sym: ?func_00011C80@Object_000FF9B0@@UAEXH@Z = 0x000FFA80 */
struct Vector3 {
    float x;
    float y;
    float z;
};

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


struct Motion_0005F060;

// A model from func_00025700; its slot 5 poses it.
struct Model_000FF9B0 {
    virtual void func_00();
    virtual void func_04();
    virtual void func_08();
    virtual void func_0C();
    virtual void func_10();
    virtual void func_14(Motion_0005F060 *motion, float time);
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
    virtual void __stdcall slot73(int value);
};

extern Device_00251D6C *data_00251D6C;
extern int data_001FA1D0;

void func_001BA9C0();
void func_001BA8A0();
void __fastcall func_001BAAA0(float *vector);
void func_001BAA50();

// A direct child of Node (table 0x1D1C70, destructor func_000FF9B0): three sprites from func_00025700, the second
// chosen by the value at 0x44.
struct Object_000FF9B0 : Node {
    virtual ~Object_000FF9B0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C80_4(int argument);

    int unknown_40;
    int value;
    Model_000FF9B0 *sprite_48;
    Model_000FF9B0 *sprite_4c;
    Vector3 position;
    Motion_0005F060 *sprite_5c;
    int unknown_60;
    float time;
    int phase;
    int unknown_6c;
};

// Sets render state data_001FA1D0 through device slot 73 when it changes; the callers keep the old value.
inline void setState_000FFA80(int value)
{
    if (data_001FA1D0 != value) {
        data_001FA1D0 = value;
        data_00251D6C->slot73(value);
    }
}

// Slot 3, the message handler: on 0, 3, 5 and 8 draws: with render state data_001FA1D0 at 1 (device slot 73) and
// device slot 33 at -25, a matrix at the position at 0x50 (func_001BA9C0, func_001BA8A0, func_001BAAA0); the model at
// 0x4c unposed and the one at 0x48 posed by the motion at 0x5c at the time at 0x64; then slot 33 back to 0 and the
// render state restored. On 7, depth 1.
void Object_000FF9B0::func_00011C80(int argument)
{
    switch (argument) {
    case 0:
    case 3:
    case 5:
    case 8: {
        int saved = data_001FA1D0;
        setState_000FFA80(1);
        data_00251D6C->slot33(-25.0f);
        func_001BA9C0();
        func_001BA8A0();
        func_001BAAA0(&position.x);
        if (sprite_4c) {
            sprite_4c->func_14(0, 0.0f);
        }
        if (sprite_48) {
            sprite_48->func_14(sprite_5c, time);
        }
        func_001BAA50();
        data_00251D6C->slot33(0.0f);
        setState_000FFA80(saved);
        break;
    }
    case 7:
        depth = 1.0f;
        break;
    }
}
