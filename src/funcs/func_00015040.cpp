struct Vector3 {
    float x;
    float y;
    float z;
};

struct Cell_000A6DC0;

int func_0004A6F0(Vector3 *point, Cell_000A6DC0 *cell);

// The records func_00015130 hands over in arrays (0x90 bytes each).
struct Face_00015040 {
    char unknown_00[0x90];
};

struct Object_00015130 {
    int func_00015040(Vector3 *point, Face_00015040 *faces, unsigned int count);
};

// 1 when func_0004A6F0 accepts the point for any of `count` records, otherwise 0.
int Object_00015130::func_00015040(Vector3 *point, Face_00015040 *faces, unsigned int count)
{
    for (unsigned int i = 0; i < count; i++) {
        if (func_0004A6F0(point, (Cell_000A6DC0 *)&faces[i]))
            return 1;
    }
    return 0;
}
