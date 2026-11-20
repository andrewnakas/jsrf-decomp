// A contact of the first list (0x58 bytes): its distance at +0x38.
struct Contact_000C4A90 {
    char unknown_00[0x38];
    float distance;
    char unknown_3c[0x1c];
};

// A contact of the second list (0x84 bytes): its distance at +0x5c.
struct Other_000194B0 {
    char unknown_00[0x5c];
    float distance;
    char unknown_60[0x24];
};

// What func_0001B5C0 hands func_000194B0: two lists of contacts with their counts.
struct Hits_000C4C60 {
    Contact_000C4A90 *contacts;
    unsigned int count;
    Other_000194B0 *others;
    unsigned int otherCount;
};

struct Object_00016200 {
    int func_000194B0(Hits_000C4C60 *hits, Contact_000C4A90 **nearest);
};

// Picks the nearest contact (smallest distance) of the two lists into `nearest` (0 when both are empty); returns 1
// when it comes from the second list. It does not use `this`.
int Object_00016200::func_000194B0(Hits_000C4C60 *hits, Contact_000C4A90 **nearest)
{
    int other = 0;
    float best = -1.0f;
    *nearest = 0;
    unsigned int i;
    if (hits->count > 0) {
        best = hits->contacts[0].distance;
        *nearest = &hits->contacts[0];
        for (i = 0; i < hits->count; i++) {
            if (best > hits->contacts[i].distance) {
                best = hits->contacts[i].distance;
                *nearest = &hits->contacts[i];
            }
        }
    }
    if (hits->otherCount > 0) {
        if (best < 0.0f) {
            best = hits->others[0].distance;
            other = 1;
            *nearest = (Contact_000C4A90 *)&hits->others[0];
        }
        for (i = 0; i < hits->otherCount; i++) {
            if (best > hits->others[i].distance) {
                best = hits->others[i].distance;
                other = 1;
                *nearest = (Contact_000C4A90 *)&hits->others[i];
            }
        }
    }
    return other;
}
