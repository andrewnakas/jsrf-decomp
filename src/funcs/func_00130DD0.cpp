// The texture the strokes are painted into (at +0xb50): slot 4 locks it, slot 5 unlocks it.
struct Texture_00130DD0 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4(void **bits, int first, int second);
    virtual long __stdcall slot5();
};

// A layout of the canvas (0x2c bytes): the row length in pixels, then its size as floats at +0xc and +0x10.
struct Layout_00130DD0 {
    int pitch;
    char unknown_04[8];
    float width;
    float height;
    char unknown_14[0x18];
};

extern Layout_00130DD0 data_0022C158[];

// A stroke timer (0x1c bytes): its colour, brush size, the drop it falls by and its point.
struct Timer_001325B0 {
    bool active;
    unsigned char color[4];
    unsigned char size;
    char unknown_06[2];
    float drop;
    float x;
    float y;
    float fall;
    unsigned short delay;
    unsigned short count;
};

struct Object_00120420 {
    char unknown_000[0x1dc];
    int layout;
    char unknown_1e0[0x970];
    Texture_00130DD0 *texture;
    char unknown_b54[8];
    unsigned char *pixels;
    char unknown_b60[0x14];
    int mode;
    char unknown_b78[0x68];
    Timer_001325B0 timers[16];

    void func_00130DD0(int index);
};

// Paints one step of stroke timer `index`: locks the texture at +0xb50 and, when the point (x, y plus the drop, which
// then grows by the fall) lies inside the layout (data_0022C158 for the mode at +0xb74 and the layout at +0x1dc; x
// checked with two pixels to spare), writes the colour as BGRA there and, for brush sizes 2 and 3, into the next one or
// two pixels, and only then unlocks it.
void Object_00120420::func_00130DD0(int index)
{
    int x = (int)timers[index].x;
    int y = (int)timers[index].y + (int)timers[index].drop;
    timers[index].drop += timers[index].fall;
    void *bits;
    texture->slot4(&bits, 0, 0);
    pixels = (unsigned char *)bits;
    if (!((unsigned int)(x + 2) >= data_0022C158[mode * 5 + layout].width)
        && !((unsigned int)y >= data_0022C158[mode * 5 + layout].height)) {
        int offset = (data_0022C158[mode * 5 + layout].pitch * y + x) * 4;
        pixels[offset + 2] = timers[index].color[0];
        pixels[offset + 1] = timers[index].color[1];
        pixels[offset] = timers[index].color[2];
        pixels[offset + 3] = timers[index].color[3];
        if (timers[index].size >= 2) {
            offset = (data_0022C158[mode * 5 + layout].pitch * y + x + 1) * 4;
            pixels[offset + 2] = timers[index].color[0];
            pixels[offset + 1] = timers[index].color[1];
            pixels[offset] = timers[index].color[2];
            pixels[offset + 3] = timers[index].color[3];
        }
        if (timers[index].size >= 3) {
            offset = (data_0022C158[mode * 5 + layout].pitch * y + x + 2) * 4;
            pixels[offset + 2] = timers[index].color[0];
            pixels[offset + 1] = timers[index].color[1];
            pixels[offset] = timers[index].color[2];
            pixels[offset + 3] = timers[index].color[3];
        }
        texture->slot5();
    }
}
