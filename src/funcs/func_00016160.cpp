/* sym: ??1Object_00016200@@QAE@XZ = 0x00016160 */
void __cdecl operator delete(void *memory) throw();

// The object at 0x22FCE8 (destroyed at exit through 0x18C950).
struct Object_00016200 {
    ~Object_00016200();

    char unknown_00[0x48];
    void *blocks[4];
    int unknown_58;
    void *block_5c;
    char unknown_60[0x10];
    void *blocks_70[3];
};

// Frees the eight blocks it holds: the four at +0x48, the three at +0x70, then +0x5c.
Object_00016200::~Object_00016200()
{
    operator delete(blocks[0]);
    operator delete(blocks[1]);
    operator delete(blocks[2]);
    operator delete(blocks[3]);
    operator delete(blocks_70[0]);
    operator delete(blocks_70[1]);
    operator delete(blocks_70[2]);
    operator delete(block_5c);
}
