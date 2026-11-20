void __cdecl operator delete(void *memory);
void __stdcall func_0006EAE0(unsigned int handle);
void __stdcall func_0006EBE0(void *handle);
struct Frame_000479D0;
struct Surface_000476F0 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4(int value);
    virtual void __stdcall slot5(int value);
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
    Frame_000479D0 *unknown_0c;
    int mode;
    int unknown_14;
    int unknown_18;
    int unknown_1c;
    void *unknown_20;
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
    unsigned int *handles;
    unsigned int handleCount;
};

// Slot 7, also run by the destructor: frees the handles at +0x6c (func_0006EAE0 each) and +0x20 (func_0006EBE0), the
// frame lists at +0x8 and +0xc (slot 8 first), and releases the surface at +0x4 unless flag 0x100 is set. Returns 0.
int Object_00047470::func_00047550()
{
    if (handles) {
        for (unsigned int i = 0; i < handleCount; i++) {
            func_0006EAE0(handles[i]);
        }
        operator delete(handles);
        handles = 0;
    }
    if (unknown_20) {
        func_0006EBE0(unknown_20);
        unknown_20 = 0;
    }
    if (frames) {
        func_00047600(frames);
        operator delete(frames);
        frames = 0;
    }
    if (unknown_0c) {
        func_00047600(unknown_0c);
        operator delete(unknown_0c);
        unknown_0c = 0;
    }
    if (!(flags & 0x100) && surface) {
        surface->slot2();
        surface = 0;
    }
    return 0;
}
