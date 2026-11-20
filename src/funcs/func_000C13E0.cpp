struct Vector3 {
    float x;
    float y;
    float z;
};

float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);
float __fastcall func_0014C6B0(const Vector3 *v);
int func_0014C7A0(float cosine);

// The object in data_00257CE8 (its callers load `ecx` from there; this function does not read it).
struct Object_00157F10 {
    int func_000C13E0(Vector3 *a, Vector3 *b);
};

// The angle between two vectors: func_0014C7A0 of their func_0014C800 over the product of their func_0014C6B0;
// 0 when that product is 0.
int Object_00157F10::func_000C13E0(Vector3 *a, Vector3 *b)
{
    float dot = func_0014C800(a, b);
    float lengths = func_0014C6B0(a) * func_0014C6B0(b);
    if (lengths == 0.0f) {
        return 0;
    }
    return func_0014C7A0(dot / lengths);
}
