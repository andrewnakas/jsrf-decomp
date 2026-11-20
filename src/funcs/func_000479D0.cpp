// A frame of the list at +0x8 (0x6c bytes): a word tested first, a position at +0x14.
struct Frame_000479D0 {
    int unknown_00;
    char unknown_04[0x10];
    float position[3];
    char unknown_20[0x4c];
};

struct Object_00047470;

extern void (*data_001FA1B0[])(Object_00047470 *object, Frame_000479D0 *frame);

struct Object_00047470 {
    virtual ~Object_00047470();

    char unknown_04[0x18];
    unsigned int count;

    void func_000479D0(Frame_000479D0 *frames, int kind);
};

// Runs handler `kind` of the table at 0x1FA1B0 on each frame whose first word is set.
void Object_00047470::func_000479D0(Frame_000479D0 *frames, int kind)
{
    for (unsigned int i = 0; i < count; frames++, i++) {
        if (frames->unknown_00) {
            data_001FA1B0[kind](this, frames);
        }
    }
}
