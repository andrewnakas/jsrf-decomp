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

void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);

struct Object_000C1440 {
    int func_000C1440(int from, int to);
    int func_000C1450(int current, int target, int step);
};

// The object in data_00257CE8; it also answers func_000C1440 and func_000C1450.
struct Object_00157F10 : Object_000C1440 {
    void func_000C1F20(Angles_000C1300 *angles, Vector3 *direction, int step);
};

extern Object_00157F10 *data_00257CE8;

struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
};

// The state handlers of the table at 0x2165F4 (owner at 4).
struct Object_000CE220 {
    int unknown_00;
    Object_000C5B50 *owner;
    char unknown_08[0x34];
    int heading;

    int func_000CE6F0(Vector3 *point);
};

// Turns the owner toward point: the angles of the direction from the owner (func_0014C4C0, func_000C1F20 with
// 0x8000), the owner's y angle stepped toward them by 0x222 (func_000C1450); returns func_000C1440 of that
// angle and the heading at 0x3c.
int Object_000CE220::func_000CE6F0(Vector3 *point)
{
    Vector3 direction;
    Angles_000C1300 angles;
    func_0014C4C0(&direction, point, &owner->position);
    data_00257CE8->func_000C1F20(&angles, &direction, 0x8000);
    owner->angles.y = data_00257CE8->func_000C1450(owner->angles.y, angles.y, 0x222);
    return data_00257CE8->func_000C1440(angles.y, heading);
}
