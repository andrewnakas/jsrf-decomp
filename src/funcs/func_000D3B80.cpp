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

struct Object_00047470 {
    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB330(int angle);

extern Vector3 data_002168E8;
extern Vector3 data_00216900;

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    int func_000C5B10(int message, void *data);

    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
    char unknown_5c[0x48];
    unsigned int flags;
};

struct Holder_000D27F0 {
    int unknown_00;
    Object_00047470 *model;
};

// The class (constructor func_000D27F0) whose slot 0 runs the member-function table at 0x2169e0.
struct Object_000D27F0 {
    char unknown_000[0x4];
    Object_000C5B50 *owner;
    int state;
    char unknown_00c[0x74];
    unsigned int frame;
    char unknown_084[0xc];
    Vector3 point_90;
    char unknown_09c[0xe04];
    Vector3 point_ea0;
    char unknown_eac[0xc];
    int count_eb8;
    int next_ebc;
    char unknown_ec0[0x20];
    int value_ee0;
    char unknown_ee4[0x10];
    Holder_000D27F0 *holder;
    char unknown_ef8[0x18];
    void *data_f10;
    char unknown_f14[0x1c];
    int value_f30;
    char unknown_f34[4];
    int mode_f38;

    void func_000D26C0();
    void func_000D34B0();
    void func_000D3B80();
};

// Entry 3 of the member-function table at 0x2169e0: in mode 2 (0xf38), inside a matrix at the owner's position
// turned a half turn past its heading, poses the holder's model (the data at 0xf10, frame 0x80), sets the points at
// 0x90 and 0xea0 from data_00216900 and data_002168E8, runs func_000D26C0, then restarts the path (one point, next
// 0) with 0xee0 cleared, state 4, 3 at 0xf30 and the owner's flag 0x8000000. Then func_000D34B0.
void Object_000D27F0::func_000D3B80()
{
    if (mode_f38 == 2) {
        func_001BAA00();
        func_001BAAA0(&owner->position.x);
        func_001BB330(owner->angles.y + 0x8000);
        holder->model->func_00047970(data_f10, 0);
        holder->model->func_000480C0(frame);
        func_001BAB20(&point_90, &data_00216900);
        func_001BAC00(&point_ea0, &data_002168E8);
        func_000D26C0();
        func_001BAA50();
        count_eb8 = 1;
        next_ebc = 0;
        value_ee0 = 0;
        state = 4;
        value_f30 = 3;
        owner->flags |= 0x8000000;
    }
    func_000D34B0();
}
