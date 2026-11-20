/* sym: ?func_00011C80@Object_000C4510@@UAEXH@Z = 0x000C47F0 */
struct Frame_000479D0;
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Point_000C4510 {
    Vector3 position;
    float w;
};

struct Matrix_001BA950 {
    float m[4][4];
};

struct Motion_0005F060 {
    short unknown_00;
    short frames;
};

void __fastcall func_001BADB0(Vector3 *position);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

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

// The models' base (tables 0x1CA490, 0x1CAA8C, 0x1CC12C): slot 5 poses the model.
struct Object_00047470 {
    virtual ~Object_00047470();
    virtual void slot1();
    virtual void func_00047470(void *first, void *second, Frame_000479D0 *frame);
    virtual void slot3();
    virtual void func_00047540();
    virtual void func_00047690(int first, int second);

    char unknown_04[0x1c];
    Matrix_001BA950 *matrices;
    char unknown_24[0x34];
    float frame;

    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

// The child of Node with the table at 0x1CDDE0 (constructor func_000C4510, 0xa8 bytes; its implicit destructor and
// deleting destructor are folded into the camera node's, 0x121D0 and 0x121B0): a model (0x44) posed from a motion
// (0x48) at a frame (0x50) under its own matrix (0x54), of a kind (0x94).
struct Object_000C4510 : Node {
    Object_000C4510(Node *owner, int id, unsigned int flags, int kind);
    virtual ~Object_000C4510();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_40[4];
    Object_00047470 *model;
    Motion_0005F060 *motion;
    float time;
    float frame;
    Matrix_001BA950 matrix;
    int kind;
    int parts[4];
};

// Slot 3: multiplies its matrix in (func_001BADB0); message 7 sets the depth to the z of the origin seen through
// it (func_001BAB20), message 8 poses the model at the frame (slot 5 with the motion at 0x48 and 0x4c).
void Object_000C4510::func_00011C80(int argument)
{
    func_001BADB0((Vector3 *)&matrix);
    switch (argument) {
    case 7: {
        Vector3 point;
        func_001BAB20(&point, 0);
        depth = point.z;
        break;
    }
    case 8:
        model->frame = frame;
        model->func_00047690((int)motion, *(int *)&time);
        break;
    }
}
