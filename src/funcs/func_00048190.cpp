void *__cdecl operator new(unsigned int size);
void *__stdcall func_0006EBB0(unsigned int size);

// What a bone's first word points at: its kind flags at +0x8.
struct Buffer_00048190 {
    int unknown_00;
    unsigned int size;
    unsigned int kind;
};

// A bone of a model file (0x80 bytes): its buffer first. The other units' names for it are Group_00047160,
// Group_00047230 and, for the first of a tree, Frame_000479D0.
struct Bone_00047D40 {
    Buffer_00048190 *buffer;
    char unknown_04[0x7c];
};

// A frame of the lists at +0x8 and +0xc (0x6c bytes).
struct Frame_000479D0 {
    int unknown_00;
    int unknown_04;
    char unknown_08[4];
    int unknown_0c;
    int unknown_10;
    char unknown_14[0x58];
};

struct Group_00047160;
struct Group_00047230;
struct Out_00047230;

struct Surface_000476F0;

struct Device_00048190 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4(int size, int flags, Surface_000476F0 **out);
};

// The base of the tables at 0x1CA490, 0x1CA5A8, 0x1CA5CC and 0x1CAA8C.
struct Object_00047470 {
    virtual ~Object_00047470();
    virtual void func_00048190(void *first, void *second, Frame_000479D0 *frame);
    virtual void func_00047470();
    virtual void func_00048390(void *first, void *second, Frame_000479D0 *frame);
    virtual void func_00047540();
    virtual void func_00047690(int value, int argument);
    virtual void func_00047820(int value);
    virtual int func_00047550();
    virtual void func_00047600(Frame_000479D0 *frame);

    void func_000476F0(int argument);
    void func_00047710(int first, int second, int third);
    void func_00047730(int argument);
    void func_00047770(int argument, int first, int second);
    void func_00047160(Group_00047160 *groups, unsigned int groupCount);
    void func_00047410(int unused, Group_00047230 *group, Out_00047230 *out, int unknown);
    void func_00047480(int unused, Group_00047230 *group, Out_00047230 *out, int unknown);
    void func_00047D40(Bone_00047D40 *bone, Frame_000479D0 **cursor, int *index);
    void func_00047E60(Frame_000479D0 *frame);
    void func_00047EA0(Frame_000479D0 *frame, int *count, int *used);

    Surface_000476F0 *surface;
    Frame_000479D0 *frames;
    Frame_000479D0 *unknown_0c;
    int mode;
    int kind;
    int unknown_18;
    unsigned int frameCount;
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
    void **unknown_6c;
    unsigned int unknown_70;
};

// Slot 1: sets the object up from a model's bones: counts them (func_00047EA0), takes the kind from the last bone's
// buffer, creates the surface (+0x4) through slot 4 of `device`; for kinds 1 and 2 builds the single frame at +0xc
// first. Then, unless flag 4 is set, makes one frame per bone at +0x8 and prepares each (func_00047410, or
// func_00047480 with flag 0x10). Flag 0x20 switches the draw handlers to func_00047730 / func_00047770.
void Object_00047470::func_00048190(void *argument, void *source, Frame_000479D0 *frame)
{
    Device_00048190 *device = (Device_00048190 *)source;
    int count = 0;
    int used = 0;
    func_00047EA0(frame, &count, &used);
    func_00047160((Group_00047160 *)frame, count);
    Buffer_00048190 *buffer = ((Bone_00047D40 *)frame)[count - 1].buffer;
    if (buffer) {
        if (buffer->kind & 0x1000) {
            if (buffer->kind & 8) {
                kind = 1;
            } else {
                kind = 2;
            }
        } else {
            kind = (buffer->kind == 0x12) ? 3 : 0;
        }
        if (!(buffer->kind & 0x10)) {
            flags &= ~1;
        }
    }
    if (kind == 1 || kind == 2) {
        device->slot4(used, 0, &surface);
        unknown_0c = (Frame_000479D0 *)operator new(0x6c);
        func_00047E60(frame);
        count--;
        int index = 0;
        func_00047D40((Bone_00047D40 *)frame + count, &unknown_0c, &index);
        if (kind == 1) {
            flags |= 2;
            func_00047410((int)argument, (Group_00047230 *)((Bone_00047D40 *)frame + count),
                          (Out_00047230 *)unknown_0c, 0x100);
            mode = 4;
        }
    } else {
        if (flags & 0x10) {
            used *= 2;
        }
        device->slot4(used, 0, &surface);
    }
    frameCount = count;
    if (frameCount > 0 && !(flags & 4)) {
        frames = (Frame_000479D0 *)operator new(count * 0x6c);
        unknown_20 = func_0006EBB0(count << 6);
        Frame_000479D0 *cursor = frames;
        int index = 0;
        func_00047D40((Bone_00047D40 *)frame, &cursor, &index);
        Frame_000479D0 *current = frames;
        for (unsigned int i = 0; i < (unsigned int)count; frame = (Frame_000479D0 *)((Bone_00047D40 *)frame + 1), current++, i++) {
            Bone_00047D40 *bones = (Bone_00047D40 *)frame;
            if (mode != 4 && bones->buffer) {
                if (!(flags & 0x10)) {
                    func_00047410((int)argument, (Group_00047230 *)bones, (Out_00047230 *)current, 0);
                } else {
                    func_00047480((int)argument, (Group_00047230 *)bones, (Out_00047230 *)current, 0);
                }
            } else {
                current->unknown_00 = 0;
                current->unknown_04 = 0;
                current->unknown_10 = 0;
                current->unknown_0c = 0;
            }
        }
    }
    if (flags & 0x20) {
        draw = &Object_00047470::func_00047730;
        drawAt = &Object_00047470::func_00047770;
    }
}
