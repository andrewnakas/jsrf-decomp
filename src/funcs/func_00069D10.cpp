struct Surface_00069D10 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4(int value);
    virtual void __stdcall slot5(int value);
};

// A frame of the list at +0x8 (0x6c bytes): a word tested first, a position at +0x14, two more frames at +0x64 and
// +0x68.
struct Frame_000479D0 {
    int unknown_00;
    char unknown_04[0x10];
    float position[3];
    char unknown_20[0x44];
    Frame_000479D0 *first;
    Frame_000479D0 *second;
};

// The class whose table is at 0x1CC12C (constructor 0x69A30, destructor 0x69F00), built on Object_00047470. Its
// slots are declared here under the names of the functions the table holds.
struct Object_00069F00 {
    virtual ~Object_00069F00();
    virtual void func_00069F90();
    virtual void func_00047470();
    virtual void func_00048390();
    virtual void func_00047540();
    virtual void func_00047690(int value, int argument);
    virtual void func_0006A100();
    virtual int func_00069CC0();
    virtual void func_00069D10(Frame_000479D0 *frame);

    Surface_00069D10 *surface;
    Frame_000479D0 *frames;
    char unknown_0c[0x18];
    unsigned int flags;
};

// Slot 8: hands the frame's word to slot 5 (flag 2 of +0x24 set) or slot 4 of the surface at +0x4, then runs itself
// on the frames at +0x64 and +0x68.
void Object_00069F00::func_00069D10(Frame_000479D0 *frame)
{
    if (flags & 2) {
        if (frame->unknown_00)
            surface->slot5(frame->unknown_00);
    } else {
        if (frame->unknown_00)
            surface->slot4(frame->unknown_00);
    }
    if (frame->first)
        func_00069D10(frame->first);
    if (frame->second)
        func_00069D10(frame->second);
}
