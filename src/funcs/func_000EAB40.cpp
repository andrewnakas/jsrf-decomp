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

// The object in data_00257CE8.
struct Object_00157F10 {
    void func_000C1300(Angles_000C1300 *angles, Vector3 *point);
};

extern Object_00157F10 *data_00257CE8;

void __fastcall func_0014C730(Vector3 *target, Vector3 *direction, float scale);
float __fastcall func_0014C580(const Vector3 *a, const Vector3 *b);

// The object a behaviour serves (at 0x4).
struct Owner_000EAB40 {
    char unknown_00[0x50];
    Angles_000C1300 angles;
    float speed;
    char unknown_60[0x48];
    Vector3 *target;
};

struct Object_000E9F70 {
    int func_000E9F70();
};

struct Object_000EAB40 {
    char unknown_000[4];
    Owner_000EAB40 *owner;
    char unknown_008[0xc];
    Vector3 position;
    char unknown_020[0x80];
    Vector3 *points;
    unsigned int count;
    char unknown_0a8[4];
    unsigned int index;

    int func_000EAB40();
};

// Speeds the owner up by 1/72 toward 25/27, turns it toward its target (func_000E9F70) and moves the position at
// 0x14 along its angles by its speed; once within 400 of the target, aims the owner at the next of the points at
// 0xa0 (wrapping at the count at 0xa4) and gives 1, else 0.
int Object_000EAB40::func_000EAB40()
{
    if (owner->speed < 0.9259259f) {
        owner->speed += 0.013888889f;
        if (owner->speed > 0.9259259f) {
            owner->speed = 0.9259259f;
        }
    }
    ((Object_000E9F70 *)this)->func_000E9F70();
    Vector3 direction;
    data_00257CE8->func_000C1300(&owner->angles, &direction);
    func_0014C730(&position, &direction, owner->speed);
    if (func_0014C580(&position, owner->target) > 400.0f) {
        return 0;
    }
    if (++index >= count) {
        index = 0;
    }
    owner->target = &points[index];
    return 1;
}
