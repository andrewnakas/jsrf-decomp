struct Vector3 {
    float x;
    float y;
    float z;
};

// One vertex of the effect's quads (0x18 bytes).
struct Vertex_000450E0 {
    float x;
    float y;
    float z;
    int colour;
    float u;
    float v;
};

// Two triangles (six vertices) form one quad.
struct Quad_000450E0 {
    Vertex_000450E0 vertices[6];
};

struct Object_00044AE0 {
    char unknown_000[0x93c];
    Quad_000450E0 *quads;

    void func_000450E0(int index, Vector3 *origin, int colour, float scale, float *axes);
};

// Fills quad `index` (+0x93c) around `origin`: its corners are `origin` plus `scale` times the four vectors at axes
// +0x18, +0x24, +0x00 and +0x0c, with texture corners (0, 1), (1, 1), (0, 0) and (1, 0), all in `colour`; the
// second triangle repeats the third and second vertices.
void Object_00044AE0::func_000450E0(int index, Vector3 *origin, int colour, float scale, float *axes)
{
    Vertex_000450E0 *vertex = quads[index].vertices;
    vertex->x = scale * axes[6] + origin->x;
    vertex->y = scale * axes[7] + origin->y;
    vertex->z = scale * axes[8] + origin->z;
    vertex->colour = colour;
    vertex->u = 0.0f;
    vertex->v = 1.0f;
    vertex++;
    vertex->x = scale * axes[9] + origin->x;
    vertex->y = scale * axes[10] + origin->y;
    vertex->z = scale * axes[11] + origin->z;
    vertex->colour = colour;
    vertex->u = 1.0f;
    vertex->v = 1.0f;
    vertex++;
    vertex->x = scale * axes[0] + origin->x;
    vertex->y = scale * axes[1] + origin->y;
    vertex->z = scale * axes[2] + origin->z;
    vertex->colour = colour;
    vertex->u = 0.0f;
    vertex->v = 0.0f;
    vertex++;
    *vertex = quads[index].vertices[2];
    vertex++;
    *vertex = quads[index].vertices[1];
    vertex++;
    vertex->x = scale * axes[3] + origin->x;
    vertex->y = scale * axes[4] + origin->y;
    vertex->z = scale * axes[5] + origin->z;
    vertex->colour = colour;
    vertex->u = 1.0f;
    vertex->v = 0.0f;
}
