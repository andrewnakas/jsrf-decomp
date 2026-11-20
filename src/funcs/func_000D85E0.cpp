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

float __fastcall func_0014CB60(const Vector3 *from, const Vector3 *to);
void __fastcall func_0014C730(Vector3 *target, Vector3 *direction, float scale);

// The object in data_00257CE8.
struct Object_00157F10 {
    void func_000C1300(Angles_000C1300 *angles, Vector3 *point);
};

extern Object_00157F10 *data_00257CE8;

struct Owner_000D85E0 {
    char unknown_00[0x50];
    Angles_000C1300 angles;
    float speed;
    float climb;
    char unknown_64[0x10];
    Vector3 heading;
    char unknown_80[0x28];
    Vector3 *target;
};

struct Object_000D8A40 {
    char unknown_000[0x4];
    Owner_000D85E0 *owner;
    char unknown_008[0xc];
    Vector3 position;

    int func_000D8560();
    int func_000D85E0();
};

// Moves toward the owner's target: speeds the owner up by 1/72 a frame to at most 1.8518518, steers it
// (func_000D8560), turns its heading by its angles (func_000C1300), moves the position at 0x14 along the heading by
// the speed (func_0014C730) and lifts it by the owner's climb (0x60). Gives 1 when the position, before the move,
// was within 15 of the target on the ground.
int Object_000D8A40::func_000D85E0()
{
    float distance = func_0014CB60(owner->target, &position);
    if (owner->speed < 1.8518518f) {
        owner->speed += 1.0f / 72.0f;
        if (owner->speed > 1.8518518f) {
            owner->speed = 1.8518518f;
        }
    }
    func_000D8560();
    data_00257CE8->func_000C1300(&owner->angles, &owner->heading);
    func_0014C730(&position, &owner->heading, owner->speed);
    position.y = owner->climb + position.y;
    if (distance > 15.0f) {
        return 0;
    }
    return 1;
}
