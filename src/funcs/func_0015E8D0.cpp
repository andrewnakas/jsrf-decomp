extern "C" void *memcpy(void *destination, const void *source, unsigned int size);

void *__cdecl func_00150EA0(unsigned int size);
unsigned long __cdecl func_00159140(void *first, unsigned long second, unsigned long third);

// A picture handed to the table: its pixels, bytes per row, format, rows, palette and palette size, and a value
// kept with it.
struct Format {
    const void *pixels;
    unsigned long pitch;
    unsigned long format;
    unsigned long rows;
    const void *palette;
    unsigned long paletteSize;
    unsigned long value_18;
};

// The image the interface at data_00265110 makes for a picture.
struct Image {
    virtual long __stdcall slot0();
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall Release();
    virtual unsigned long __stdcall func_0C(unsigned long kind);
    virtual long __stdcall Lock(void **bits, unsigned long flags);
    virtual void __stdcall Unlock();
    virtual long __stdcall LockPalette(void **entries, unsigned long flags);
    virtual void __stdcall UnlockPalette();
};

// One entry of the table (0x20 bytes).
struct Slot {
    Image *image;
    void *memory;
    unsigned long format;
    unsigned long size;
    unsigned long value_10;
    unsigned long usage;
    unsigned long unknown_18[2];
};

struct Object_001E1640;

long __stdcall func_0015DCE0(Object_001E1640 *object, void *destination, unsigned long format, const Format *picture,
                             unsigned long flags);
long __stdcall func_0015EB70(Object_001E1640 *object, Image *image, unsigned long format, const Format *picture);

// A class whose table is at 0x1E1640 (26 slots; created by 0x159D70).
struct Object_001E1640 {
    virtual long __stdcall func_00159B70(const void *iid, void **object);  // slot 0
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual long __stdcall func_0015E8D0(unsigned long argument1, unsigned long argument2,
                                         unsigned long argument3);  // slot 3

    long func_0015D950(const Format *format, unsigned long second, unsigned long third, unsigned long fourth,
                       unsigned long fifth);

    Slot *slots;
    unsigned int count;
    int value_0C;
    int value_10;

    Slot *FreeSlot()
    {
        for (unsigned int i = 0; i < count; i++) {
            if (!slots[i].image)
                return &slots[i];
        }
        return 0;
    }
};

// Slot 3: puts the picture argument2 into a free entry of the table in format argument1: makes an image for it
// (func_0015D950), copies the pixels in (converting them with func_0015DCE0 when the formats differ) and the
// palette, and with flags argument3 & 0xE also keeps a copy in memory (with 8 or 4 more for flags 4 or 8). The
// entry, or 0 (the image released again) when anything fails.
long __stdcall Object_001E1640::func_0015E8D0(unsigned long argument1, unsigned long argument2,
                                              unsigned long argument3)
{
    const Format *picture = (const Format *)argument2;
    unsigned long flags = argument3;
    if (!picture)
        goto none;
    Slot *slot = FreeSlot();
    if (!slot)
        goto none;
    unsigned long usage = 0;
    if (flags & 0x100)
        usage = 0x100;
    unsigned long original = argument1;
    if (flags & 0xC)
        argument1 = (argument1 & 0xFFFFEFF3) | 2;
    Image *image = 0;
    if (func_0015D950(picture, argument1, usage, flags, (unsigned long)&image) < 0)
        goto none;
    void *bits = 0;
    long result = image->Lock(&bits, 0);
    if (result >= 0) {
        if (picture->pixels) {
            if (argument1 == picture->format)
                memcpy(bits, picture->pixels, picture->rows * picture->pitch);
            else
                result = func_0015DCE0(this, bits, argument1, picture, flags);
        }
        image->Unlock();
        if (flags & 0x200)
            result = func_0015EB70(this, image, argument1, picture);
        if (result >= 0 && picture->paletteSize) {
            result = image->LockPalette(&bits, 0);
            if (result >= 0) {
                if (picture->palette)
                    memcpy(bits, picture->palette, picture->paletteSize * 2);
                image->UnlockPalette();
            }
        }
    }
    unsigned long size = 0;
    void *memory = 0;
    if (result >= 0) {
        if (flags & 0xE) {
            size = image->func_0C(2);
            if (flags & 4)
                size += 8;
            else if (flags & 8)
                size += 4;
            memory = func_00150EA0(picture->pitch * size);
            if (!memory)
                goto failed;
            if (picture->pixels) {
                if (original == picture->format)
                    memcpy(memory, picture->pixels, picture->rows * picture->pitch);
                else
                    func_0015DCE0(this, memory, original, picture, flags);
            }
            func_00159140(memory, picture->pitch * size, 2);
        }
        slot->image = image;
        slot->memory = memory;
        slot->format = original;
        slot->size = size;
        slot->value_10 = picture->value_18;
        slot->usage = usage;
        return (long)slot;
    }
failed:
    while (image->Release())
        ;
none:
    return 0;
}
