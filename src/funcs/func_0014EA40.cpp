/* sym: ??0Swizzle@@QAE@KKK@Z = 0x0014EA40 */
// Interleaves the coordinate bits of a texture of the given size (each dimension takes the next free address bit
// while it still has bits left), as used to swizzle and unswizzle textures.
struct Swizzle {
    Swizzle(unsigned long width, unsigned long height, unsigned long depth);

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

// The constructor: keeps the size, clears the masks and positions and builds the three masks.
Swizzle::Swizzle(unsigned long width, unsigned long height, unsigned long depth)
{
    this->width = width;
    this->height = height;
    this->depth = depth;
    mask_x = mask_y = mask_z = 0;
    x = y = z = 0;
    unsigned long bit, size, last;
    bit = size = 1;
    do {
        last = 0;
        if (size < width) {
            mask_x |= bit;
            bit <<= 1;
            last = bit;
        }
        if (size < height) {
            mask_y |= bit;
            bit <<= 1;
            last = bit;
        }
        if (size < depth) {
            mask_z |= bit;
            bit <<= 1;
            last = bit;
        }
        size <<= 1;
    } while (last);
}
