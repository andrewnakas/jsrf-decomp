// A point of a curve, aligned to 16 bytes.
struct __declspec(align(16)) Point_00099E70 {
    float x;
    float y;
    float z;
    float w;
};

// The curve the player keeps at 0x70: slot 8 gives its point at a time between 0 and 1.
struct Curve_00099E70 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8(Point_00099E70 *point, float time);
};

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x70];
    Curve_00099E70 *curve;
    char unknown_074[0xa60];
    unsigned int frames;
    unsigned int frame;
    char unknown_adc[0x200];
    float value_cdc;

    void func_00099E70();
};

// The rise for this frame: the y of the curve at 0x70 (slot 8) at this frame (0xad8) less at the last one, on the
// count of frames at 0xad4, into 0xcdc.
void Object_000A1C50::func_00099E70()
{
    float step = 1.0f / frames;
    Point_00099E70 points[2];
    curve->slot8(&points[0], (frame - 1) * step);
    curve->slot8(&points[1], frame * step);
    value_cdc = points[1].y - points[0].y;
}
