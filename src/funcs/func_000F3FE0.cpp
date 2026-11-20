/* sym: ?func_00011C80@Object_000F44E0@@UAEXH@Z = 0x000F3FE0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Motion_0005F060;

struct Item_000162A0 {
    char unknown_00[8];
};

struct Part_00017F60 {
    Vector3 center;
    float radius;
    Vector3 motion;
    char unknown_1c[8];
};

struct Mesh_00017F60 {
    Part_00017F60 *parts;
};

struct Object_00016200 {
    void func_00019570(Mesh_00017F60 *mesh, const Mesh_00017F60 *source);
    void func_000162A0(Item_000162A0 *item);
};

struct Object_000C1270 {
    int func_000C1160(int kind, int value, Vector3 *position);
    void func_000C1270(int handle, void *position);
};

// The model at 0x94: slot 5 draws the motion at a time.
struct Model_000F3FE0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(Motion_0005F060 *motion, float time);
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

// The child of Node whose table is at 0x1CF098 (constructor func_000F3E60, destructor func_000F3F70): its slot 1
// runs entry `state` of the member-function table at 0x21b2dc on itself.
struct Object_000F44E0 : Node {
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    int unknown_040;
    unsigned int state;
    Vector3 position;
    char unknown_054[0xc];
    int angle;
    float x;
    int unknown_068;
    float z;
    int count;
    char unknown_074[0x20];
    Model_000F3FE0 *model;
    Motion_0005F060 *motion;
    float time;
    char unknown_0a0[0x44];
    Item_000162A0 item;
    Mesh_00017F60 *mesh;
    char unknown_0f0[0x18];
    int handle;

};

int func_0005E030(Motion_0005F060 *motion, float *time, float step, int flag);
void __fastcall func_001BAAA0(float *position);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

// Slot 3: in pass 8, once past state 0, draws the model at the position and angle (plus a half turn); in any other
// pass, sets the depth at 0x10 from the transformed origin.
void Object_000F44E0::func_00011C80(int pass)
{
    if (pass == 8) {
        if (state > 0) {
            func_001BAAA0(&position.x);
            func_001BB330(angle + 0x8000);
            model->slot5(motion, time);
        }
    } else {
        Vector3 origin;
        func_001BAAA0(&position.x);
        func_001BAB20(&origin, 0);
        depth = origin.z;
    }
}
