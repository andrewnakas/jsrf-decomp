struct Owner_000DCBC0 {
    char unknown_00[0x5c];
    float speed;
    float climb;
    char unknown_64[0x40];
    unsigned int flags;
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000DCBC0 {
    char unknown_000[0x4];
    Owner_000DCBC0 *owner;
    char unknown_008[0xc];
    Vector3 position;
    float forward[3];
    char unknown_02c[0xf8];
    float direction[3];

    void func_000DDEF0();
};

// Moves the position at 0x14 by the owner's speed along the direction at 0x124 (with the owner's flag 0x200000) or
// the one at 0x20, and lifts it by the owner's climb.
/* const: 0x200000 */
void Object_000DCBC0::func_000DDEF0()
{
    Owner_000DCBC0 *current = owner;
    if (current->flags & 0x200000) {
        position.x += direction[0] * current->speed;
        position.y += current->climb;
        position.z += direction[2] * current->speed;
    } else {
        position.x += forward[0] * current->speed;
        position.y += current->climb;
        position.z += forward[2] * current->speed;
    }
}
