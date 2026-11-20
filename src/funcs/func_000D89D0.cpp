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

void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB330(int angle);

// A direction and a point in the model's frame.
extern Vector3 data_002173A8;
extern Vector3 data_002173B4;

// The model (the holder's first word).
struct Object_00047470 {
    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

struct Holder_000D8A40 {
    Object_00047470 *model;
};

struct Owner_000D89D0 {
    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
};

struct Object_000D8A40 {
    char unknown_000[0x4];
    Owner_000D89D0 *owner;
    char unknown_008[0x9c];
    Holder_000D8A40 *holder;
    char unknown_0a8[0x18];
    void *handle_c0;

    void func_000D89D0(Vector3 *position, Vector3 *direction);
};

// Sets the model up at the owner's place, turned by its heading (y), with the handle at 0xc0 and part 15
// (func_00047970, func_000480C0), and gives the point data_002173B4 and the direction data_002173A8 through it
// (func_001BAB20, func_001BAC00).
void Object_000D8A40::func_000D89D0(Vector3 *position, Vector3 *direction)
{
    func_001BAA00();
    func_001BAAA0(&owner->position.x);
    func_001BB330(owner->angles.y + 0x8000);
    holder->model->func_00047970(handle_c0, 0);
    holder->model->func_000480C0(15);
    func_001BAB20(position, &data_002173B4);
    func_001BAC00(direction, &data_002173A8);
    func_001BAA50();
}
