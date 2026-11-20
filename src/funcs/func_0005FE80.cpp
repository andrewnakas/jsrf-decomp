struct Vector3 {
    float x;
    float y;
    float z;
};

struct Matrix_001BA950 {
    float m[4][4];
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
float func_0014C820(float value);

// The class whose table is at 0x1CB040.
struct Object_00062390 {
    char unknown_0000[0x94];
    Matrix_001BA950 first;
    char unknown_00d4[0x88];
    int frames;
    float fade;
    char unknown_0164[0x118];
    Vector3 position;
    char unknown_0288[0x12bc];
    float nearDistance;
    float farDistance;

    int func_0005FE80();
};

// The distance across (x and z) of the position at +0x27c moved by the matrix at +0x94: beyond +0x1548 the fade at
// +0x160 is 0 and the answer 0; else counts the frames at +0x15c and fades from 1 (within +0x1544) to 0 (at +0x1548),
// answering 1.
int Object_00062390::func_0005FE80()
{
    Vector3 moved;
    func_001BA9C0();
    func_001BA8F0(&first);
    func_001BAB20(&moved, &position);
    func_001BAA50();
    float distance = func_0014C820(moved.x * moved.x + moved.z * moved.z);
    if (distance > farDistance) {
        fade = 0.0f;
        return 0;
    }
    frames++;
    if (distance <= nearDistance) {
        fade = 1.0f;
        return 1;
    }
    fade = 1.0f - (distance - nearDistance) / (farDistance - nearDistance);
    return 1;
}
