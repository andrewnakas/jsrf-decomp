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

// A pair of values a region collects from the points inside it.
struct Pair_00066AD0 {
    int first;
    int second;
};

// A region of the list at +4: its cells, the next region and its share of the pairs.
struct Region_00066AD0 {
    Cell_000A6DC0 *cells;
    unsigned int count;
    char unknown_08[4];
    Region_00066AD0 *next;
    Pair_00066AD0 *pairs;
    unsigned int pairCount;
};

// A point of the list at +0xc: where it is, its two values and the next point.
struct Point_00066AD0 {
    Vector3 position;
    int first;
    int second;
    char unknown_14[4];
    Point_00066AD0 *next;
};

// Object 0x1FB8CC.
struct Object_00039A10 {
    char unknown_00[4];
    Region_00066AD0 *regions;
    char unknown_08[4];
    Point_00066AD0 *points;
    char unknown_10[4];
    Pair_00066AD0 *pairs;
    unsigned int pairCount;

    void func_00066AD0();
};

// Shares out the pair table at +0x14: each region gets the pairs of the points lying in one of its cells
// (func_0004A6F0), in region order; +0x18 counts them all.
void Object_00039A10::func_00066AD0()
{
    pairCount = 0;
    for (Region_00066AD0 *region = regions; region; region = region->next) {
        region->pairs = &pairs[pairCount];
        Point_00066AD0 *point = points;
        region->pairCount = 0;
        for (; point; point = point->next) {
            unsigned int i;
            for (i = 0; i < region->count; i++) {
                if (func_0004A6F0(&point->position, &region->cells[i])) {
                    break;
                }
            }
            if (i < region->count) {
                region->pairs[region->pairCount].first = point->first;
                region->pairs[region->pairCount].second = point->second;
                region->pairCount++;
                pairCount++;
            }
        }
    }
}
