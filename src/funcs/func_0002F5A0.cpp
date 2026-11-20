extern "C" void *memset(void *destination, int value, unsigned int size);

// The 0x114-byte block kept at +0x158c.
struct Block_0002F5A0 {
    int words[0x45];
};

struct Object_000265A0 {
    char unknown_0000[0x1588];
    int unknown_1588;
    Block_0002F5A0 *block;
    int unknown_1590;

    int func_0002F5A0(int argument);
};

// Handler 11 of the table at 0x1EC068: with +0x1588 set, 4 into +0x1590; otherwise a new cleared block at +0x158c and
// 0 into +0x1590. Returns 1.
int Object_000265A0::func_0002F5A0(int)
{
    if (unknown_1588) {
        unknown_1590 = 4;
        return 1;
    }
    block = new Block_0002F5A0;
    memset(block, 0, sizeof(Block_0002F5A0));
    unknown_1590 = 0;
    return 1;
}
