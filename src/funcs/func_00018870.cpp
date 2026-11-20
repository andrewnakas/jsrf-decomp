struct Vector3 {
    float x;
    float y;
    float z;
};

float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);
float func_0014C820(float value);
float func_0014C870(float a, float b);

// The collision world (data_0022FCE8).
struct Object_00016200 {
    float func_00018870(const Vector3 *point, const Vector3 *center, const Vector3 *direction, float radius);
};

// Called by func_0001B5C0 and func_0001BE50 (it does not use `this`): along `direction` from `point`, where a sphere of
// `radius` around `center` is met: t = (point - center) . direction (func_0014C800), s = the square root
// (func_0014C820) of radius^2 - |point - center|^2 + t^2 when that is not negative, and the result is
// -func_0014C870(-s - t, s - t).
float Object_00016200::func_00018870(const Vector3 *point, const Vector3 *center, const Vector3 *direction,
                                     float radius)
{
    Vector3 offset;
    offset.x = point->x - center->x;
    offset.y = point->y - center->y;
    offset.z = point->z - center->z;
    float t = func_0014C800(&offset, direction);
    float s = radius * radius - offset.x * offset.x - offset.y * offset.y - offset.z * offset.z + t * t;
    if (!(s < 0.0f))
        s = func_0014C820(s);
    return -func_0014C870(-s - t, s - t);
}
