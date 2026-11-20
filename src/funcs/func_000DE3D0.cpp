struct Vector3 {
    float x;
    float y;
    float z;
};

// Three angles (x, y, z).
struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

void func_001BA9C0();
void func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

struct Object_0003E750 {
    void func_0003F280(int key);
};

extern Object_0003E750 data_002314B0;

// The model (the holder's first word).
struct Object_00047470 {
    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

struct Holder_000DCBC0 {
    Object_00047470 *model;
};

// The owner at 0x4.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
    float speed;
    float climb;
    char unknown_64[0x40];
    unsigned int flags;

    void func_000C5AD0(int amount);
};

struct Object_000DCBC0 {
    char unknown_000[0x4];
    Object_000C5B50 *owner;
    int state;
    char unknown_00c[0x168];
    float height;
    char unknown_178[0x8];
    Holder_000DCBC0 *holder;
    char unknown_184[0x1c];
    void *handle_1a0;
    char unknown_1a4[0x24];
    int phase;
    char unknown_1cc[0xf8];
    int key;
    char unknown_2c8[0xc];
    int value_2d4;

    void func_000DDEF0();
    void func_000DE3D0();
};

// A handler of the table at 0x217A20: moves (func_000DDEF0); then, unless the owner has flag 0x80 and is no more
// than 200 below the height at 0x174, sets its flag 0x2000, moves to state 33 (phase 2), gives the owner 1
// (func_000C5AD0) and stops it, sets the model up at the owner's place and angles with the handle at 0x1a0 and
// part 9 (func_00047970, func_000480C0), sends kind 0x26 to node 0xe8 (func_000651E0) at the model's origin one
// above the owner, hands the key at 0x2c4 to func_0003F280 of data_002314B0, forgets it and gives 1 at 0x2d4.
void Object_000DCBC0::func_000DE3D0()
{
    Vector3 point;
    func_000DDEF0();
    Object_000C5B50 *current = owner;
    if (!(current->flags & 0x80) || height - current->position.y > 200.0f) {
        owner->flags |= 0x2000;
        state = 33;
        phase = 2;
        owner->func_000C5AD0(1);
        owner->speed = 0.0f;
        owner->climb = 0.0f;
        func_001BA9C0();
        func_001BAAA0(&owner->position.x);
        func_001BB330(owner->angles.y + 0x8000);
        func_001BB2E0(owner->angles.x);
        func_001BB380(owner->angles.z);
        holder->model->func_00047970(handle_1a0, 0);
        holder->model->func_000480C0(9);
        func_001BAB20(&point, 0);
        func_001BAA50();
        point.y = owner->position.y + 1.0f;
        Object_000607B0 *node = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (node) {
            node->func_000651E0(0x26, &point, 0);
        }
        data_002314B0.func_0003F280(key);
        key = -1;
        value_2d4 = 1;
    }
}
