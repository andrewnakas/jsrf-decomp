extern "C" void *memset(void *destination, int value, unsigned int size);

struct Rect {
    long left;
    long top;
    long right;
    long bottom;
};

// A surface description (D3DSURFACE_DESC on this platform: format, type, usage, size, multisample type, width,
// height).
struct SurfaceDesc {
    unsigned long format;
    unsigned long type;
    unsigned long usage;
    unsigned long size;
    unsigned long multisample;
    unsigned long width;
    unsigned long height;
};

int __stdcall func_00182B81(Rect *rect, long left, long top, long right, long bottom);
int __stdcall func_00182BA5(Rect *destination, const Rect *source);
// The surface's description (Direct3D 8's GetDesc).
long __stdcall func_0018E730(void *surface, SurfaceDesc *desc);
// Copies rectangles from one surface to another (Direct3D 8's CopyRects: source, rectangles, count, destination,
// points).
long __stdcall func_0018D7C0(void *source, const Rect *rects, unsigned int count, void *destination,
                             void *points);

// The base of the classes whose tables are at 0x1E1290, 0x1E1298, 0x1E12B8 and 0x1E12D8.
struct Object_001E1290 {
    virtual long __stdcall func_00152360(const void *iid, void **object);  // slot 0

    void *object;
};

// Kind 1 of 0x152BC0 (0x18 bytes).
struct Object_001E1298 : Object_001E1290 {
    virtual long __stdcall func_00152780(void *first, void *second, const Rect *rect);  // slot 6
};

// Slot 6: copies the rectangle (or the whole surface) of this object's surface to the surface of first (another of
// these objects) at second. E_NOTIMPL without first.
long __stdcall Object_001E1298::func_00152780(void *first, void *second, const Rect *rect)
{
    Rect source;
    SurfaceDesc desc;
    memset(&desc, 0, sizeof(desc));
    func_0018E730(object, &desc);
    if (rect == 0)
        func_00182B81(&source, 0, 0, desc.width, desc.height);
    else
        func_00182BA5(&source, rect);
    if (first == 0)
        return 0x80004001;
    func_0018D7C0(object, &source, 1, static_cast<Object_001E1290 *>(first)->object, second);
    return 0;
}
