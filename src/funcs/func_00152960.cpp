/* sym: ??0Swizzle@@QAE@KKK@Z = 0x0014EA40 */
// A 0x24-byte description that its constructor (0x14EA40) fills from a width, a height and a depth.
struct Swizzle {
    char unknown_00[0x24];

    Swizzle(unsigned long width, unsigned long height, unsigned long depth);
};

// What a lock hands out (D3DLOCKED_RECT: Pitch, pBits).
struct LockedRect {
    long pitch;
    void *bits;
};

// Locks a level of a texture (texture, level, locked rectangle, rectangle, flags).
long __stdcall func_0018E630(void *texture, unsigned int level, LockedRect *lock, const void *rect,
                             unsigned long flags);
// Unswizzles the source into the destination (the counterpart of 0x14EAC0).
long __stdcall func_00152470(Swizzle *swizzle, void *linear, void *swizzled, unsigned long bits);

// The base of the classes whose tables are at 0x1E1290 (destructor 0x152690), 0x1E1298, 0x1E12B8 and 0x1E12D8
// (created by 0x152BC0); all four share this QueryInterface.
struct Object_001E1290 {
    virtual long __stdcall func_00152360(const void *iid, void **object);  // slot 0

    void *object;
    unsigned long size;
    char unknown_0C[0xC];
    void *texture;
    unsigned long unknown_1C;
    unsigned long format;
    void *data;
};

// The class whose table is at 0x1E12B8 (created by 0x152BC0).
struct Object_001E12B8 : Object_001E1290 {
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void __stdcall slot3();
    virtual long __stdcall func_00152960(unsigned long *second, unsigned long *first, unsigned long flags);  // slot 4
};

// Slot 4: locks level 0 of the texture at +0x18 (without flag 0x20). With a buffer at +4 the texture's data is
// unswizzled into it (32 bits for format 4, else 16), kept at +0x24 for slot 5, and the buffer is handed out;
// otherwise the locked data is. first gets the pitch.
long __stdcall Object_001E12B8::func_00152960(unsigned long *second, unsigned long *first, unsigned long flags)
{
    LockedRect lock;
    func_0018E630(texture, 0, &lock, 0, flags & ~0x20);
    void *buffer = object;
    if (buffer) {
        Swizzle swizzle(size, size, 1);
        if (format == 4)
            func_00152470(&swizzle, buffer, lock.bits, 0x20);
        else
            func_00152470(&swizzle, buffer, lock.bits, 0x10);
        if (second)
            *second = (unsigned long)object;
        data = lock.bits;
    } else {
        if (second)
            *second = (unsigned long)lock.bits;
    }
    if (first)
        *first = lock.pitch;
    return 0;
}
