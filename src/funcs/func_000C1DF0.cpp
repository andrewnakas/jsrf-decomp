struct Vector3 {
    float x;
    float y;
    float z;
};

float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);
void __fastcall func_0014CD50(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C8B0(Vector3 *out, const Vector3 *from, const Vector3 *to, float amount);
void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);

// The object in data_00257CE8 (its callers load `ecx` from there; this function does not read it).
struct Object_00157F10 {
    void func_000C1DF0(const Vector3 *target, Vector3 *direction);
};

// Moves the direction three quarters of the way to the target (negated when they point apart; func_0014C800,
// func_0014CD50, func_0014C8B0) and makes it unit length again (func_0014C410).
void Object_00157F10::func_000C1DF0(const Vector3 *target, Vector3 *direction)
{
    Vector3 goal = *target;
    if (func_0014C800(&goal, direction) < 0.0f) {
        func_0014CD50(&goal, &goal);
    }
    func_0014C8B0(direction, &goal, direction, 0.25f);
    func_0014C410(direction, direction);
}
