struct Vector3 {
    float x;
    float y;
    float z;
};

// What +0x8 of an entry points at: per range of the list at +0x14 a value at +0x18; per range of the main list the
// entry it follows (+0x8c) and the offset from it (+0x90).
struct Info_0001F340 {
    char unknown_00[0x18];
    int *values;
    char unknown_1c[0x70];
    unsigned int *parents;
    Vector3 *offsets;
};

struct Entry_0001F340 {
    char unknown_00[8];
    Info_0001F340 *info;
};

// Node child with the table at 0x1C4BA8.
struct Object_00022990 {
    char unknown_00[0xe0];
    Entry_0001F340 **entries;

    int func_0001EBE0(unsigned int index, unsigned int key, int extra, int *kind);
    void func_0001EDD0(unsigned int index, int range, unsigned int key, Vector3 *position);
    void func_0001EFC0(unsigned int index, int range, unsigned int key, Vector3 *position, Vector3 *direction,
                       int *value);
    int func_0001F340(unsigned int index, unsigned int key, Vector3 *position, int *value, Vector3 *direction,
                      int *out, int extra);
};

// The pose of entry `index` at the key: finds the key's range (func_0001EBE0); returns 0 without one. A range of the
// main list follows its parent entry (recursively) and adds its offset (returns 1); an extra range runs
// func_0001EDD0 (returns 2); any other runs func_0001EFC0 and stores the range's value (returns 1).
int Object_00022990::func_0001F340(unsigned int index, unsigned int key, Vector3 *position, int *value,
                                    Vector3 *direction, int *out, int extra)
{
    Info_0001F340 *info = entries[index]->info;
    int kind;
    int range = func_0001EBE0(index, key, extra, &kind);
    if (range < 0)
        return 0;
    switch (kind) {
    case 1: {
        int unused;
        func_0001F340(info->parents[range], key, position, &unused, direction, out, 0);
        position->x += info->offsets[range].x;
        position->y += info->offsets[range].y;
        position->z += info->offsets[range].z;
        return 1;
    }
    case 2:
        func_0001EDD0(index, range, key, position);
        return 2;
    default:
        func_0001EFC0(index, range, key, position, direction, out);
        *value = info->values[range];
        return 1;
    }
}
