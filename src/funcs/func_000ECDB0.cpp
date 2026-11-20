/* sym: ?func_00011C90@Object_000ECB50@@UAEXXZ = 0x000ECDB0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 target;
};

extern Object_000C1270 *data_00257CE4;

struct Object_0006DB80 {
    void func_0006DFC0(int key, const Vector3 *position);
};

extern Object_0006DB80 data_00251F78;

struct Object_00047470 {
    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
float __fastcall func_0014C530(const Vector3 *a, const Vector3 *b);

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

// The second base (table 0x1CE1B8), two slots.
struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

// The part at 0xbc (built by func_000EB830).
struct Object_000EBB80 {
    void func_000EBB80(Object_00047470 *model);

    char unknown_00[0x6c];
};

// The class whose tables are at 0x1CEF20 (Node) and 0x1CEF18 (Object_000C60C0 at +0x44).
struct Object_000ECB50 : Node, Object_000C60C0 {
    virtual ~Object_000ECB50();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    void func_000EC720();
    void func_000EC7E0();
    void func_000EC990();

    Vector3 position;
    char unknown_054[0x20];
    float distance;
    char unknown_078[0x18];
    unsigned int flags_90;
    char unknown_094[0x28];
    Object_000EBB80 part;
    int state;
    char unknown_12c[0x14];
    Object_00047470 *model;
    char unknown_144[0xc];
    void *data_150;
    char unknown_154[0x220];
    int effect_374;
};

// The handlers slot 1 runs by the state at 0x128 (filled in by the dynamic initializer func_0018C0C0).
extern void (Object_000ECB50::*data_00258520[])();

// Slot 1: runs the handler of the state at 0x128, func_000EC720, the model's func_00047970 with the data at 0x150 and
// func_000EC7E0; unless the flag 0x4000000 is set at 0x90: func_000EC990, frame 0 of the model, the position at 0x48
// set (func_001BAB20), its distance to the point at 0x7c of data_00257CE4 kept at 0x74, the part at 0xbc drawn with
// the model (func_000EBB80), and with an effect at 0x374, the position set again and handed to data_00251F78 with it.
void Object_000ECB50::func_00011C90()
{
    (this->*data_00258520[state])();
    func_000EC720();
    model->func_00047970(data_150, 0);
    func_000EC7E0();
    if (!(flags_90 & 0x4000000)) {
        func_000EC990();
        model->func_000480C0(0);
        func_001BAB20(&position, 0);
        distance = func_0014C530(&position, &data_00257CE4->target);
        part.func_000EBB80(model);
        if (effect_374 != -1) {
            func_001BAB20(&position, 0);
            data_00251F78.func_0006DFC0(effect_374, &position);
        }
    }
}
