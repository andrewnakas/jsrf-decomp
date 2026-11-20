/* sym: ?func_00011C90@Object_000E45D0@@UAEXXZ = 0x000E4910 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Rotation_000E45D0 {
    int x;
    int y;
    int z;
};

struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 position;
};

extern Object_000C1270 *data_00257CE4;

struct Object_0003E750 {
    void func_0003F410(int key, int value);
};

extern Object_0003E750 data_002314B0;

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 {
    void func_000C1EA0(int key);
};

extern Object_00157F10 *data_00257CE8;

struct Object_00047470 {
    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

struct Holder_000E45D0 {
    Object_00047470 *model;
};

float __fastcall func_0014C530(const Vector3 *a, const Vector3 *b);
void func_001BAA00();
void func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

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


// The class whose tables are at 0x1CED20 (Node) and 0x1CED18 (Object_000C60C0 at +0x44); slot 15 holds a folded
// thunk.
struct Object_000E45D0 : Node, Object_000C60C0 {
    virtual ~Object_000E45D0();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    void func_000E3F10();
    void func_000E4250();

    Vector3 position;
    Rotation_000E45D0 rotation;
    char unknown_060[0x14];
    float distance;
    char unknown_078[0x44];
    int state;
    char unknown_0c0[0xa4];
    Holder_000E45D0 *holder;
    char unknown_168[4];
    void *data_16c;
    char unknown_170[0xa8];
    int effect;
};

// The handlers slot 1 runs by the state at 0xbc (filled in by a dynamic initializer).
extern void (Object_000E45D0::*data_00258470[])();

// Slot 1: runs the handler of the state and func_000E4250, keeps the distance from the position to the point at 0x7c
// of data_00257CE4 at 0x74, then inside a matrix placed and turned by 0x48 and 0x54 poses the holder's model with the
// data at 0x16c and runs func_000E3F10; with an effect at 0x218, frame 2 of the model and the effect shown (with
// func_000C1EA0) within 100 of the point, else hidden.
void Object_000E45D0::func_00011C90()
{
    (this->*data_00258470[state])();
    func_000E4250();
    distance = func_0014C530(&position, &data_00257CE4->position);
    func_001BAA00();
    func_001BAAA0(&position.x);
    func_001BB330(rotation.y + 0x8000);
    func_001BB2E0(rotation.x);
    func_001BB380(rotation.z);
    holder->model->func_00047970(data_16c, 0);
    func_000E3F10();
    if (effect != -1) {
        holder->model->func_000480C0(2);
        if (distance < 100.0f) {
            data_002314B0.func_0003F410(effect, 1);
            data_00257CE8->func_000C1EA0(effect);
        } else {
            data_002314B0.func_0003F410(effect, 0);
        }
    }
    func_001BAA50();
}
