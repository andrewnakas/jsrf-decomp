/* const: 0x200000 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// The child of Node whose table is at 0x1CE1C8 (destructor func_000C7240).
struct Object_000C7910 {
    char unknown_00[0x60];
    float speed;
    float lift;
    char unknown_68[0x28];
    unsigned int flags;
    char unknown_94[0x30];
    Vector3 heading;
    Vector3 position;
    char unknown_dc[0x50];
    Vector3 slide;

    void func_000C8600();
};

// Moves the position at 0xd0: x and z by the speed at 0x60 along the heading at 0xc4 (along 0x12c under flag
// 0x200000), y by the lift at 0x64.
void Object_000C7910::func_000C8600()
{
    if (flags & 0x200000) {
        position.x += slide.x * speed;
        position.y += lift;
        position.z += slide.z * speed;
    } else {
        position.x += heading.x * speed;
        position.y += lift;
        position.z += heading.z * speed;
    }
}
