struct Vector3 {
    float x;
    float y;
    float z;
};

// A convex cell (0x90 bytes): six points on its faces, then the six face normals.
struct Cell_000A6DC0 {
    Vector3 points[6];
    Vector3 normals[6];
};

int func_0004A6F0(Vector3 *point, Cell_000A6DC0 *cell);

// A cell of 0xb8 bytes.
struct Cell_00089C50 {
    Cell_000A6DC0 cell;
    char unknown_90[0x28];
};

// A list of cells (+0x94, count +0x98) with a 3-bit value per cell in the word at +0xa4; +0xc4 marks a single cell that
// counts only while the value at +0xc8 is positive.
struct Region_00089C50 {
    char unknown_00[0x94];
    Cell_00089C50 *cells;
    unsigned int count;
    char unknown_9c[8];
    unsigned int values;
    char unknown_a8[0x1c];
    int single;
    float unknown_c8;
};

// The player.
struct Object_000A1C50 {
    char unknown_000[0xc9c];
    unsigned int unknown_c9c;
    char unknown_ca0[4];
    Vector3 position;

    int func_00089C50(Region_00089C50 *region);
};

// The index of the first cell of `region` that holds the player's position (+0xca4, func_0004A6F0) and whose 3-bit
// value is not the one at +0xc9c, or -1. A single-cell region gives 0 or -1.
int Object_000A1C50::func_00089C50(Region_00089C50 *region)
{
    if (region->single) {
        if (region->unknown_c8 > 0.0f && func_0004A6F0(&position, &region->cells->cell))
            return 0;
    } else {
        for (unsigned int i = 0; i < region->count; i++) {
            if (((region->values >> (i * 3)) & 7) != unknown_c9c && func_0004A6F0(&position, &region->cells[i].cell))
                return i;
        }
    }
    return -1;
}
