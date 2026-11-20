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

struct Object_000C1440 {
    int func_000C1440(int from, int to);
    int func_000C1450(int current, int target, int step);
};

// The object in data_00257CE8; it also answers func_000C1440 and func_000C1450.
struct Object_00157F10 : Object_000C1440 {
    void func_000C1F20(Angles_000C1300 *angles, Vector3 *direction, int step);
};

extern Object_00157F10 *data_00257CE8;

int __fastcall func_0014C840(int first, int second);

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

    int func_000D2190(Vector3 *position, int step, int limit);
};

// Turns the owner's heading toward `position` by at most `step` (func_000C1450 toward the heading func_000C1F20 gives
// for the direction from the owner's position); 1 when what is left between that heading and the one at +0x4c
// (func_000C1440, measured by func_0014C840) is below `limit`.
int Object_000D27F0::func_000D2190(Vector3 *position, int step, int limit)
{
    Vector3 direction;
    Angles_000C1300 angles;
    func_0014C4C0(&direction, position, &owner->position);
    data_00257CE8->func_000C1F20(&angles, &direction, 0x8000);
    angles.x = angles.y;
    owner->angles.y = data_00257CE8->func_000C1450(owner->angles.y, angles.y, step);
    int difference = data_00257CE8->func_000C1440(angles.y, heading);
    return func_0014C840(difference, -difference) < limit;
}
