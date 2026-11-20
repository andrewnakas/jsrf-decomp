/* const: 0x10000 */
struct Vector3 {
    float x;
    float y;
    float z;
};

float func_0014C820(float value);
float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);
int func_0014C7A0(float cosine);

// An entry of the table at +0xe0: a direction at +0x10.
struct Entry_0001F750 {
    char unknown_00[0x10];
    Vector3 direction;
};

// Node child with the table at 0x1C4BA8 (destructor 0x22990).
struct Object_00022990 {
    char unknown_00[0xe0];
    Entry_0001F750 **entries;

    int func_0001F750(unsigned int index);
};

// Called by func_00022AF0: the angle (func_0014C7A0 of the cosine) between -z and entry `index`'s direction flattened
// to the x/z plane and normalised, measured the other way round (0x10000 less) when that direction points to +x.
int Object_00022990::func_0001F750(unsigned int index)
{
    Vector3 back = {0.0f, 0.0f, -1.0f};
    Vector3 direction = entries[index]->direction;
    direction.y = 0.0f;
    float length = func_0014C820(direction.x * direction.x + direction.z * direction.z);
    float scale = 1.0f / length;
    direction.x *= scale;
    direction.z *= scale;
    float cosine = func_0014C800(&direction, &back);
    int angle = func_0014C7A0(cosine);
    if (direction.x > 0.0f)
        return 0x10000 - angle;
    return angle;
}
