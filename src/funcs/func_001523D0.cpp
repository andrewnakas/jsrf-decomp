extern "C" int __cdecl abs(int value);

// The base of the classes whose tables are at 0x1E1290 (destructor 0x152690), 0x1E1298, 0x1E12B8 and 0x1E12D8
// (created by 0x152BC0): the surface's width and height at +8 and +0xC.
struct Object_001E1290 {
    virtual long __stdcall func_00152360(const void *iid, void **object);  // slot 0

    void func_001523D0(unsigned long second, unsigned long first, unsigned long value);

    void *object;
    unsigned int width;
    unsigned int height;
};

// Fills the locked surface (data second, pitch first) with value: 32-bit pixels when the pitch holds width of them,
// otherwise 16-bit pixels written in pairs.
void Object_001E1290::func_001523D0(unsigned long second, unsigned long first, unsigned long value)
{
    unsigned int y = 0;
    long pitch = (long)first;
    if ((unsigned long)abs(pitch) >= width * 4) {
        for (; y < height; y++) {
            for (unsigned int x = 0; x < width; x++)
                ((unsigned long *)second)[x] = value;
            second += pitch;
        }
    } else {
        unsigned long pair = value & 0xffff;
        pair |= pair << 16;
        for (; y < height; y++) {
            for (unsigned int x = 0; x < width / 2; x++)
                ((unsigned long *)second)[x] = pair;
            second += pitch;
        }
    }
}
