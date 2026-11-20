struct Vector3 {
    float x;
    float y;
    float z;
};

float func_0014C870(float a, float b);
float func_0014C850(float a, float b);

// An axis-aligned box: its low and high corners.
struct Box_00017A50 {
    Vector3 low;
    Vector3 high;
};

// The collision world (data_0022FCE8).
struct Object_00016200 {
    void func_00017BC0(Box_00017A50 *box, const Vector3 *a, const Vector3 *b, const Vector3 *c);
};

// Called by func_00019970 (it does not use `this`): the box around three points, as func_00017A50 does for two.
void Object_00016200::func_00017BC0(Box_00017A50 *box, const Vector3 *a, const Vector3 *b, const Vector3 *c)
{
    box->low = *a;
    box->high = *a;
    box->low.x = func_0014C870(box->low.x, b->x);
    box->high.x = func_0014C850(box->high.x, b->x);
    box->low.y = func_0014C870(box->low.y, b->y);
    box->high.y = func_0014C850(box->high.y, b->y);
    box->low.z = func_0014C870(box->low.z, b->z);
    box->high.z = func_0014C850(box->high.z, b->z);
    box->low.x = func_0014C870(box->low.x, c->x);
    box->high.x = func_0014C850(box->high.x, c->x);
    box->low.y = func_0014C870(box->low.y, c->y);
    box->high.y = func_0014C850(box->high.y, c->y);
    box->low.z = func_0014C870(box->low.z, c->z);
    box->high.z = func_0014C850(box->high.z, c->z);
}
