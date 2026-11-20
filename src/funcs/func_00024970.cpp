void *operator new(unsigned int size);

struct Vector3 {
    float x;
    float y;
    float z;
};

// What func_0014BE70 builds from three corners (0x30 bytes).
struct Triangle_0014BE70 {
    int unknown_00[0xc];
};

void func_0014BE70(Triangle_0014BE70 *triangle, const Vector3 *first, const Vector3 *second, const Vector3 *third);

// A quad: four corners.
struct Quad_00024970 {
    Vector3 corners[4];
};

// A shape to add (0x30 bytes): a value, its quads, a vector and four more values.
struct Shape_00024970 {
    int value;
    Quad_00024970 *quads;
    unsigned int count;
    char unknown_0c[4];
    Vector3 normal;
    int last;
    int values[3];
};

// A two-sided face (0x60 bytes): its front and back triangles.
struct Face_00024970 {
    Triangle_0014BE70 front;
    Triangle_0014BE70 back;
};

// A mesh of the list at +4 (0x30 bytes, its faces follow it): `count` faces, a value, a vector and four more
// values; linked through +0x2c, with the link that points at it at +0x28.
struct Mesh_00024AE0 {
    Face_00024970 *faces;
    unsigned int count;
    int value;
    Vector3 normal;
    int values[4];
    Mesh_00024AE0 **link;
    Mesh_00024AE0 *next;
};

struct Object_0001DEF0 {
    char unknown_00[8];
    Mesh_00024AE0 **tail;

    Mesh_00024AE0 *func_00024970(Shape_00024970 *shape);
};

// Builds a mesh from a shape in one block (each quad gives a face: front triangle from corners 0, 3, 2 and back from
// 0, 2, 1, func_0014BE70), copies the shape's values and appends it to the list whose tail link is at +8.
Mesh_00024AE0 *Object_0001DEF0::func_00024970(Shape_00024970 *shape)
{
    unsigned int words = (shape->count * sizeof(Face_00024970) + sizeof(Mesh_00024AE0)) / 4 + 1;
    Mesh_00024AE0 *mesh = (Mesh_00024AE0 *)operator new(words << 2);
    mesh->faces = (Face_00024970 *)(mesh + 1);
    mesh->count = shape->count;
    for (unsigned int i = 0; i < mesh->count; i++) {
        Quad_00024970 *quad = &shape->quads[i];
        func_0014BE70(&mesh->faces[i].front, &quad->corners[0], &quad->corners[3], &quad->corners[2]);
        func_0014BE70(&mesh->faces[i].back, &quad->corners[0], &quad->corners[2], &quad->corners[1]);
    }
    mesh->value = shape->value;
    mesh->normal = shape->normal;
    mesh->values[0] = shape->values[0];
    mesh->values[1] = shape->values[1];
    mesh->values[2] = shape->values[2];
    mesh->values[3] = shape->last;
    mesh->next = 0;
    *tail = mesh;
    mesh->link = tail;
    tail = &mesh->next;
    return mesh;
}
