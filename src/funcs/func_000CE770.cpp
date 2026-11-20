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

void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BB330(int angle);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
float __fastcall func_0014C460(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C730(Vector3 *target, Vector3 *direction, float scale);
float __fastcall func_0014CB60(const Vector3 *from, const Vector3 *to);

// The owner at 0x4: its position at 0x44, angles at 0x50, speed at 0x5c and home at 0x80.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
    float speed;
    char unknown_60[0x20];
    Vector3 home;
};

// The objects whose state handlers fill the table at 0x2165F4 to 0x216660 (func_000CE1A0, func_000CE220,
// func_000CEF60, func_000CF010, ...).
struct Object_000CE220 {
    int unknown_00;
    Object_000C5B50 *owner;

    int func_000CE6F0(Vector3 *point);
    float func_000CE770(Vector3 *point);
};

// Flies the owner toward the point: the speed grows by 1/36 up to 55/36, the angles turn toward it
// (func_000CE6F0), and the owner moves forward along its heading (z axis turned by the y angle, func_001BAC00) by
// the speed, kept within 200 of its home at 0x80 (func_0014C460, func_0014C730). Returns the distance to the point
// (func_0014CB60).
float Object_000CE220::func_000CE770(Vector3 *point)
{
    Vector3 forward;
    forward.x = 0.0f;
    forward.y = 0.0f;
    forward.z = 1.0f;
    Vector3 next = owner->position;
    owner->speed += 0.027777778f;
    if (owner->speed > 1.5277778f) {
        owner->speed = 1.5277778f;
    }
    func_000CE6F0(point);
    func_001BAA00();
    func_001BB330(owner->angles.y);
    func_001BAC00(&forward, &forward);
    func_001BAA50();
    func_0014C730(&next, &forward, owner->speed);
    func_0014C4C0(&forward, &next, &owner->home);
    if (func_0014C460(&forward, &forward) > 200.0f) {
        owner->position = owner->home;
        func_0014C730(&owner->position, &forward, 200.0f);
    } else {
        owner->position = next;
    }
    return func_0014CB60(point, &owner->position);
}
