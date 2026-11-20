struct Vector3 {
    float x;
    float y;
    float z;
};

struct Matrix_001BA950 {
    float m[4][4];
};

struct Object_00062390 {
    char unknown_0000[0x7c];
    float *depths;
    int *order;
    char unknown_0084[0xc];
    int sorted;
    Matrix_001BA950 first;
    char unknown_00d4[0x1a8];
    Vector3 position;
    char unknown_0288[0x140];
    int count;
    char unknown_03cc[0x3ac];
    int relative;
    char unknown_077c[0xd58];
    Vector3 **points;

    void func_00060470(int descending, int low, int high);
    void func_00061F10();
};

// Takes the depth (the third column of the matrix at +0x94) of each of the points at +0x14d4 (moved by the position
// when +0x778 is 1) and keeps those not behind it, with their indices, in the lists at +0x7c and +0x80 (+0x90 of
// them); sorts the list when it has two or more (func_00060470).
void Object_00062390::func_00061F10()
{
    sorted = 0;
    for (int i = 0; i < count; i++) {
        Vector3 *point = points[i];
        if (point) {
            Vector3 at = *point;
            if (relative == 1) {
                at.x += position.x;
                at.y += position.y;
                at.z += position.z;
            }
            float depth = at.x * first.m[0][2] + at.y * first.m[1][2] + at.z * first.m[2][2] + first.m[3][2];
            if (!(depth < 0.0f)) {
                depths[sorted] = depth;
                order[sorted] = i;
                sorted++;
            }
        }
    }
    if (sorted > 1) {
        func_00060470(1, 0, sorted - 1);
    }
}
