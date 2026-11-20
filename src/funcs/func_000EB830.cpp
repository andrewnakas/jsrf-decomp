/* sym: ??0Part_000EB830@@QAE@PAX@Z = 0x000EB830 */
extern "C" void *memset(void *destination, int value, unsigned int size);

// Four words.
struct Quad_000EB830 {
    int a;
    int b;
    int c;
    int d;
};

// The part that func_000EA3B0 builds at 0x30 and func_000ECB50 at 0xbc (0x6c bytes).
struct Part_000EB830 {
    Part_000EB830(void *owner);

    void *owner;
    int handles[6];
    char unknown_1c[0x30];
    Quad_000EB830 first;
    Quad_000EB830 second;
};

// Keeps the owner, marks the six handles from 4 unused (-1) and clears the two quads at 0x4c and 0x5c.
Part_000EB830::Part_000EB830(void *owner)
{
    this->owner = owner;
    for (int i = 0; i < 6; i++) {
        handles[i] = -1;
    }
    memset(&first, 0, sizeof(first));
    memset(&second, 0, sizeof(second));
}
