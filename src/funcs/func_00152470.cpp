// A 0x24-byte description that its constructor (0x14EA40) fills from a width, a height and a depth: the size,
// the bits of a swizzled offset that belong to each axis and the current position (as swizzled bits).
struct Swizzle {
    unsigned long width;
    unsigned long height;
    unsigned long depth;
    unsigned long mask_x;
    unsigned long mask_y;
    unsigned long mask_z;
    unsigned long x;
    unsigned long y;
    unsigned long z;
};

// Unswizzles a width x height picture of 8, 16 or 32-bit texels at swizzled into the linear picture at linear (the
// counterpart of 0x14EAC0). E_INVALIDARG for another texel size.
long __stdcall func_00152470(Swizzle *swizzle, void *linear, void *swizzled, unsigned long bits)
{
    if (bits == 8) {
        unsigned char *linearRow = (unsigned char *)linear;
        unsigned char *texels = (unsigned char *)swizzled;
        swizzle->y = 0;
        for (unsigned long row = 0; row < swizzle->height; row++) {
            swizzle->x = 0;
            for (unsigned long column = 0; column < swizzle->width; column++) {
                linearRow[column] = texels[swizzle->x | swizzle->y];
                swizzle->x = (swizzle->x - swizzle->mask_x) & swizzle->mask_x;
            }
            linearRow += swizzle->width;
            swizzle->y = (swizzle->y - swizzle->mask_y) & swizzle->mask_y;
        }
        return 0;
    }
    if (bits == 16) {
        unsigned short *linearRow = (unsigned short *)linear;
        unsigned short *texels = (unsigned short *)swizzled;
        swizzle->y = 0;
        for (unsigned long row = 0; row < swizzle->height; row++) {
            swizzle->x = 0;
            for (unsigned long column = 0; column < swizzle->width; column++) {
                linearRow[column] = texels[swizzle->x | swizzle->y];
                swizzle->x = (swizzle->x - swizzle->mask_x) & swizzle->mask_x;
            }
            linearRow += swizzle->width;
            swizzle->y = (swizzle->y - swizzle->mask_y) & swizzle->mask_y;
        }
        return 0;
    }
    if (bits == 32) {
        unsigned long *linearRow = (unsigned long *)linear;
        unsigned long *texels = (unsigned long *)swizzled;
        swizzle->y = 0;
        for (unsigned long row = 0; row < swizzle->height; row++) {
            swizzle->x = 0;
            for (unsigned long column = 0; column < swizzle->width; column++) {
                linearRow[column] = texels[swizzle->x | swizzle->y];
                swizzle->x = (swizzle->x - swizzle->mask_x) & swizzle->mask_x;
            }
            linearRow += swizzle->width;
            swizzle->y = (swizzle->y - swizzle->mask_y) & swizzle->mask_y;
        }
        return 0;
    }
    return 0x80070057;
}
