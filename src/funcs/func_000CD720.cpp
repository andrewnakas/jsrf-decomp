// A face of the first kind (0x58 bytes): its flags at 0x24 and distance at 0x38.
struct Face_000CD720 {
    char unknown_00[0x24];
    unsigned int flags;
    char unknown_28[0x10];
    float distance;
    char unknown_3c[0x1c];
};

// A face of the second kind (0x84 bytes): its flags at 0x48 and distance at 0x5c.
struct Wall_000CD720 {
    char unknown_00[0x48];
    unsigned int flags;
    char unknown_4c[0x10];
    float distance;
    char unknown_60[0x24];
};

// What a sweep found: the faces of each kind and their counts.
struct Hits_000CD720 {
    Face_000CD720 *faces;
    unsigned int faceCount;
    Wall_000CD720 *walls;
    unsigned int wallCount;
};

// The objects of 0xD6D80, 0xE89C0 and 0xEF0E0 call this with themselves in ecx; it does not use them.
struct Object_000CD720 {
    int func_000CD720(Hits_000CD720 *hits, void **nearest, unsigned int mask);
};

// Finds the nearest hit (under 1000) among the faces and walls whose flags share a bit with the mask, stores it
// (or 0), and returns 1 when it is a wall.
int Object_000CD720::func_000CD720(Hits_000CD720 *hits, void **nearest, unsigned int mask)
{
    int wall = 0;
    float best = 1000.0f;
    *nearest = 0;
    unsigned int i;
    for (i = 0; i < hits->faceCount; i++) {
        if ((hits->faces[i].flags & mask) && best > hits->faces[i].distance) {
            best = hits->faces[i].distance;
            *nearest = &hits->faces[i];
        }
    }
    for (i = 0; i < hits->wallCount; i++) {
        Wall_000CD720 *other = &hits->walls[i];
        if ((other->flags & mask) && best > other->distance) {
            wall = 1;
            best = other->distance;
            *nearest = other;
        }
    }
    return wall;
}
