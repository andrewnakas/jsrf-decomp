struct Vector3 {
    float x;
    float y;
    float z;
};

// Three corners of a triangle.
struct Triangle_00088400 {
    Vector3 corner[3];
};

// Three angles.
struct Angles_00088400 {
    int x;
    int y;
    int z;
};

int func_0004A7A0(float x, float z);
int func_0004A7F0(int angle, int other);
float __fastcall func_0014C6B0(const Vector3 *vector);
void func_001BAA00();
void func_001BAA50();
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);
void func_001BB5E0();

// A player (object 4 and on).
struct Object_000A1C50 {
    int func_00088400(Triangle_00088400 *first, Triangle_00088400 *second, Angles_00088400 *angles);
};

// The angle (func_0004A7F0 of the two func_0004A7A0 headings) between the two triangles' corner sums (the two edges
// from the first corner added) turned by the x and z angles and half a turn (the matrix at func_001BAA00..
// func_001BAA50) and flattened; 0 when either is shorter than 0.001.
int Object_000A1C50::func_00088400(Triangle_00088400 *first, Triangle_00088400 *second, Angles_00088400 *angles)
{
    Vector3 secondWay;
    Vector3 firstWay;
    Vector3 firstSum;
    Vector3 secondSum;
    firstSum.x = (first->corner[1].x - first->corner[0].x) + (first->corner[2].x - first->corner[0].x);
    firstSum.y = (first->corner[1].y - first->corner[0].y) + (first->corner[2].y - first->corner[0].y);
    firstSum.z = (first->corner[1].z - first->corner[0].z) + (first->corner[2].z - first->corner[0].z);
    secondSum.x = (second->corner[1].x - second->corner[0].x) + (second->corner[2].x - second->corner[0].x);
    secondSum.y = (second->corner[1].y - second->corner[0].y) + (second->corner[2].y - second->corner[0].y);
    secondSum.z = (second->corner[1].z - second->corner[0].z) + (second->corner[2].z - second->corner[0].z);
    func_001BAA00();
    func_001BB2E0(angles->x);
    func_001BB380(angles->z);
    func_001BB330(0x8000);
    func_001BB5E0();
    func_001BAC00(&firstWay, &firstSum);
    func_001BAC00(&secondWay, &secondSum);
    func_001BAA50();
    firstWay.y = 0.0f;
    secondWay.y = 0.0f;
    if (func_0014C6B0(&firstWay) > 0.001f && func_0014C6B0(&secondWay) > 0.001f) {
        return func_0004A7F0(func_0004A7A0(-firstWay.x, -firstWay.z), func_0004A7A0(-secondWay.x, -secondWay.z));
    }
    return 0;
}
