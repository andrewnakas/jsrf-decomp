/* sym: ?func_00011C90@Object_000C4510@@UAEXXZ = 0x000C4670 */
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

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Entry_000607B0;

struct Object_000607B0 {
    void func_000606C0(int key, Vector3 *value);
};

void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
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

// Slot 1: runs the motion at 0x48 (func_0005E030, half speed, once); at its end removes itself and everything below
// it (func_00011BE0, func_00011C20), and over its last 30 frames fades the frame at 0x50 by a sixtieth down to 0.
// With parts (0x98), poses the model and gives node 0xe8 (func_000606C0) the origin of bones 1 to 4 (kind 2) or 3 and 4
// (kind 3) for the parts.
void Object_000C4510::func_00011C90()
{
    if (!func_0005E030(motion, &time, 0.5f, 1)) {
        if (motion->frames - 1.0f - time <= 30.0f) {
            frame -= 0.016666668f;
            if (frame < 0.0f) {
                frame = 0.0f;
            }
        }
    } else {
        func_00011BE0(this);
        func_00011C20(child);
    }
    if (parts[0]) {
        Object_000607B0 *target = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (target) {
            model->func_00047970(motion, *(int *)&time);
            switch (kind) {
            case 2: {
                unsigned int bones[4] = {1, 2, 3, 4};
                for (unsigned int i = 0; i < 4; i++) {
                    model->func_000480C0(bones[i]);
                    Point_000C4510 point;
                    func_001BAB20(&point.position, 0);
                    target->func_000606C0(parts[i], &point.position);
                }
                break;
            }
            case 3: {
                unsigned int bones[2] = {3, 4};
                for (unsigned int i = 0; i < 2; i++) {
                    model->func_000480C0(bones[i]);
                    Point_000C4510 point;
                    func_001BAB20(&point.position, 0);
                    target->func_000606C0(parts[i], &point.position);
                }
                break;
            }
            }
        }
    }
}
