struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_001BAB20(Vector3 *to, const Vector3 *from);
void __fastcall func_001BAC00(Vector3 *to, const Vector3 *from);

// Runs func_001BAB20 over the first six vectors and func_001BAC00 over the next six, from `from` into `to`.
void func_0004A750(Vector3 *to, const Vector3 *from)
{
    for (int i = 0; i < 6; i++) {
        func_001BAB20(&to[i], &from[i]);
        func_001BAC00(&to[i + 6], &from[i + 6]);
    }
}
