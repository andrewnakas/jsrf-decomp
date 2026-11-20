struct Vector3 {
    float x;
    float y;
    float z;
};

struct Box_00017CC0 {
    Vector3 min;
    Vector3 max;
};

// A vertex of a deformed mesh (0x18 bytes): position and normal.
struct Vertex_00017DF0 {
    Vector3 position;
    Vector3 normal;
};

float func_0014C850(float a, float b);
float func_0014C870(float a, float b);

// The collision world (data_0022FCE8).
struct Object_00016200 {
    void func_00017DF0(Box_00017CC0 *box, const Vertex_00017DF0 *vertices, unsigned int count);
};

// Makes `box` the bounds of the vertices' positions (func_0014C870 the smaller, func_0014C850 the larger of two
// values). Does not use `this`.
void Object_00016200::func_00017DF0(Box_00017CC0 *box, const Vertex_00017DF0 *vertices, unsigned int count)
{
    if (box && vertices && count > 0) {
        box->min = vertices[0].position;
        box->max = vertices[0].position;
        for (unsigned int i = 1; i < count; i++) {
            box->min.x = func_0014C870(box->min.x, vertices[i].position.x);
            box->max.x = func_0014C850(box->max.x, vertices[i].position.x);
            box->min.y = func_0014C870(box->min.y, vertices[i].position.y);
            box->max.y = func_0014C850(box->max.y, vertices[i].position.y);
            box->min.z = func_0014C870(box->min.z, vertices[i].position.z);
            box->max.z = func_0014C850(box->max.z, vertices[i].position.z);
        }
    }
}
