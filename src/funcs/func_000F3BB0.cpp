/* sym: ?func_00011C80_3@Object_000F37B0@@UAEXH@Z = 0x000F3BB0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Motion_0005F060;

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *first, const Vector3 *second);
void __fastcall func_0014C730(Vector3 *out, Vector3 *in, float scale);
void __fastcall func_0014C8B0(Vector3 *out, const Vector3 *first, const Vector3 *second, float share);
int func_0014C7D0(float x, float z);
void func_001BB630(float value);
void func_001BB650(float distance);
int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

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
    virtual void __stdcall slot74(int state, int value);
};

extern Device_00251D6C *data_00251D6C;

// The model drawn for each segment: slot 5 with the motion and its time; its fade at 0x58.
struct Model_000F3A20 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void draw(Motion_0005F060 *motion, float time);

    char unknown_04[0x54];
    float fade;
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

// The child of Node whose table is at 0x1CF058 (constructor func_000F37B0).
struct Object_000F37B0 : Node {
    virtual void func_00011C80_3(int argument);

    char unknown_040[4];
    Vector3 points[0x96];
    unsigned int count;
    char unknown_750[4];
    float fade;
    Model_000F3A20 *model;
    Motion_0005F060 *motion;
    float time;
};

// Slot 12 (a second pass), with at least two of the points at 0x44 (count at 0x74c). Pass 12 keeps the z of the
// transformed midpoint of the first and last points as the node's depth. Pass 13 sets the model's fade from 0x754
// and, with device state 0x302 at 1, draws the model at the middle of each segment turned along it (func_0014C7D0 +
// 0x4000), stretched by -1 and 2 (func_001BB630, func_001BB650), running the motion at 0x75c from the time at 0x760
// at half speed per segment (func_0005E030); then sets the state back to 0x303 and runs the motion's own time on.
void Object_000F37B0::func_00011C80_3(int argument)
{
    if (count < 2) {
        return;
    }
    switch (argument) {
    case 12: {
        Vector3 middle;
        func_0014C8B0(&middle, &points[0], &points[count - 1], 0.5f);
        func_001BAB20(&middle, &middle);
        depth = middle.z;
        break;
    }
    case 13: {
        float segmentTime = time;
        model->fade = fade;
        data_00251D6C->slot74(0x302, 1);
        for (unsigned int i = 1; i < count; i++) {
            Vector3 point = points[i];
            Vector3 difference;
            func_0014C4C0(&difference, &point, &points[i - 1]);
            int angle = func_0014C7D0(difference.x, difference.z);
            func_0014C730(&point, &difference, 0.5f);
            func_001BA9C0();
            func_001BAAA0(&point.x);
            func_001BB330(angle + 0x4000);
            func_001BB630(-1.0f);
            func_001BB650(2.0f);
            model->draw(motion, segmentTime);
            func_001BAA50();
            func_0005E030(motion, &segmentTime, 0.5f, 0);
        }
        data_00251D6C->slot74(0x302, 0x303);
        func_0005E030(motion, &time, 0.5f, 0);
        break;
    }
    }
}
