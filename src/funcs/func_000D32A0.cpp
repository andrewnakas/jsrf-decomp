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

struct Rotation_000D2B90 {
    Vector3 axis;
    int angle;
};

struct Point_000D1700 {
    Vector3 position;
    char unknown_0c[0xc];
};

struct Object_00047470 {
    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB330(int angle);
void __fastcall func_0014C3B0(Vector3 *out, const Vector3 *a, const Vector3 *b);
void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);
float __fastcall func_0014C460(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);
int func_0014C7A0(float cosine);
float func_0014C7F0(float value);

extern Vector3 data_002168E8;

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0x50];
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
    char unknown_00c[8];
    Vector3 position;
    char unknown_020[0x10];
    unsigned int count_30;
    char unknown_034[4];
    unsigned int index_38;
    unsigned int step_3c;
    char unknown_040[0x40];
    unsigned int frame;
    char unknown_084[4];
    int value_88;
    char unknown_08c[4];
    Vector3 path[300];
    char unknown_ea0[0x18];
    unsigned int total;
    unsigned int next;
    unsigned int value_ec0;
    Rotation_000D2B90 rotation;
    Vector3 start;
    char unknown_ee0[0x14];
    Holder_000D27F0 *holder;
    char unknown_ef8[0x18];
    void *data_f10;
    char unknown_f14[0x1c];
    int value_f30;

    int func_000D2120(Point_000D1700 *point, int range);
    void func_000D32A0();
};

// Entry 5 of the member-function table at 0x2169e0. Past the last point of the path at 0x90: back to the start at
// 0xed4 in state 10 with 7 at 0xf30, the index at 0x38 moved by the step at 0x3c (wrapping within 0x30), no turn at
// 0xed0 and the owner's flag 0x8000000 cleared. Otherwise takes the next point as the position and steers toward it
// (func_000D2120, range 0x222); without 0x88 and within 24 points of the end, state 8 with 5 at 0xf30 and the count
// at 0xec0. Else the rotation at 0xec4 turns the holder's model heading (posed at the owner turned a half turn, frame
// at 0x80) toward the last path segment when they are not nearly parallel.
void Object_000D27F0::func_000D32A0()
{
    if (++next >= total) {
        position = start;
        state = 10;
        value_f30 = 7;
        index_38 += step_3c;
        index_38 = index_38 == -1 ? count_30 - 1 : index_38;
        index_38 = index_38 < count_30 ? index_38 : 0;
        rotation.angle = 0;
        owner->flags &= ~0x8000000;
        return;
    }
    if (value_88 == 0 && (int)(total - next) <= 0x18) {
        position = path[next];
        func_000D2120((Point_000D1700 *)&position, 0x222);
        rotation.angle = 0;
        state = 8;
        value_f30 = 5;
        value_ec0 = total;
        return;
    }
    position = path[next];
    func_000D2120((Point_000D1700 *)&position, 0x222);
    func_001BAA00();
    func_001BB330(owner->angles.y + 0x8000);
    holder->model->func_00047970(data_f10, 0);
    holder->model->func_000480C0(frame);
    Vector3 ahead;
    func_001BAC00(&ahead, &data_002168E8);
    func_001BAA50();
    Vector3 offset;
    func_0014C4C0(&offset, &path[next], &path[next - 1]);
    if (func_0014C460(&offset, &offset) > 0.0f) {
        float cosine = func_0014C800(&offset, &ahead);
        if (func_0014C7F0(cosine) < 0.999f) {
            func_0014C3B0(&rotation.axis, &ahead, &offset);
            func_0014C410(&rotation.axis, &rotation.axis);
            rotation.angle = func_0014C7A0(cosine);
        }
    }
}
