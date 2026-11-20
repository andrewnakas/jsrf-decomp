struct Vector3 {
    float x;
    float y;
    float z;
};

float func_0014C850(float a, float b);
float func_0014C870(float a, float b);

struct Box_00017CC0 {
    Vector3 min;
    Vector3 max;
};

struct Object_00016200 {
    void func_00017CC0(Box_00017CC0 *box, const Vector3 *points, unsigned int count);
};

// The box around the points: starts at the first point and widens per axis with func_0014C870 (smaller) and
// func_0014C850 (larger). Nothing without a box, points or count.
void Object_00016200::func_00017CC0(Box_00017CC0 *box, const Vector3 *points, unsigned int count)
{
    if (box && points && count > 0) {
        box->min = points[0];
        box->max = points[0];
        for (unsigned int i = 1; i < count; i++) {
            box->min.x = func_0014C870(box->min.x, points[i].x);
            box->max.x = func_0014C850(box->max.x, points[i].x);
            box->min.y = func_0014C870(box->min.y, points[i].y);
            box->max.y = func_0014C850(box->max.y, points[i].y);
            box->min.z = func_0014C870(box->min.z, points[i].z);
            box->max.z = func_0014C850(box->max.z, points[i].z);
        }
    }
}
