struct Vector3 {
    float x;
    float y;
    float z;
};

struct Rotation_000D2B90 {
    Vector3 axis;
    int angle;
};

struct Matrix_001BA950 {
    float m[16];
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAAE0(float *vector);
void __fastcall func_001BA950(Matrix_001BA950 *matrix);
void __fastcall func_001BAC70(Rotation_000D2B90 *rotation);
void __fastcall func_0014C3B0(Vector3 *out, const Vector3 *a, const Vector3 *b);
void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);
float __fastcall func_0014C460(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);
int func_0014C7A0(float cosine);
float func_0014C7F0(float value);

// The zero in .rdata, read as a variable.
extern float data_001C43D0;

// The forward axis the trail segments are turned from.
extern Vector3 data_00218E64;

// A joint of a skinned model (0x6c bytes): its scale at 0x14.
struct Joint_000E6F70 {
    char unknown_00[0x14];
    Vector3 scale;
    char unknown_20[0x4c];
};

// The skinned trail model at 0x53c: its joints at 0x8 and matrices at 0x20.
struct Object_00047470 {
    virtual ~Object_00047470();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void func_00047690(int first, int second);
    virtual void func_00047820(int argument);

    char unknown_04[4];
    Joint_000E6F70 *joints;
    char unknown_0c[0x14];
    Matrix_001BA950 *matrices;

    void func_000480C0(unsigned int index);
    void func_00048000();
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

// The child of Node whose table is at 0x1CEDA0: a ring of 95 trail points at 0xa8 (the next one at 0x51c) and the
// models at 0x538.
struct Object_000E6E80 : Node {
    virtual ~Object_000E6E80();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    void func_000E6F70();

    char unknown_044[0x64];
    Vector3 trail[95];
    int index;
    char unknown_520[0x18];
    Object_00047470 *models[3];
};

// Draws the trail: model 0 at the newest point turned from data_00218E64 toward the segment before it, then model 1
// as runs of 19 joints, each joint at the next older point turned the same way (half a turn when the segment points
// back; the last turn is kept when func_0014C460 gives a negative length or the points ran out), until all 95 points
// are laid; model 2 last.
void Object_000E6E80::func_000E6F70()
{
    int current = index - 1;
    if (current < 0) {
        current = 94;
    }
    int previous = current - 1;
    if (previous < 0) {
        previous = 94;
    }
    Object_00047470 *model = models[1];
    unsigned int count = 0;
    Rotation_000D2B90 rotation;
    rotation.angle = 0;
    rotation.axis.x = 0.0f;
    rotation.axis.y = 1.0f;
    rotation.axis.z = 0.0f;
    Vector3 offset;
    func_0014C4C0(&offset, &trail[previous], &trail[current]);
    func_0014C410(&offset, &offset);
    float cosine = func_0014C800(&offset, &data_00218E64);
    if (func_0014C7F0(cosine) < 0.999f) {
        func_0014C3B0(&rotation.axis, &data_00218E64, &offset);
        func_0014C410(&rotation.axis, &rotation.axis);
        rotation.angle = func_0014C7A0(cosine);
    } else if (cosine < 0.0f) {
        rotation.angle = 0x8000;
    }
    func_001BA9C0();
    func_001BAAA0(&trail[current].x);
    func_001BAC70(&rotation);
    func_001BA950(&model->matrices[19]);
    models[0]->func_00047690(0, 0);
    func_001BAA50();
    do {
        func_001BA9C0();
        model->func_000480C0(19);
        func_001BA950(&model->matrices[0]);
        func_001BAA50();
        for (unsigned int i = 1; i < 20; i++) {
            if (count >= 94 ||
                (func_0014C4C0(&offset, &trail[previous], &trail[current]),
                 func_0014C460(&offset, &offset) >= 0.0f)) {
                cosine = func_0014C800(&offset, &data_00218E64);
                if (func_0014C7F0(cosine) < 0.999f) {
                    func_0014C3B0(&rotation.axis, &data_00218E64, &offset);
                    func_0014C410(&rotation.axis, &rotation.axis);
                    rotation.angle = func_0014C7A0(cosine);
                } else {
                    float zero = data_001C43D0;
                    rotation.axis.y = 1.0f;
                    if (cosine < zero) {
                        rotation.axis.x = rotation.axis.z = zero;
                        rotation.angle = 0x8000;
                    } else {
                        rotation.axis.x = rotation.axis.z = zero;
                        rotation.angle = 0;
                    }
                }
            }
            func_001BA9C0();
            func_001BAAA0(&trail[current].x);
            func_001BAC70(&rotation);
            func_001BAAE0(&model->joints[i].scale.x);
            func_001BA950(&model->matrices[i]);
            func_001BAA50();
            count++;
            if (--current < 0) {
                current = 94;
            }
            if (--previous < 0) {
                previous = 94;
            }
        }
        model->func_00048000();
        model->func_00047820((int)model);
    } while (count < 95);
    func_001BA9C0();
    model->func_000480C0(19);
    models[2]->func_00047690(0, 0);
    func_001BAA50();
}
