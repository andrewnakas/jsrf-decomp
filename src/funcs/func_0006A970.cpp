struct Vector3 {
    float x;
    float y;
    float z;
};

// A cell of the map (0x90 bytes).
struct Cell_000A6DC0 {
    char unknown_00[0x90];
};

int func_0004A6F0(Vector3 *position, Cell_000A6DC0 *cell);

// A zone of the map (0x154 bytes): its bounds, its cells and the groups seen from it.
struct Zone_0006A970 {
    Cell_000A6DC0 bounds;
    Cell_000A6DC0 *cells;
    unsigned int count;
    unsigned int *visible;
    unsigned int visibleCount;
    char unknown_a0[0xb4];
};

struct Map_0006A970 {
    char unknown_00[4];
    Zone_0006A970 *zones;
    unsigned int count;
};

// Object 0x20C6C0: the map and the visibility mask of its groups.
struct Object_0006A960 {
    char unknown_00[4];
    Map_0006A970 *map;
    unsigned int bits[8];

    void func_0006A970(Vector3 *position);
};

// Clears the mask, then finds the first zone whose bounds and one of whose cells hold the position
// (func_0004A6F0) and sets the bit of every group seen from it.
void Object_0006A960::func_0006A970(Vector3 *position)
{
    for (int i = 0; i < 8; i++) {
        bits[i] = 0;
    }
    if (map) {
        for (unsigned int zone = 0; zone < map->count; zone++) {
            if (func_0004A6F0(position, &map->zones[zone].bounds)) {
                unsigned int cell;
                for (cell = 0; cell < map->zones[zone].count; cell++) {
                    if (func_0004A6F0(position, &map->zones[zone].cells[cell])) {
                        break;
                    }
                }
                if (cell < map->zones[zone].count) {
                    for (unsigned int j = 0; j < map->zones[zone].visibleCount; j++) {
                        unsigned int group = map->zones[zone].visible[j];
                        bits[group >> 5] |= 1 << (group & 0x1f);
                    }
                    return;
                }
            }
        }
    }
}
