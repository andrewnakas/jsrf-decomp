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

struct Owner_000E9F70 {
    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
    char unknown_5c[0x4c];
    Vector3 *target;
};

struct Object_000E9F70 {
    char unknown_00[4];
    Owner_000E9F70 *owner;

    int func_000E9F70();
};

// Turns the owner's angles toward its target (+0xa8; the direction func_0014C4C0 gives from its position) by at
// most 0x111 (func_000C1F20). Takes the new heading and gives 0 when it changed, 1 when it did not.
int Object_000E9F70::func_000E9F70()
{
    Vector3 direction;
    func_0014C4C0(&direction, owner->target, &owner->position);
    Angles_000C1300 angles = owner->angles;
    data_00257CE8->func_000C1F20(&angles, &direction, 0x111);
    if (angles.y != owner->angles.y) {
        owner->angles.y = angles.y;
        return 0;
    }
    return 1;
}
