struct Vector3 {
    float x;
    float y;
    float z;
};

// A vertex of a quad (0x18 bytes): position, colour and texture coordinates.
struct Vertex_00060120 {
    float x;
    float y;
    float z;
    unsigned int color;
    float u;
    float v;
};

// The four corners of a quad around its centre.
struct Corners_00060010 {
    Vector3 corner[4];
};

// The class whose table is at 0x1CB040.
struct Object_00062390 {
    void func_00060010(Vertex_00060120 *out, Vector3 *center, Corners_00060010 *corners, float size, float unused,
                       unsigned int color);
};

// Writes the six vertices of two triangles of a quad: `center` plus each corner scaled by `size`, all in `color`:
// corner 2 (0, 1), corner 0 (0, 0), corner 1 (1, 0), the first and third again and corner 3 (1, 1).
void Object_00062390::func_00060010(Vertex_00060120 *out, Vector3 *center, Corners_00060010 *corners, float size,
                                    float unused, unsigned int color)
{
    Vertex_00060120 *vertex = out;
    vertex->x = size * corners->corner[2].x + center->x;
    vertex->y = size * corners->corner[2].y + center->y;
    vertex->z = size * corners->corner[2].z + center->z;
    vertex->color = color;
    vertex->u = 0.0f;
    vertex->v = 1.0f;
    vertex++;
    vertex->x = size * corners->corner[0].x + center->x;
    vertex->y = size * corners->corner[0].y + center->y;
    vertex->z = size * corners->corner[0].z + center->z;
    vertex->color = color;
    vertex->u = 0.0f;
    vertex->v = 0.0f;
    vertex++;
    vertex->x = size * corners->corner[1].x + center->x;
    vertex->y = size * corners->corner[1].y + center->y;
    vertex->z = size * corners->corner[1].z + center->z;
    vertex->color = color;
    vertex->u = 1.0f;
    vertex->v = 0.0f;
    vertex++;
    *vertex = vertex[-3];
    vertex++;
    *vertex = vertex[-2];
    vertex++;
    vertex->x = size * corners->corner[3].x + center->x;
    vertex->y = size * corners->corner[3].y + center->y;
    vertex->z = size * corners->corner[3].z + center->z;
    vertex->color = color;
    vertex->u = 1.0f;
    vertex->v = 1.0f;
}
