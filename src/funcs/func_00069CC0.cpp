// A frame of the list at +0x8 (0x6c bytes): a word tested first, a position at +0x14.
struct Frame_000479D0 {
    int unknown_00;
    char unknown_04[0x10];
    float position[3];
    char unknown_20[0x4c];
};

// The class whose table is at 0x1CC12C (constructor 0x69A30, destructor 0x69F00), built on Object_00047470. Its
// slots are declared here under the names of the functions the table holds, so that slot 8 (0x69D10) can be called.
struct Object_00069F00 {
    virtual ~Object_00069F00();
    virtual void func_00069F90();
    virtual void func_00047470(void *first, void *second, Frame_000479D0 *frame);
    virtual void func_00048390();
    virtual void func_00047540();
    virtual void func_00047690(int value, int argument);
    virtual void func_0006A100();
    virtual int func_00069CC0();
    virtual void func_00069D10(Frame_000479D0 *frames);

    void *surface;
    Frame_000479D0 *frames;
    Frame_000479D0 *others;
};

// Slot 7: hands the frame blocks at +0x8 and +0xc to slot 8, frees them and clears the pointers; returns 0.
int Object_00069F00::func_00069CC0()
{
    if (frames) {
        func_00069D10(frames);
        delete frames;
        frames = 0;
    }
    if (others) {
        func_00069D10(others);
        delete others;
        others = 0;
    }
    return 0;
}
