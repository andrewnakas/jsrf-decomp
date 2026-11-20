// A face func_00018260 reports (0x58 bytes).
struct Face_000E4540 {
    char unknown_00[0x38];
    float distance;
    char unknown_3c[0x1c];
};

// An edge func_00018260 reports (0x84 bytes).
struct Edge_000E4540 {
    char unknown_00[0x5c];
    float distance;
    char unknown_60[0x24];
};

// What func_00018260 reports: two lists.
struct Hit_00018260 {
    Face_000E4540 *faces;
    unsigned int faceCount;
    Edge_000E4540 *edges;
    unsigned int edgeCount;
};

struct Object_000E45D0 {
    int func_000E4540(Hit_00018260 *hit, void **nearest);
};

// Picks the face or edge of `hit` with the largest distance above 0 into `nearest`; returns 1 when it is an edge.
// Called by func_000E4C20.
int Object_000E45D0::func_000E4540(Hit_00018260 *hit, void **nearest)
{
    int edge = 0;
    *nearest = 0;
    float best = 0.0f;
    if (hit->faceCount > 0) {
        for (unsigned int i = 0; i < hit->faceCount; i++) {
            if (hit->faces[i].distance > best) {
                best = hit->faces[i].distance;
                *nearest = &hit->faces[i];
            }
        }
    }
    if (hit->edgeCount > 0) {
        for (unsigned int i = 0; i < hit->edgeCount; i++) {
            if (hit->edges[i].distance > best) {
                edge = 1;
                best = hit->edges[i].distance;
                *nearest = &hit->edges[i];
            }
        }
    }
    return edge;
}
