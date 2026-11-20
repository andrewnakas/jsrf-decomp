struct Vector3 {
    float x;
    float y;
    float z;
};

// A face: a point on it, its distance and its normal (+0x10).
struct Plane_0007F030 {
    Vector3 point;
    float distance;
    Vector3 normal;
};

float __fastcall func_0014C620(int angle);
float __fastcall func_0014C640(int angle);
float __fastcall func_0014BD00(Vector3 *out, const Vector3 *point, const Plane_0007F030 *plane);
int func_0014C7D0(float x, float z);

// The player.
struct Object_000A1C50 {
    char unknown_000[0xcc0];
    int angle_cc0;

    int func_0007EFC0(const Plane_0007F030 *plane);
};

// The heading from the foot on the face (func_0014BD00) of the point one unit behind the face's point along the
// player's heading (+0xcc0, sine and cosine by func_0014C620 / func_0014C640) back to the face's point.
int Object_000A1C50::func_0007EFC0(const Plane_0007F030 *plane)
{
    Vector3 behind;
    behind.x = plane->point.x - func_0014C620(angle_cc0);
    behind.y = plane->point.y;
    behind.z = plane->point.z - func_0014C640(angle_cc0);
    Vector3 foot;
    func_0014BD00(&foot, &behind, plane);
    return func_0014C7D0(plane->point.x - foot.x, plane->point.z - foot.z);
}
