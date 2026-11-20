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

// Swizzles a linear width x height picture of 8, 16 or 32-bit texels at linear into swizzled: walks the rows and
// columns while stepping the swizzled y and x through their masks ((v - mask) & mask is the next swizzled value).
// E_INVALIDARG for another texel size.
long __stdcall func_0014EAC0(Swizzle *swizzle, void *swizzled, void *linear, unsigned long bits)
{
    if (bits == 8) {
        unsigned char *from = (unsigned char *)linear;
        unsigned char *to = (unsigned char *)swizzled;
        swizzle->y = 0;
        for (unsigned long row = 0; row < swizzle->height; row++) {
            swizzle->x = 0;
            for (unsigned long column = 0; column < swizzle->width; column++) {
                to[swizzle->x | swizzle->y] = from[column];
                swizzle->x = (swizzle->x - swizzle->mask_x) & swizzle->mask_x;
            }
            from += swizzle->width;
            swizzle->y = (swizzle->y - swizzle->mask_y) & swizzle->mask_y;
        }
        return 0;
    }
    if (bits == 16) {
        unsigned short *from = (unsigned short *)linear;
        unsigned short *to = (unsigned short *)swizzled;
        swizzle->y = 0;
        for (unsigned long row = 0; row < swizzle->height; row++) {
            swizzle->x = 0;
            for (unsigned long column = 0; column < swizzle->width; column++) {
                to[swizzle->x | swizzle->y] = from[column];
                swizzle->x = (swizzle->x - swizzle->mask_x) & swizzle->mask_x;
            }
            from += swizzle->width;
            swizzle->y = (swizzle->y - swizzle->mask_y) & swizzle->mask_y;
        }
        return 0;
    }
    if (bits == 32) {
        unsigned long *from = (unsigned long *)linear;
        unsigned long *to = (unsigned long *)swizzled;
        swizzle->y = 0;
        for (unsigned long row = 0; row < swizzle->height; row++) {
            swizzle->x = 0;
            for (unsigned long column = 0; column < swizzle->width; column++) {
                to[swizzle->x | swizzle->y] = from[column];
                swizzle->x = (swizzle->x - swizzle->mask_x) & swizzle->mask_x;
            }
            from += swizzle->width;
            swizzle->y = (swizzle->y - swizzle->mask_y) & swizzle->mask_y;
        }
        return 0;
    }
    return 0x80070057;
}
