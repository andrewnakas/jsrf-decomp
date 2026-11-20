struct Data_000C2700;

struct Vector3 {
    float x;
    float y;
    float z;
};

// A vector with a spare word (the 16-byte locals of these functions).
struct Vector4_000C2840 {
    Vector3 vector;
    float w;
};

// Three angles (x, y, z).
struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

struct Object_000C1440 {
    int func_000C1450(int current, int target, int step);
};

// The object at data_00257CE8 (func_00157F10 is the engine's); it also answers func_000C1450.
struct Object_00157F10 : Object_000C1440 {
    void func_000C1300(Angles_000C1300 *angles, Vector3 *point);
};

extern Object_00157F10 *data_00257CE8;

void __fastcall func_0014C3B0(Vector3 *out, const Vector3 *a, const Vector3 *b);
int func_0014C7D0(float x, float z);

// What func_000194B0 of data_0022FCE8 hands func_000C3410: a point at 0x50 and the x and z of a direction at 0x6c and 0x74.
struct Hit_000C2840 {
    char unknown_00[0x50];
    Vector3 point;
    char unknown_5c[0x10];
    float x;
    char unknown_70[4];
    float z;
};

// The base whose table is at 0x1CDCF8 (constructor func_000C2420, destructor func_000C2470).
struct Object_000C2420 {
    Object_000C2420(Data_000C2700 *data);
    virtual void func_000C2630();

    char unknown_04[0xc];
    Vector3 position;
    Angles_000C1300 angles;

    void func_000C2900(Hit_000C2840 *hit);
};

// Puts the position three times the direction (its x and z) away from the hit's point (the height is the point's)
// and turns the heading a quarter turn from the direction's, to the side the angles' direction (func_000C1300) lies
// on (func_0014C3B0, func_0014C7D0).
void Object_000C2420::func_000C2900(Hit_000C2840 *hit)
{
    Vector4_000C2840 offset;
    Vector4_000C2840 forward;
    Vector4_000C2840 side;
    data_00257CE8->func_000C1300(&angles, &forward.vector);
    forward.vector.y = 0.0f;
    offset.vector.x = hit->x;
    offset.vector.y = 0.0f;
    offset.vector.z = hit->z;
    position.x = offset.vector.x * 3.0f + hit->point.x;
    position.y = hit->point.y;
    position.z = offset.vector.z * 3.0f + hit->point.z;
    func_0014C3B0(&side.vector, &offset.vector, &forward.vector);
    int heading = func_0014C7D0(offset.vector.x, offset.vector.z);
    if (side.vector.y > 0.0f) {
        heading -= 0x4000;
    } else {
        heading += 0x4000;
    }
    angles.y = heading;
}
