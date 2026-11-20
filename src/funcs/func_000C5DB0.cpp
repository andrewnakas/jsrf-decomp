struct Vector3 {
    float x;
    float y;
    float z;
};

struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

struct Object_00157F10 {
    void func_000C1300(Angles_000C1300 *angles, Vector3 *point);
    int func_000C13E0(Vector3 *first, Vector3 *second);
};

extern Object_00157F10 *data_00257CE8;

// The reach of a test: the widest angle at 0 and the radius at 4.
struct Cone_000C5DB0 {
    int angle;
    float radius;
};

// The owner at 0x4 of the Object_000CC600 family.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
    char unknown_5c[0x70];
    Cone_000C5DB0 *cone;

    int func_000C5DB0(Vector3 *point);
};

// Kind 1's test (data_00216214): true when the point lies within the radius of the cone at 0xcc (on x and z) and
// within its angle of the way the owner faces (func_000C1300 of the angles at 0x50, func_000C13E0).
int Object_000C5B50::func_000C5DB0(Vector3 *point)
{
    Vector3 offset;
    Vector3 facing;
    Cone_000C5DB0 *reach = cone;
    offset.x = point->x - position.x;
    offset.y = 0.0f;
    offset.z = point->z - position.z;
    if (offset.z * offset.z + offset.x * offset.x > reach->radius * reach->radius)
        return 0;
    data_00257CE8->func_000C1300(&angles, &facing);
    return reach->angle >= data_00257CE8->func_000C13E0(&offset, &facing);
}
