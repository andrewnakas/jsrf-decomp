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

// A slope of a zone (0x80 bytes): along its axis from `start` to `end` the height goes from `low` to `high`.
struct Ramp_0006AC40 {
    Vector3 origin;
    float start;
    float end;
    char unknown_14[0x18];
    float low;
    float high;
    char unknown_34[0x40];
    float scale;
    char unknown_78[8];
};

// A zone of the map (0x154 bytes): its bounds, its cells, the groups seen from it, its floor height and slopes.
struct Zone_0006A970 {
    Cell_000A6DC0 bounds;
    Cell_000A6DC0 *cells;
    unsigned int count;
    unsigned int *visible;
    unsigned int visibleCount;
    char unknown_a0[0x30];
    float height;
    char unknown_d4[0x34];
    Ramp_0006AC40 *ramps;
    unsigned int rampCount;
    char unknown_110[0x44];
};

struct Map_0006A970 {
    char unknown_00[4];
    Zone_0006A970 *zones;
    int count;
};

// Object 0x20C6C0: the map and the visibility mask of its groups.
struct Object_0006A960 {
    char unknown_00[4];
    Map_0006A970 *map;

    int func_0006AAA0(Vector3 *position, int hint);
};

// The zone holding the position: its bounds and one of its cells (func_0004A6F0). The hinted zone is tried first,
// then all in order; -1 for none.
int Object_0006A960::func_0006AAA0(Vector3 *position, int hint)
{
    if (map) {
        if (hint >= 0 && hint < map->count && func_0004A6F0(position, &map->zones[hint].bounds)) {
            unsigned int cell;
            for (cell = 0; cell < map->zones[hint].count; cell++) {
                if (func_0004A6F0(position, &map->zones[hint].cells[cell])) {
                    break;
                }
            }
            if (cell < map->zones[hint].count) {
                return hint;
            }
        }
        for (unsigned int zone = 0; zone < (unsigned int)map->count; zone++) {
            if (func_0004A6F0(position, &map->zones[zone].bounds)) {
                unsigned int cell;
                for (cell = 0; cell < map->zones[zone].count; cell++) {
                    if (func_0004A6F0(position, &map->zones[zone].cells[cell])) {
                        break;
                    }
                }
                if (cell < map->zones[zone].count) {
                    return zone;
                }
            }
        }
    }
    return -1;
}
