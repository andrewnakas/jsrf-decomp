/* cflags: /Oy- */
struct Vector3 {
    float x, y, z;
};

struct Table_00065F10;

struct Object_00039A10 {
    int func_00065F10(Table_00065F10 *table, int *indices, unsigned int count);
};

// One cell of a section (0xd0 bytes): bounds the point is tested against, and its kind.
struct Cell_000A6DC0 {
    char unknown_00[0x9c];
    unsigned int kind;
    char unknown_a0[0x30];
};

// One section (0x20 bytes): its cells and the table indices that gate it.
struct Section_000A6DC0 {
    char unknown_00[0x10];
    Cell_000A6DC0 *cells;
    unsigned int cell_count;
    int *indices;
    unsigned int index_count;
};

struct Map_000A6DC0 {
    int unknown_00;
    Section_000A6DC0 *sections;
    unsigned int section_count;
};

int func_0004A6F0(Vector3 *point, Cell_000A6DC0 *cell);

extern Object_00039A10 data_001FB820;
extern unsigned char data_00231D40[];

struct Object_000A63C0 {
    char unknown_000[0x78];
    Table_00065F10 *table;
    char unknown_07c[0x4];
    int section_index;
    char unknown_084[0x814];
    int count_898;
    float *weights;
    float distance;

    int func_000A68D0(Section_000A6DC0 *section);
    int func_000A6950(int *indices, unsigned int count)
    {
        if (table) {
            return data_001FB820.func_00065F10(table, indices, count) == 0;
        }
        return 1;
    }
    int func_000A6510(Section_000A6DC0 *section, Cell_000A6DC0 *cell, int arg, int *path, int depth, int flags,
                      Vector3 *point, int *out, unsigned int section_index);
    int func_000A6DC0(Map_000A6DC0 *map, int arg, Vector3 *point);
};

int Object_000A63C0::func_000A6DC0(Map_000A6DC0 *map, int arg, Vector3 *point)
{
    int path[512];
    int out;
    int found = 0;
    count_898 = 0;
    distance = 100000.0f;
    section_index = -1;
    weights = (float *)data_00231D40;
    for (unsigned int i = 0; i < map->section_count; i++) {
        Section_000A6DC0 *section = &map->sections[i];
        if (!func_000A68D0(section)) {
            continue;
        }
        if (!func_000A6950(section->indices, section->index_count)) {
            continue;
        }
        unsigned int j;
        for (j = 0; j < section->cell_count; j++) {
            weights[j] = -1.0f;
        }
        for (j = 0; j < section->cell_count; j++) {
            if (section->cells[j].kind == 0 && func_0004A6F0(point, &section->cells[j])) {
                path[0] = j;
                if (func_000A6510(section, &section->cells[j], arg, path, 1, 0, point, &out, i)) {
                    found = 1;
                }
            }
        }
    }
    return found;
}
