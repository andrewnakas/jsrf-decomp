struct Vector3 {
    float x;
    float y;
    float z;
};

// What func_00089950 hands its helpers: a direction at +0x10 and a length at +0x20.
struct Move_0007F110 {
    char unknown_00[0x10];
    Vector3 direction;
    char unknown_1c[0x4];
    float length;
};

struct Object_000A1C50 {
    void func_0007F110(Vector3 *out, const Move_0007F110 *move);
};

// Case 0 of func_00089950: the direction scaled by the length. It does not use `this`; func_00089950 calls it with
// the player still in ecx.
void Object_000A1C50::func_0007F110(Vector3 *out, const Move_0007F110 *move)
{
    out->x = move->direction.x * move->length;
    out->y = move->direction.y * move->length;
    out->z = move->direction.z * move->length;
}
