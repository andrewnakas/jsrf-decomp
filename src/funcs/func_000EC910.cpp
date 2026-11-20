struct Sphere_000EC910 {
    float x;
    float y;
    float z;
    int radius;
};

struct Shape_000EC910 {
    int unknown_00;
    unsigned int first;
    char unknown_08[0xc];
    unsigned int second;
    char unknown_18[0x2c];
};

struct Object_00016200 {
    int func_0001B5C0(Shape_000EC910 *shape, Sphere_000EC910 *sphere, int radius, int *hit, int mask, int limit);
};

extern Object_00016200 data_0022FCE8;

// The class whose tables are at 0x1CEF20 (Node) and 0x1CEF18.
struct Object_000ECB50 {
    char unknown_000[0x174];
    Sphere_000EC910 spheres[4];
    unsigned int states[4];
    char unknown_1c4[0xc0];
    Shape_000EC910 shapes[4];

    void func_000EC910();
};

// For each of the four spheres at +0x174, tests it against its shape at +0x284 (func_0001B5C0 of data_0022FCE8,
// skipped when both of the shape's counts are 0): on a hit its state at +0x1b4 becomes 1 when it was above 1 and 0
// otherwise; on a miss 3 when it was below 2 and 2 otherwise.
void Object_000ECB50::func_000EC910()
{
    for (int i = 0; i < 4; i++) {
        int hit[4];
        if ((shapes[i].first > 0 || shapes[i].second > 0) &&
            data_0022FCE8.func_0001B5C0(&shapes[i], &spheres[i], spheres[i].radius, hit, 0xffff, -1)) {
            states[i] = states[i] > 1;
        } else {
            states[i] = states[i] < 2 ? 3 : 2;
        }
    }
}
