struct Vector3 {
    float x;
    float y;
    float z;
};

struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int flags);
void func_001BA9C0();
void func_001BAA50();
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void func_000EB540(Vector3 *position, int column, int row);

extern Vector3 data_0021A168;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int id, void *data, Vector3 *position);
};

struct Object_00047470 {
    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

// The object a behaviour serves.
struct Object_000C5B50 {
    int func_000C5B10(int message, void *data);
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

// The second base (table 0x1CE1B8), two slots.
struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

// The motion set at 0x144.
struct MotionSet_000EC3E0 {
    char unknown_00[0xc];
    Motion_0005F060 *motion_0c;
};

// The class whose tables are at 0x1CEF20 (Node) and 0x1CEF18 (Object_000C60C0 at +0x44).
struct Object_000ECB50 : Node, Object_000C60C0 {
    virtual ~Object_000ECB50();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    void func_000EC3E0();

    char unknown_048[0x68];
    Object_000C5B50 *owner;
    char unknown_0b4[0x74];
    int state;
    char unknown_12c[8];
    unsigned int row;
    unsigned int column;
    char unknown_13c[4];
    Object_00047470 *model;
    MotionSet_000EC3E0 *set;
    Motion_0005F060 *motion_148;
    Motion_0005F060 *motion_14c;
    void *data_150;
    float time_154;
    float time_158;
};

// A handler of the member pointers at 0x258520: steps the motions at 0x148 and 0x14c by half a frame; once the one
// at 0x14c is through, state 3 with the set's motion 0xc there from 0, the model posed (func_00047970 with the data
// at 0x150, frame 0), a func_000EB540 object at the point data_0021A168 of the model's matrix for the column at 0x138
// and the row at 0x134, sound 0x3d and message 0x32 to the owner at 0xb0 there; the column counts 0..2.
void Object_000ECB50::func_000EC3E0()
{
    func_0005E030(motion_148, &time_154, 0.5f, 0);
    if (func_0005E030(motion_14c, &time_158, 0.5f, 1)) {
        state = 3;
        motion_14c = set->motion_0c;
        time_158 = 0.0f;
        func_001BA9C0();
        model->func_00047970(data_150, 0);
        model->func_000480C0(0);
        Vector3 position;
        func_001BAB20(&position, &data_0021A168);
        func_001BAA50();
        func_000EB540(&position, column, row);
        Object_000607B0 *sounds = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (sounds) {
            sounds->func_000651E0(0x3d, &position, 0);
        }
        owner->func_000C5B10(0x32, &position);
        if (++column > 2) {
            column = 0;
        }
    }
}
