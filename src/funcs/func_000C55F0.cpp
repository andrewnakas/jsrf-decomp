struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_0014C730(Vector3 *target, Vector3 *direction, float scale);

struct Object_000C55F0 {
    char unknown_00[0x50];
    Vector3 position;
    Vector3 velocity;

    void func_000C55F0();
};

// Moves the position along the velocity (func_0014C730 adds direction * scale to target).
void Object_000C55F0::func_000C55F0()
{
    func_0014C730(&position, &velocity, 5.5555553f);
}
