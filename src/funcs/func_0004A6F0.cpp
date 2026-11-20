struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *a, const Vector3 *b);
float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);

// A convex cell (0x90 bytes): six points on its faces, then the six face normals.
struct Cell_000A6DC0 {
    Vector3 points[6];
    Vector3 normals[6];
};

// 1 when the point lies on the inner side of all six faces of the cell (point - face point, dotted with the face
// normal, is not negative), otherwise 0.
int func_0004A6F0(Vector3 *point, Cell_000A6DC0 *cell)
{
    for (unsigned int i = 0; i < 6; i++) {
        Vector3 offset;
        func_0014C4C0(&offset, &cell->points[i], point);
        if (func_0014C800(&offset, &cell->normals[i]) < 0.0f)
            return 0;
    }
    return 1;
}
