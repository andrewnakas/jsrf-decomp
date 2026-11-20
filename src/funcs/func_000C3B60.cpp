/* sym: ??0Object_000C3BE0@@QAE@XZ = 0x000C3B60 */
/* sym: ??0Object_00066980@@QAE@XZ = 0x00066920 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Object_00047470;
struct Motions_000C3350;

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Direction_000C3BE0 {
    Vector3 vector;
    float unknown_0c;
};

// The 15-bit pseudo-random generator (constructor func_00066920 clears it, func_00066980 seeds it).
struct Object_00066980 {
    Object_00066980();

    int value;

    void func_00066980(int newValue);
};

// Resource 0xc: the models, a value at 0x18 and the motions at 0x20.
struct Resource_000C3B60 {
    Object_00047470 **models;
    char unknown_04[0x14];
    void *value_18;
    char unknown_1c[4];
    Motions_000C3350 *motions;
};

void *func_00025700(unsigned int index, int first, int second, int third);

// The object in data_00257CEC (table 0x1CDDA0: only the destructor).
struct Object_000C3BE0 {
    Object_000C3BE0();
    virtual ~Object_000C3BE0() {}

    int value_04;
    Vector3 points[4];
    float ranges[4];
    int values_48[12];
    Direction_000C3BE0 directions[4];
    int angle;
    Object_00066980 random;
    Object_00047470 **models;
    void *value_c4;
    Motions_000C3350 *motions;
};

// Takes the models, the value at 0x18 and the motions of resource 0xc (func_00025700), clears 0x4, the points,
// the ranges and the words at 0x48, and seeds the generator at 0xbc with 0x7b.
Object_000C3BE0::Object_000C3BE0()
{
    Resource_000C3B60 *resource = (Resource_000C3B60 *)func_00025700(0xc, 0, 0, 0);
    models = resource->models;
    value_c4 = resource->value_18;
    motions = resource->motions;
    value_04 = 0;
    memset(points, 0, sizeof(points));
    memset(ranges, 0, sizeof(ranges));
    memset(values_48, 0, sizeof(values_48));
    random.func_00066980(0x7b);
}
