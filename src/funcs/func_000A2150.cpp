struct Vector3 {
    float x;
    float y;
    float z;
};

int func_00119540(int group, int index, void *position);

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0xc70];
    int group;
    char unknown_c74[0x30];
    Vector3 position;

    int func_000A2150(int which);
};

// Plays sound 3, 4 or 0x18 (which 0, 1, 2) of the group at 0xc70 at the position at 0xca4 (func_00119540); -1
// for any other.
int Object_000A1C50::func_000A2150(int which)
{
    switch (which) {
    case 0:
        return func_00119540(group, 3, &position);
    case 1:
        return func_00119540(group, 4, &position);
    case 2:
        return func_00119540(group, 0x18, &position);
    }
    return -1;
}
