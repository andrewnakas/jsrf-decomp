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

float __fastcall func_0014C530(const Vector3 *position, const Vector3 *axis);

// Object 0x20C6C0: the map and the visibility mask of its groups.
struct Object_0006A960 {
    char unknown_00[4];
    Map_0006A970 *map;

    int func_0006AAA0(Vector3 *position, int hint);
    float func_0006AC40(Vector3 *position, int hint);
};

// The floor height under the position: 0 outside every zone (func_0006AAA0), the zone's height, or the height on the
// first of its slopes whose span the position's distance along the slope (func_0014C530) has not passed: its low
// end before the start, else interpolated towards its high end.
float Object_0006A960::func_0006AC40(Vector3 *position, int hint)
{
    int zone = func_0006AAA0(position, hint);
    if (zone < 0) {
        return 0.0f;
    }
    float result = map->zones[zone].height;
    for (unsigned int i = 0; i < map->zones[zone].rampCount; i++) {
        Ramp_0006AC40 *ramp = &map->zones[zone].ramps[i];
        float along = func_0014C530(position, &ramp->origin);
        if (along < ramp->start) {
            result = ramp->low;
            break;
        }
        if (along < ramp->end) {
            result = ((along - ramp->start) * ramp->scale) * (ramp->high - ramp->low) + ramp->low;
            break;
        }
    }
    return result;
}
