void __cdecl operator delete(void *memory);

struct Surface_000476F0 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4(int value);
    virtual void __stdcall slot5(int value);
};

// A 0x20-byte part of a frame: a buffer at +0x1c.
struct Part_00047600 {
    char unknown_00[0x1c];
    void *buffer;
};

// A frame of the list at +0x8 (0x6c bytes): two handles first, its parts at +0xc (count at +0x10), two more frames
// at +0x64 and +0x68.
struct Frame_000479D0 {
    int unknown_00;
    int unknown_04;
    char unknown_08[4];
    Part_00047600 *parts;
    unsigned int partCount;
    char unknown_14[0x50];
    Frame_000479D0 *first;
    Frame_000479D0 *second;
};

// The base of the tables at 0x1CA490, 0x1CA5A8, 0x1CA5CC and 0x1CAA8C.
struct Object_00047470 {
    virtual ~Object_00047470();
    virtual void func_00048190(void *first, void *second, Frame_000479D0 *frame);
    virtual void func_00047470(void *first, void *second, Frame_000479D0 *frame);
    virtual void func_00048390(void *first, void *second, Frame_000479D0 *frame);
    virtual void func_00047540();
    virtual void func_00047690(int value, int argument);
    virtual void func_00047820(int value);
    virtual int func_00047550();
    virtual void func_00047600(Frame_000479D0 *frame);

    void func_000476F0(int argument);
    void func_00047710(int first, int second, int third);

    Surface_000476F0 *surface;
    Frame_000479D0 *frames;
    void *unknown_0c;
    int mode;
    int unknown_14;
    int unknown_18;
    int unknown_1c;
    int unknown_20;
    unsigned int flags;
    float unknown_28;
    int unknown_2c;
    int unknown_30;
    float unknown_34;
    float unknown_38;
    int unknown_3c;
    int unknown_40;
    int unknown_44;
    float colour[4];
    float unknown_58;
    int unknown_5c;
    int unknown_60;
    void (Object_00047470::*draw)(int argument);
    void (Object_00047470::*drawAt)(int first, int second, int third);
    void **unknown_6c;
    unsigned int unknown_70;
};

// Slot 8: hands the frame's two handles (+0x0, +0x4) to slot 5 of the surface at +0x4, frees the buffers of its parts
// and the parts, then runs itself on the frames at +0x64 and +0x68.
void Object_00047470::func_00047600(Frame_000479D0 *frame)
{
    if (frame->unknown_00) {
        surface->slot5(frame->unknown_00);
    }
    if (frame->unknown_04) {
        surface->slot5(frame->unknown_04);
    }
    if (frame->parts) {
        Part_00047600 *part = frame->parts;
        for (unsigned int i = 0; i < frame->partCount; part++, i++) {
            if (part->buffer) {
                operator delete(part->buffer);
            }
        }
        operator delete(frame->parts);
    }
    if (frame->first) {
        func_00047600(frame->first);
    }
    if (frame->second) {
        func_00047600(frame->second);
    }
}
