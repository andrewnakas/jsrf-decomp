/* sym: ?func_00011C80@Object_00102480@@UAEXH@Z = 0x00102490 */
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

// A model from func_00025700; its slot 5 poses it, its alpha is at 0x58.
struct Model_00102480 {
    virtual void func_00();
    virtual void func_04();
    virtual void func_08();
    virtual void func_0C();
    virtual void func_10();
    virtual void func_14(Motion_0005F060 *motion, float time);

    char unknown_04[0x54];
    float alpha;
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

void func_001BAA00();
void __fastcall func_001BAAA0(float *vector);
void func_001BB630(float distance);
void func_001BB650(float distance);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB2E0(int angle);
void func_001BAA50();

// A direct child of Node (table 0x1D1DD0, destructor func_00102480).
struct Object_00102480 : Node {
    virtual ~Object_00102480();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C80_4(int argument);

    int unknown_040;
    int unknown_044;
    Vector3 position;
    char unknown_054[4];
    int mode;
    char unknown_05c[0x1c];
    int pitch;
    int angle;
    char unknown_080[0x1c];
    Model_00102480 *model;
    float alpha;
};

// Slot 3, the message handler: on 0, 3, 5 and 8, while the alpha at 0xa0 is above 0, draws the model at 0x9c (with
// that alpha while it is below 1) at the position at 0x48, by 32 and -12 (func_001BB630, func_001BB650), turned by the
// angle at 0x7c and in mode 1 the pitch at 0x78, with device slot 33 at -24.9. On 7, depth 0.9.
void Object_00102480::func_00011C80(int argument)
{
    switch (argument) {
    case 0:
    case 3:
    case 5:
    case 8:
        if (alpha > 0.0f) {
            data_00251D6C->slot33(-24.9f);
            func_001BAA00();
            func_001BAAA0(&position.x);
            func_001BB630(32.0f);
            func_001BB650(-12.0f);
            func_001BB330(angle);
            if (mode == 1) {
                func_001BB2E0(pitch);
            }
            if (model) {
                if (alpha < 1.0f) {
                    model->alpha = alpha;
                }
                model->func_14(0, 0.0f);
                if (alpha < 1.0f) {
                    model->alpha = 1.0f;
                }
            }
            func_001BAA50();
            data_00251D6C->slot33(0.0f);
        }
        break;
    case 7:
        depth = 0.9f;
        break;
    }
}
