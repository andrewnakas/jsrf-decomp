struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
float __fastcall func_0014C460(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C730(Vector3 *point, Vector3 *direction, float distance);

// The owner at 0x4: its position at 0x44, speed at 0x5c, rise at 0x60, home at 0x80 and flags at 0xa4.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0xc];
    float speed;
    float rise;
    char unknown_64[0x1c];
    Vector3 home;
    char unknown_8c[0x18];
    unsigned int flags;
};

// The objects whose state handlers fill the table at 0x2165F4 to 0x216660 (func_000CE1A0, func_000CE220,
// func_000CEF60, func_000CF010, ...).
struct Object_000CE220 {
    int unknown_00;
    Object_000C5B50 *owner;
    char unknown_08[0x44];
    Vector3 direction;

    void func_000CE8B0();
};

// Moves the owner along the direction at 0x4c by its speed and up by its rise. Above its home's height it falls (the
// rise drops by 1/36) with flag 0x80; otherwise it stands at that height without it. More than 200 away from its home
// at 0x80 on the flat, it is put back on the circle of 200 around the home at the new height.
void Object_000CE220::func_000CE8B0()
{
    Vector3 next = owner->position;
    next.x += direction.x * owner->speed;
    next.y += owner->rise;
    next.z += direction.z * owner->speed;
    if (next.y > owner->home.y) {
        owner->rise -= 0.027777778f;
        owner->flags |= 0x80;
    } else {
        next.y = owner->home.y;
        owner->flags &= ~0x80;
    }
    Vector3 way;
    func_0014C4C0(&way, &next, &owner->home);
    way.y = 0.0f;
    if (func_0014C460(&way, &way) > 200.0f) {
        owner->position = owner->home;
        func_0014C730(&owner->position, &way, 200.0f);
        owner->position.y = next.y;
        return;
    }
    owner->position = next;
}
