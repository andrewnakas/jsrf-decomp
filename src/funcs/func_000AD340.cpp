struct Vector3 {
    float x;
    float y;
    float z;
};

float __fastcall func_0014C6B0(const Vector3 *vector);

// The class whose table is at 0x1CD7B0 (only the fields this method uses).
struct Object_000ACFB0 {
    char unknown_000[0x50];
    Vector3 position;
    char unknown_05c[0x184];
    Vector3 target;
    char unknown_1ec[0x18];
    int angle;

    void func_000AD340();
};

// Turns the angle at 0x204 by ten degrees (in 65536ths of a turn, negated) per unit of distance from the position
// at 0x50 to the target at 0x1e0 (func_0014C6B0).
void Object_000ACFB0::func_000AD340()
{
    Vector3 delta;
    delta.x = target.x - position.x;
    delta.y = target.y - position.y;
    delta.z = target.z - position.z;
    angle += (int)((func_0014C6B0(&delta) * 10.0f) * -182.04445f);
}
