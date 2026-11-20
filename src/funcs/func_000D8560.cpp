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

void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);

// The object in data_00257CE8.
struct Object_00157F10 {
    void func_000C1F20(Angles_000C1300 *angles, Vector3 *direction, int step);
};

extern Object_00157F10 *data_00257CE8;

struct Owner_000D8560 {
    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
    char unknown_5c[0x4c];
    Vector3 *target;
};

struct Object_000D8A40 {
    char unknown_000[0x4];
    Owner_000D8560 *owner;
    char unknown_008[0x5c];
    int angle;

    int func_000D8560();
};

// Steers the owner toward its target: keeps its heading angle (y) at 0x64, turns its angles toward the direction
// func_0014C4C0 gives for its target and position by at most 0x222 (func_000C1F20) and takes the new heading. Gives 1 when the
// heading did not change.
int Object_000D8A40::func_000D8560()
{
    angle = owner->angles.y;
    Vector3 direction;
    func_0014C4C0(&direction, owner->target, &owner->position);
    Angles_000C1300 angles = owner->angles;
    data_00257CE8->func_000C1F20(&angles, &direction, 0x222);
    owner->angles.y = angles.y;
    return angle == angles.y;
}
