/* sym: ?func_00011C80@Object_00070BD0@@UAEXH@Z = 0x00070C90 */
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

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Interface_00070C90 {
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
    virtual void __stdcall slot12(int first, int second);
    virtual void __stdcall slot13(int value);
    virtual void __stdcall slot14(int first, void *data);
};

struct Motion_00070BE0 {
    short unknown_00;
    short frames;
};

struct Model_00070C90 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(Motion_00070BE0 *motion, float time);

    Interface_00070C90 *unknown_04;
    char unknown_08[0x1c];
    unsigned int flags;
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
void __fastcall func_001BAC50(int *angles, int zero);
void __fastcall func_001BB270(float *scale);

// The class whose table is at 0x1CCA38: overrides slots 1 (70BE0), 3 (70C90), 4 (AECC0), 6 (B3DE0), 7 (AECC0), 9 (B3DE0), 10 (AECC0), 12 (B3DE0), 13 (AECC0), 15 (B3DE0).
struct Object_00070BD0 : Node {
    virtual ~Object_00070BD0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C80_4(int argument);

    unsigned int unknown_44;
    int unknown_48;
    Vector3 unknown_4c;
    int unknown_58;
    int unknown_5c;
    Vector3 position;
    int angles[3];
    Vector3 scale;
    float unknown_84;
    int unknown_88;
    int unknown_8c;
    int unknown_90;
    int unknown_94;
    Model_00070C90 *model;
    Motion_00070BE0 *motion;
    float time;
    int unknown_a4;
    int phase;
    int unknown_ac;
    int unknown_b0[6];
    int hasB0;
};

// Slot 3: message 0, 3 or 5 draws the model at its place (with a white light from straight ahead when +0x44 has its
// top bit); message 7 sets the depth to 0.9.
void Object_00070BD0::func_00011C80(int argument)
{
    switch (argument) {
    case 0:
    case 3:
    case 5:
    case 8:
        data_00251D6C->slot33(unknown_84 - 25.0f);
        func_001BAA00();
        if (unknown_44 & 0x80000000) {
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
        func_001BAAA0(&unknown_4c.x);
        func_001BAAA0(&position.x);
        func_001BAC50(angles, 0);
        func_001BB270(&scale.x);
        if (model) {
            if (hasB0) {
                model->unknown_04->slot12(0, 7);
                model->unknown_04->slot14(0, unknown_b0);
            }
            model->slot5(motion, time);
            if (hasB0) {
                model->unknown_04->slot13(0);
            }
        }
        if (unknown_44 & 0x80000000) {
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
