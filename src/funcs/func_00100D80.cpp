/* sym: ?func_00011C80@Object_00100770@@UAEXH@Z = 0x00100D80 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAF70(Vector3 *eye, Vector3 *target, int roll);

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
    virtual void __stdcall slot31(int state, float nearDepth, float farDepth);
    virtual void __stdcall slot32();
    virtual void __stdcall slot33(float value);
    virtual void __stdcall slot34();
    virtual void __stdcall slot35();
    virtual void __stdcall slot36(void *out, Vector3 *point);
};

extern Device_00251D6C *data_00251D6C;

// The owner the id at 0x90 names: the camera's id at 0x16b8.
struct Object_00107FE0 {
    char unknown_0000[0x16b8];
    int cameraId;

    int func_001084E0(int kind);
};

// The object the camera follows: a point at 0xcf8.
struct Target_00100D80 {
    char unknown_000[0xcf8];
    Vector3 point;
};

// The camera: its target at 0x24, eye 0x44, focus 0x5c, roll 0x7c, mode 0x208, state 0x22c.
struct Camera_00100D80 {
    char unknown_000[0x24];
    Target_00100D80 *target;
    char unknown_028[0x1c];
    Vector3 eye;
    char unknown_050[0xc];
    Vector3 focus;
    char unknown_068[0x14];
    int roll;
    char unknown_080[0x188];
    int mode;
    char unknown_20c[0x20];
    int state;
};

// A model: slot 5 draws it.
struct Model_00100D80 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void draw(int first, int second);
};

struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);

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

// The child of Node whose table is at 0x1D1D00 (constructor func_001005F0).
struct Object_00100770 : Node {
    virtual void func_00011C80(int argument);

    char unknown_040[0xc];
    Model_00100D80 *model;
    int first;
    int second;
    char unknown_058[8];
    int mode;
    char unknown_064[8];
    char screen[8];
    Vector3 position;
    char unknown_080[0xc];
    int shown;
    int ownerId;

    void func_00100780(Vector3 *point);
};

// Slot 3 (the pass), unless the owner's camera (id at 0x16b8) is in mode 14, and only in mode 0x60 or while the
// owner's func_001084E0(5) gives something. Passes 2 and 7 set the node's depth to 0.9. Passes 0, 3, 5 and 8, with
// 0x8c set and a model: through the camera's view (eye, focus, roll; device slot 31 with its state 0x22c) projects
// the camera target's point at 0xcf8 to 0x6c (device slot 36); if it lies beyond 1, draws the model at 0x74 offset by
// func_00100780 (z flattened) with device slot 33 at -25.
void Object_00100770::func_00011C80(int argument)
{
    Object_00107FE0 *owner = (Object_00107FE0 *)data_0022FCE0->func_000128C0(ownerId);
    Camera_00100D80 *camera = (Camera_00100D80 *)data_0022FCE0->func_000128C0(owner->cameraId);
    if (camera && camera->mode == 14) {
        return;
    }
    if (!mode && !((unsigned int)owner->func_001084E0(5) > 0)) {
        return;
    }
    switch (argument) {
    case 0:
    case 3:
    case 5:
    case 8: {
        if (!shown) {
            return;
        }
        if (!model) {
            return;
        }
        Target_00100D80 *target = camera->target;
        int visible = 0;
        if (!target) {
            return;
        }
        func_001BAA00();
        data_00251D6C->slot31(camera->state, 1.0f, 4000.0f);
        func_001BAF70(&camera->eye, &camera->focus, camera->roll);
        Vector3 point;
        func_001BAB20(&point, &target->point);
        if (point.z > 1.0f) {
            visible = 1;
        }
        data_00251D6C->slot36(screen, &point);
        data_00251D6C->slot31(0x222, 1.0f, 4000.0f);
        func_001BAA50();
        if (!visible) {
            return;
        }
        data_00251D6C->slot33(-25.0f);
        func_001BAA00();
        func_001BAAA0(&position.x);
        func_00100780(&point);
        point.z = 0.0f;
        func_001BAAA0(&point.x);
        model->draw(first, second);
        func_001BAA50();
        data_00251D6C->slot33(0.0f);
        break;
    }
    case 2:
    case 7:
        depth = 0.9f;
        break;
    }
}
