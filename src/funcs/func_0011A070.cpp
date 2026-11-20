/* sym: ?func_00011C80@Object_0011A020@@UAEXH@Z = 0x0011A070 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// The device at data_00251D6C: slot 33 takes a float.
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

struct Transform_000704E0 {
    float scale;
    float unknown_04;
    float unknown_08;
    float unknown_0c;
    float unknown_10;
    float rate;
};

struct Record_0011A070 {
    unsigned int value;
    char unknown_04[4];
    int value_08;
    char unknown_0c[0x1c];
};

struct Object_00070850 {
    char unknown_00[0xe8];
    Record_0011A070 records[1];

    void func_000704E0(int index, Transform_000704E0 *transform);
    int func_00070990(int index);
};

struct Object_001197F0 {
    int func_00119C00();
    int func_00119C10();
};

// The interface a model keeps at +4 (stdcall slots 12-14).
struct Interface_0011A070 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5();
    virtual long __stdcall slot6();
    virtual long __stdcall slot7();
    virtual long __stdcall slot8();
    virtual long __stdcall slot9();
    virtual long __stdcall slot10();
    virtual long __stdcall slot11();
    virtual long __stdcall slot12(int stage, int value);
    virtual long __stdcall slot13(int stage);
    virtual long __stdcall slot14(int stage, Transform_000704E0 *transform);
};

// A model: slot 5 draws it.
struct Model_0011A070 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);

    Interface_0011A070 *effect;
};

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

    Node *func_00011BD0();
};

struct Object_0011A020 : Node {
    virtual ~Object_0011A020();
    virtual void func_00011C80(int argument);

    char unknown_44[4];
    int index;
    int target;
    Model_0011A070 *model;
    Model_0011A070 *marker;
    Vector3 *positions;
    Vector3 position;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
extern Device_00251D6C *data_00251D6C;
extern Vector3 data_00224FF8[];

void func_001BA9C0();
void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *position);

// Slot 3 of the class whose table is at 0x1D7BA0. Messages 0, 3, 5 and 8 draw it with slot 33 of the device at
// -26: at +0x5c, the model at +0x50 at entry +0x48 (+4) of the points at +0x58 when the object named at +0x4c is
// active (func_00119C10) and its record in the owner (func_00011BD0) is set, with the owner's transform for it
// (func_000704E0) on stage 0, and the marker at +0x54 at data_00224FF8's point when func_00070990 of the owner
// allows it. Message 7 sets the depth to 0.9.
void Object_0011A020::func_00011C80(int argument)
{
    Object_00070850 *owner = (Object_00070850 *)func_00011BD0();
    Object_001197F0 *object = (Object_001197F0 *)data_0022FCE0->func_000128C0(target);
    switch (argument) {
    case 0:
    case 3:
    case 5:
    case 8:
        data_00251D6C->slot33(-26.0f);
        func_001BAA00();
        func_001BAAA0(&position.x);
        if (object->func_00119C10() && owner->records[object->func_00119C00()].value_08 && model) {
            func_001BA9C0();
            func_001BAAA0(&positions[index + 4].x);
            Transform_000704E0 transform;
            owner->func_000704E0(object->func_00119C00(), &transform);
            model->effect->slot12(0, 7);
            model->effect->slot14(0, &transform);
            model->slot5(0, 0);
            model->effect->slot13(0);
            func_001BAA50();
        }
        if (owner->func_00070990(index) && marker) {
            func_001BA9C0();
            func_001BAAA0(&data_00224FF8[index].x);
            marker->slot5(0, 0);
            func_001BAA50();
        }
        func_001BAA50();
        data_00251D6C->slot33(0.0f);
        break;
    case 7:
        depth = 0.9f;
        break;
    }
}
