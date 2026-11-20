// A hit of the list func_00018920 fills in: 0x20 bytes, its distance last.
struct Hit_000F4390 {
    char unknown_00[0x1c];
    float distance;
};

struct Hits_000F4390 {
    Hit_000F4390 *items;
    unsigned int count;
};

struct Object_000F44E0 {
    Hit_000F4390 *func_000F4390(Hits_000F4390 *hits);
};

// The nearest of the hits (the smallest distance at 0x1c; the first on a tie). It does not use `this`.
Hit_000F4390 *Object_000F44E0::func_000F4390(Hits_000F4390 *hits)
{
    Hit_000F4390 *hit = hits->items;
    Hit_000F4390 *nearest = hit;
    float distance = hit->distance;
    for (unsigned int i = 0; i < hits->count; i++, hit++) {
        if (hit->distance < distance) {
            nearest = hit;
            distance = hit->distance;
        }
    }
    return nearest;
}
