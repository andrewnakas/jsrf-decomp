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

// The object a behaviour serves (at 0xb0).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;

    int func_000C5B10(int message, void *data);
    void func_000C5B40(int handle, void *data);
    int func_000C5B70(int handle);
};


struct Object_0003E750 {
    void func_0003F410(int key, int value);
};

extern Object_0003E750 data_002314B0;

// The object at data_00257CE8 (func_00157F10 is the engine's).
// The object in data_00257CE4.
struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 position;
    char unknown_88[0x18];
    Vector3 target;
};

extern Object_000C1270 *data_00257CE4;
extern Vector3 data_00218AD8;

void func_000C5670(void *parent, Vector3 *position, Vector3 *direction, int kind);
void __fastcall func_0014C500(Vector3 *direction, const Vector3 *from);

struct Object_00047470 {
    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

struct Holder_000E45D0 {
    Object_00047470 *model;
};

float __fastcall func_0014C530(const Vector3 *a, const Vector3 *b);
void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
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


// The class whose tables are at 0x1CED20 (Node) and the Object_000C60C0 part at +0x44.
struct Object_000E45D0 : Node, Object_000C60C0 {
    virtual ~Object_000E45D0();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    int func_000E4370();
    void func_000E4AB0();

    Vector3 position;
    Rotation_000E45D0 rotation;
    char unknown_060[0x14];
    float distance;
    char unknown_078[0x38];
    Object_000C5B50 *owner;
    char unknown_0b4[0xc];
    int timer;
    char unknown_0c4[8];
    Vector3 target;
    char unknown_0d8[0x6c];
    int value_144;
    char unknown_148[0x1c];
    Holder_000E45D0 *holder;
    char unknown_168[4];
    void *data_16c;
    char unknown_170[0xb8];
    int handle;
};

// A handler of the member pointers at 0x258470: sets 0x144 to 91 * (2 - distance / 300), aims at the point at 0x7c of
// data_00257CE4 lifted by 10 (func_000E4370); every 12 frames (0xc0) fires a func_000C5670 shot from the muzzle
// data_00218AD8 at bone 2 of the holder's model, posed at the position and turned by the rotation, toward the point at
// 0xa0 of data_00257CE4 (func_0014C500); then keeps the owner's message handle at 0x228 at the position.
void Object_000E45D0::func_000E4AB0()
{
    value_144 = (int)((2.0f - distance * 0.0033333334f) * 91.0f);
    target = data_00257CE4->position;
    target.y += 10.0f;
    func_000E4370();
    if (--timer <= 0) {
        timer = 12;
        Vector3 muzzle;
        Vector3 direction = data_00257CE4->target;
        func_001BA9C0();
        func_001BAAA0(&position.x);
        func_001BB330(rotation.y + 0x8000);
        func_001BB2E0(rotation.x);
        func_001BB380(rotation.z);
        holder->model->func_00047970(data_16c, 0);
        holder->model->func_000480C0(2);
        func_001BAB20(&muzzle, &data_00218AD8);
        func_001BAA50();
        func_0014C500(&direction, &muzzle);
        func_000C5670(0, &muzzle, &direction, 0);
    }
    if (owner->func_000C5B70(handle)) {
        owner->func_000C5B40(handle, &position);
    } else {
        handle = owner->func_000C5B10(0x25, &owner->position);
    }
}
