struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000B45A0 {
    void func_000B45A0(int index, float time, Vector3 *out);
    void func_000B46D0(int index, float time, Vector3 *out);
};

// Passes its arguments on to func_000B45A0 (func_000AD3A0 calls it five times).
void Object_000B45A0::func_000B46D0(int index, float time, Vector3 *out)
{
    func_000B45A0(index, time, out);
}
