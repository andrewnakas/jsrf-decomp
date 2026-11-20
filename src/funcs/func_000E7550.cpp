/* sym: ?func_00011C80@Object_000E6E80@@UAEXH@Z = 0x000E7550 */
struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

// The models at 0x534..0x540; slot 5 draws.
struct Model_000E7550 {
    virtual void func_0();
    virtual void func_1();
    virtual void func_2();
    virtual void func_3();
    virtual void func_4();
    virtual void func_5(int first, int second);

    char unknown_04[0x54];
    float fade;
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
};

// The child of Node whose table is at 0x1CEDA0; its handlers (table at 0x218E4C) run by the state at 0x9c.
struct Object_000E6E80 : Node {
    virtual ~Object_000E6E80();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    void func_000E6F70();

    char unknown_044[0x24];
    Vector3 previous;
    char unknown_074[0x1c];
    int angles[3];
    char unknown_09c[4];
    unsigned int flags_a0;
    char unknown_0a4[0x48c];
    float fade;
    Model_000E7550 *model;
    Model_000E7550 *models[3];
};

// Slot 3: on pass 0 (unless flag 1 at 0xa0) draws the model at 0x534 at the point at 0x68 turned by the angles at
// 0x90; on pass 7 keeps that point's depth at 0x10; on pass 8 gives the three models at 0x538 the fade at 0x530 and
// runs func_000E6F70.
void Object_000E6E80::func_00011C80(int argument)
{
    switch (argument) {
    case 0:
        if (!(flags_a0 & 1)) {
            func_001BAAA0(&previous.x);
            func_001BB330(angles[1] + 0x8000);
            func_001BB2E0(angles[0]);
            func_001BB380(angles[2]);
            model->func_5(0, 0);
        }
        break;
    case 7: {
        func_001BAAA0(&previous.x);
        Vector3 point;
        func_001BAB20(&point, 0);
        depth = point.z;
        break;
    }
    case 8:
        models[0]->fade = fade;
        models[1]->fade = fade;
        models[2]->fade = fade;
        func_000E6F70();
        break;
    }
}
