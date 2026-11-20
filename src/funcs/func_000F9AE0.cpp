/* sym: ?func_00011C80@Object_000F98B0@@UAEXH@Z = 0x000F9AE0 */
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

struct Motion_0005F060;

// A model with a colour (func_00047F40); its slot 5 poses it.
struct Model_00133370 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);

    void func_00047F40(int value);
};

unsigned int func_0014C690(float value);
float func_0003D750(float scale, int text);
void func_0003D5D0(float x, float y, float scale, unsigned int color, float first, float second, int text);
void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);

// The child of Node whose table is at 0x1D08A0 (constructor func_000F98B0): three models at 0x48, the fade at 0x5c,
// the selection at 0x64, the position at 0x68 and a text at 0x84.
struct Object_000F98B0 : Node {
    virtual void func_00011C80(int argument);

    char unknown_040[8];
    Model_00133370 *models[3];
    char unknown_054[8];
    float fade;
    char unknown_060[4];
    int *selection;
    float position[3];
    char unknown_074[0x10];
    int text;
};

// Slot 3: message 0 or 8 draws the three models at the position (the selected one of the first two in the colour of
// the fade, 0xffffAAAA with AA = fade * 255) and the text at 0x84 centred on x 320 at y 210; message 7 sets the depth
// to 1.
void Object_000F98B0::func_00011C80(int argument)
{
    switch (argument) {
    case 0:
    case 8: {
        unsigned int alpha = func_0014C690(fade * 255.0f);
        data_00251D6C->slot33(-27.0f);
        func_001BAA00();
        func_001BAAA0(position);
        if (models[0]) {
            if (*selection == 0) {
                models[0]->func_00047F40(((alpha | 0xffffff00) << 8) | alpha);
            }
            models[0]->slot5(0, 0);
            if (*selection == 0) {
                models[0]->func_00047F40(-1);
            }
        }
        if (models[1]) {
            if (*selection == 1) {
                models[1]->func_00047F40(((alpha | 0xffffff00) << 8) | alpha);
            }
            models[1]->slot5(0, 0);
            if (*selection == 1) {
                models[1]->func_00047F40(-1);
            }
        }
        if (models[2]) {
            models[2]->slot5(0, 0);
        }
        func_001BAA50();
        data_00251D6C->slot33(0.0f);
        if (text) {
            float width = func_0003D750(1.0f, text);
            float half = width * 0.5f;
            float x = 320.0f - half;
            func_0003D5D0(x, 210.0f, 1.1f, 0xff000000, 1.0f, 1.0f, text);
        }
        break;
    }
    case 7:
        depth = 1.0f;
        break;
    }
}
