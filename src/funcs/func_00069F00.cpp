/* sym: ??1Object_00069F00@@UAE@XZ = 0x00069F00 */
/* sym: ??1Object_00047470@@UAE@XZ = 0x00048180 */
/* sym: ?func_00048190@Object_00069F00@@UAEXPAX0PAUFrame_000479D0@@@Z = 0x00069F90 */
/* sym: ?func_00047820@Object_00069F00@@UAEXH@Z = 0x0006A100 */
// A frame of the list at +0x8 (0x6c bytes).
struct Frame_000479D0 {
    int unknown_00;
    char unknown_04[0x68];
};

// The base of the tables at 0x1CA490, 0x1CA5A8, 0x1CA5CC and 0x1CAA8C (constructor 0x48100).
struct Object_00047470 {
    virtual ~Object_00047470();
    virtual void func_00048190(void *argument, void *source, Frame_000479D0 *frame);
    virtual void func_00047470(void *first, void *second, Frame_000479D0 *frame);
    virtual void func_00048390(void *argument, void *source, Frame_000479D0 *frame);
    virtual void func_00047540();
    virtual void func_00047690(int value, int argument);
    virtual void func_00047820(int value);

    void *surface;
    Frame_000479D0 *frames;
    Frame_000479D0 *others;
    char unknown_10[0x64];
};

// The class whose table is at 0x1CC12C (constructor 0x69A30, destructor 0x69F00), built on Object_00047470.
struct Object_00069F00 : Object_00047470 {
    virtual ~Object_00069F00();
    virtual void func_00048190(void *argument, void *source, Frame_000479D0 *frame);
    virtual void func_00047820(int value);
    virtual int func_00069CC0();
    virtual void func_00069D10(Frame_000479D0 *frame);
};

// Runs slot 8 (func_00069D10) on the frames at +0x8 and +0xc before freeing each and clearing its pointer.
Object_00069F00::~Object_00069F00()
{
    Object_00069F00 *self = this;
    if (frames) {
        self->func_00069D10(frames);
        delete frames;
        frames = 0;
    }
    if (others) {
        self->func_00069D10(others);
        delete others;
        others = 0;
    }
}
