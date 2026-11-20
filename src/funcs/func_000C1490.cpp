struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_0014C370(Vector3 *out, const Vector3 *in, float scale);
float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);
void __fastcall func_0014C500(Vector3 *vector, const Vector3 *other);
void __fastcall func_0014C300(Vector3 *out, const Vector3 *a, const Vector3 *b);

// Three directions: the second's at 0x8, the first's at 0x1c and the normal at 0x2c.
struct Frame_000C1490 {
    char unknown_00[8];
    Vector3 second;
    char unknown_14[8];
    Vector3 first;
    char unknown_28[4];
    Vector3 normal;
};

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 {
    void func_000C1490(Vector3 *out, Frame_000C1490 *frame, float first, float second);
};

// Out = A - B * 2(A.n) + n (A.n + B.n), with A the first direction times the first scale, B the second times the
// second scale and n the normal (func_0014C370 scales, func_0014C800 is the dot product).
void Object_00157F10::func_000C1490(Vector3 *out, Frame_000C1490 *frame, float first, float second)
{
    Vector3 b;
    Vector3 a;
    Vector3 along;
    func_0014C370(&a, &frame->first, first);
    func_0014C370(&b, &frame->second, second);
    float dot = func_0014C800(&a, &frame->normal);
    func_0014C370(&along, &frame->normal, dot + func_0014C800(&b, &frame->normal));
    func_0014C370(&b, &b, dot * 2.0f);
    func_0014C500(&a, &b);
    func_0014C300(out, &a, &along);
}
