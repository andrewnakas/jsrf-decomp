/* sym: ?func_00011C80@Object_000DB3E0@@UAEXH@Z = 0x000DB5B0 */
struct Motion_0005F060;
struct Vector3;
struct Item_00017940;

struct Item_00016200 {
    Item_00017940 *handle;
    Item_00016200 *next;
};

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC50(int *angles, int order);

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

// A model: slot 5 poses it with a motion at a time.
struct Model_000DB3E0 {
    virtual void func_00();
    virtual void func_04();
    virtual void func_08();
    virtual void func_0C();
    virtual void func_10();
    virtual void func_14(Motion_0005F060 *motion, float time);

    char unknown_04[0x58];
    int value_5c;
};

// The class whose table is at 0x1CE740 (destructor func_000DB520).
struct Object_000DB3E0 : Node {
    virtual ~Object_000DB3E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    float position[3];
    int angles[3];
    char unknown_05c[4];
    Model_000DB3E0 *model_60;
    Model_000DB3E0 *model_64;
    Model_000DB3E0 *model_68;
    int value_6c;
    Motion_0005F060 *motion;
    float time;
    Item_00016200 link;
};

// Slot 3: places itself at 0x44; on event 2 keeps the depth of its origin, on 3, 13 and 17/18 turns by the angles at
// 0x50 and poses the model at 0x60 (with 0x6c at its 0x5c), 0x68 (with the motion at 0x70) or 0x64.
void Object_000DB3E0::func_00011C80(int event)
{
    float point[4];
    func_001BAAA0(position);
    switch (event) {
    case 3:
        func_001BAC50(angles, 0);
        model_60->value_5c = value_6c;
        model_60->func_14(0, 0.0f);
        break;
    case 2:
        func_001BAB20((Vector3 *)point, 0);
        depth = point[2];
        break;
    case 13:
        func_001BAC50(angles, 0);
        model_68->func_14(motion, time);
        break;
    case 17:
    case 18:
        func_001BAC50(angles, 0);
        model_64->func_14(0, 0.0f);
        break;
    }
}
