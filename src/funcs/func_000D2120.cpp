struct Vector3 {
    float x;
    float y;
    float z;
};

// Three angles (x, y, z).
struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

struct Point_000D1700 {
    Vector3 position;
    char unknown_0c[0xc];
};

void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);

// The object in data_00257CE8.
struct Object_00157F10 {
    void func_000C1F20(Angles_000C1300 *angles, Vector3 *direction, int step);
};

extern Object_00157F10 *data_00257CE8;

struct Owner_000D2120 {
    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
};

// The class (constructor func_000D27F0) whose slot 0 runs the member-function table at 0x2169e0.
struct Object_000D27F0 {
    char unknown_00[0x4];
    Owner_000D2120 *owner;
    char unknown_08[0x44];
    int heading;

    int func_000D2120(Point_000D1700 *point, int range);
};

// Turns the owner's angles toward `point` (the direction func_0014C4C0 gives from the owner's position) by at
// most `range` (func_000C1F20) and takes the new heading; 1 when it equals the heading at +0x4c.
int Object_000D27F0::func_000D2120(Point_000D1700 *point, int range)
{
    Vector3 direction;
    func_0014C4C0(&direction, &point->position, &owner->position);
    Angles_000C1300 angles = owner->angles;
    data_00257CE8->func_000C1F20(&angles, &direction, range);
    owner->angles.y = angles.y;
    return heading == angles.y;
}
