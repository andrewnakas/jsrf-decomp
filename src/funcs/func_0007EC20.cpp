struct Vector3 {
    float x;
    float y;
    float z;
};

// A ray: where it starts and where it goes.
struct Segment_0006F8C0 {
    Vector3 start;
    float unknown_0c;
    Vector3 direction;
    float unknown_1c;
};

// A plane: a point on it, its distance and its normal.
struct Triangle_0006F8C0 {
    Vector3 point;
    float distance;
    Vector3 normal;
    float unknown_1c;
};

float __fastcall func_0014C620(int angle);
float __fastcall func_0014C640(int angle);
int __fastcall func_0014C100(Vector3 *out, const Segment_0006F8C0 *segment, const Triangle_0006F8C0 *triangle);
float func_0014C820(float value);
int func_0014C7D0(float x, float z);

// The player.
struct Object_000A1C50 {
    int func_0007EC20(int angle, Vector3 *normal);
};

// The slope angle along a heading: casts an upward ray from the unit point at `angle` against the plane through the
// origin with `normal` (func_0014C100) and gives the angle of the hit's height over its distance across
// (func_0014C7D0), or 0x4000 when the ray misses.
int Object_000A1C50::func_0007EC20(int angle, Vector3 *normal)
{
    Segment_0006F8C0 ray;
    ray.start.x = func_0014C620(angle);
    ray.start.y = 0.0f;
    ray.start.z = func_0014C640(angle);
    Triangle_0006F8C0 plane;
    ray.direction.x = 0.0f;
    ray.direction.y = 1.0f;
    ray.direction.z = 0.0f;
    plane.point.x = 0.0f;
    plane.point.y = 0.0f;
    plane.point.z = 0.0f;
    plane.normal = *normal;
    plane.distance = 0.0f;
    Vector3 hit;
    if (func_0014C100(&hit, &ray, &plane)) {
        float across = func_0014C820(hit.x * hit.x + hit.z * hit.z);
        return func_0014C7D0(hit.y, across);
    }
    return 0x4000;
}
