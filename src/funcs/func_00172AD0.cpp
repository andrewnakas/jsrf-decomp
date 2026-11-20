extern "C" void *__cdecl memset(void *destination, int value, unsigned int size);

struct Guid;

// The block slot 6 takes (0x18 bytes, its size first).
struct Block {
    unsigned long size;
    unsigned long words[5];
};

// The class whose table is at 0x1E3C80.
struct Object_001E3C80 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual long __stdcall func_00172AD0(const Block *block);

    char unknown_04[0xc];
    Block block;
};

// Slot 6: copies a 0x18-byte block in to +0x10, or clears that block for a null pointer. E_INVALIDARG for a block whose
// first word is not 0x18.
long __stdcall Object_001E3C80::func_00172AD0(const Block *block)
{
    if (!block) {
        memset(&this->block, 0, sizeof(Block));
        return 0;
    }
    if (block->size == sizeof(Block)) {
        this->block = *block;
        return 0;
    }
    return 0x80070057;
}
