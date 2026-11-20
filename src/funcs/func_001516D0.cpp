struct Params;
struct Rect6;
struct Source;

void *__stdcall func_0014A83E(unsigned long flags, unsigned long size);
int __stdcall func_0014A85B(void *handle);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014CF20(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0014CF00();  // slot 1
    virtual unsigned long __stdcall func_0014CF80();  // slot 2
    virtual long __stdcall func_00155A60(unsigned long argument1);  // slot 3
    virtual void __stdcall func_00155540(void *handle);  // slot 4
    virtual long __stdcall func_00155560(unsigned long argument1, unsigned long argument2, unsigned long argument3);  // slot 5
    virtual long __stdcall func_00155380(Params *params);  // slot 6
    virtual long __stdcall func_00154D70(int kind, Source *source);  // slot 7
    virtual void *__stdcall func_00154DC0(int kind);  // slot 8
    virtual long __stdcall func_00155150(unsigned long argument1, unsigned long argument2);  // slot 9
    virtual long __stdcall func_00155050(const Params *desc, int again);  // slot 10
    virtual int __stdcall func_00154CF0(Rect6 *out);  // slot 11
    virtual void __stdcall func_00154BB0(unsigned long mode);  // slot 12
    virtual int __stdcall func_001548E0(int index);  // slot 13
    virtual long __stdcall func_0014F720(unsigned long argument1, unsigned long argument2);  // slot 14
};

// The device in use.
extern Object_001E0F00 *data_002650D8;

// The picture slot 14 of the device takes: pixels, the width, a format word and one more.
struct Picture {
    unsigned char *pixels;
    unsigned long width;
    unsigned long format;
    unsigned long value_0C;
};

// One of the four grey levels a 2-bit pixel stands for.
static inline unsigned char Level(unsigned int bits)
{
    switch (bits) {
    case 0:
        return 0;
    case 1:
        return 0x44;
    case 2:
        return 0x88;
    default:
        return 0xFF;
    }
}

// The class whose table is at 0x1E1248 (a font, 0x24 bytes, created by 0x151CA0).
struct Object_001E1248 {
    virtual long __stdcall func_00151AC0(const void *iid, void **object);  // slot 0

    long func_001516D0(void *memory, unsigned long index, const unsigned char *data);
};

// Loads a font from data: copies its 0x600-byte header to memory, expands the 128 x 128 picture after it (2 bits
// a pixel, four to a byte) into one byte a pixel in a 32-byte aligned buffer, and gives that to the device as
// picture index (device slot 14). E_OUTOFMEMORY without the buffer.
long Object_001E1248::func_001516D0(void *memory, unsigned long index, const unsigned char *data)
{
    struct Header {
        unsigned long words[0x180];
    };
    *(Header *)memory = *(const Header *)data;
    unsigned char *buffer = (unsigned char *)func_0014A83E(0x40, 0x4020);
    if (buffer) {
        unsigned char *pixels = (unsigned char *)((unsigned long)(buffer + 0x1F) & ~0x1F);
        data += 0x600;
        unsigned char *out = pixels;
        int rows = 0x80;
        do {
            int count = 0x20;
            do {
                unsigned char bits = *data++;
                out[0] = Level(bits >> 6);
                out[1] = Level(bits >> 4 & 3);
                out[2] = Level(bits >> 2 & 3);
                out[3] = Level(bits & 3);
                out += 4;
            } while (--count);
        } while (--rows);
        Picture picture;
        picture.pixels = pixels;
        picture.width = 0x80;
        picture.format = 0xF;
        picture.value_0C = 0;
        long result = data_002650D8->func_0014F720(index, (unsigned long)&picture);
        func_0014A85B(buffer);
        return result;
    }
    return 0x8007000E;
}
