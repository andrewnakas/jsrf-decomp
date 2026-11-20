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
void func_001BAA50();
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);

extern Vector3 data_00215DDC;

// The object in data_00257CE8 (its callers load `ecx` from there; this function does not read it).
struct Object_00157F10 {
    void func_000C1300(Angles_000C1300 *angles, Vector3 *point);
};

// Turns data_00215DDC by the angles (y, then minus x, then z, between func_001BAA00 and func_001BAA50) into the
// point (func_001BAC00).
void Object_00157F10::func_000C1300(Angles_000C1300 *angles, Vector3 *point)
{
    func_001BAA00();
    func_001BB330(angles->y);
    func_001BB2E0(-angles->x);
    func_001BB380(angles->z);
    func_001BAC00(point, &data_00215DDC);
    func_001BAA50();
}
