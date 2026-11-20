struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

struct Object_00047470 {
    void func_000480C0(unsigned int index);
};

void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB330(int angle);

extern Vector3 data_00216A50[3];

struct Holder_000D27F0 {
    int unknown_00;
    Object_00047470 *model;
};

// The class (constructor func_000D27F0) whose slot 0 runs the member-function table at 0x2169e0.
struct Object_000D27F0 {
    char unknown_000[0x80];
    unsigned int frame;
    char unknown_084[0xe70];
    Holder_000D27F0 *holder;

    void func_000D26C0();
};

// Picks frame 0xd of the holder's model for frame 0xe, else frame 0x11 and a half turn; then starts kind 0x49 of
// object 0xe8 at each of the three points of data_00216A50 placed by the matrix (func_001BAB20). Called by
// func_000D3B80 and func_000D3F20.
void Object_000D27F0::func_000D26C0()
{
    if (frame == 0xe) {
        holder->model->func_000480C0(0xd);
    } else {
        holder->model->func_000480C0(0x11);
        func_001BB330(0x8000);
    }
    Vector3 point;
    func_001BAB20(&point, &data_00216A50[0]);
    Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (object) {
        object->func_000651E0(0x49, &point, 0);
    }
    func_001BAB20(&point, &data_00216A50[1]);
    object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (object) {
        object->func_000651E0(0x49, &point, 0);
    }
    func_001BAB20(&point, &data_00216A50[2]);
    object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (object) {
        object->func_000651E0(0x49, &point, 0);
    }
}
