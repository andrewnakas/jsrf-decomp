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

// What the quad is spanned by: two half axes at +0x18 and +0x24.
struct Axes_00060120 {
    char unknown_00[0x18];
    Vector3 first;
    Vector3 second;
};

// The class whose table is at 0x1CB040.
struct Object_00062390 {
    void func_00060120(Vertex_00060120 *out, Vector3 *center, Axes_00060120 *axes, unsigned int color);
};

// Writes the six vertices of two triangles of a quad around `center` spanned by the two half axes, all in `color`:
// center + first (0, 1), center - second (0, 0), center - first (1, 0), the first and third again and
// center + second (1, 1).
void Object_00062390::func_00060120(Vertex_00060120 *out, Vector3 *center, Axes_00060120 *axes, unsigned int color)
{
    Vertex_00060120 *vertex = out;
    vertex->x = center->x + axes->first.x;
    vertex->y = center->y + axes->first.y;
    vertex->z = center->z + axes->first.z;
    vertex->color = color;
    vertex->u = 0.0f;
    vertex->v = 1.0f;
    vertex++;
    vertex->x = center->x - axes->second.x;
    vertex->y = center->y - axes->second.y;
    vertex->z = center->z - axes->second.z;
    vertex->color = color;
    vertex->u = 0.0f;
    vertex->v = 0.0f;
    vertex++;
    vertex->x = center->x - axes->first.x;
    vertex->y = center->y - axes->first.y;
    vertex->z = center->z - axes->first.z;
    vertex->color = color;
    vertex->u = 1.0f;
    vertex->v = 0.0f;
    vertex++;
    *vertex = vertex[-3];
    vertex++;
    *vertex = vertex[-2];
    vertex++;
    vertex->x = center->x + axes->second.x;
    vertex->y = center->y + axes->second.y;
    vertex->z = center->z + axes->second.z;
    vertex->color = color;
    vertex->u = 1.0f;
    vertex->v = 1.0f;
}
