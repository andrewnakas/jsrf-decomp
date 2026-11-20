struct Sound;
struct SoundBuffer;

// DirectSound's library code: 0x19E4C6 calls slot 1 (AddRef) of the DirectSound object; 0x19E4F7 calls slot 1 of the
// object at +0x10, through the interface 0x1c bytes into it.
unsigned long __stdcall func_0019E4C6(Sound *sound);
unsigned long __stdcall func_0019E4F7(SoundBuffer *buffer);

// The class whose table is at 0x1E3B90.
struct Object_001E3B90 {
    void *vtable;
    void *outer;
    long references;
    Sound *sound;
    SoundBuffer *buffer;
    Sound *heldSound;
    SoundBuffer *heldBuffer;
    unsigned long unknown_1c;
    unsigned long flags;
};

// With flag 0x10 set at +0x20, takes a reference to the DirectSound object (flag 1) or to the object at +0x10 and
// keeps it at +0x14 or +0x18 (the slot 0x16F8F0 calls it). Always S_OK.
long __stdcall func_0016BAA0(Object_001E3B90 *self)
{
    unsigned long flags = self->flags;
    if (flags & 0x10) {
        if (flags & 1) {
            func_0019E4C6(self->sound);
            self->heldSound = self->sound;
            return 0;
        }
        func_0019E4F7(self->buffer);
        self->heldBuffer = self->buffer;
    }
    return 0;
}
