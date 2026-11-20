struct Guid;

// The DirectSound library's calls that take the level at +0x23c (0x19F0D4) and the value
// at +0x240 (0x19FE40).
struct SoundBuffer;
long __stdcall func_0019F0D4(SoundBuffer *buffer, long level);
long __stdcall func_0019FE40(SoundBuffer *buffer, long value);

// The DirectSound buffer, called through inline wrappers of the library's functions.
struct SoundBuffer {
    long setLevel(long level)
    {
        return func_0019F0D4(this, level);
    }
    long setValue(long value)
    {
        return func_0019FE40(this, value);
    }
};

// The class whose table is at 0x1E3B90.
struct Object_001E3B90 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    long __stdcall func_0016B840(long *position);
    long __stdcall func_0016C4F0(long position);
    long __stdcall func_0016B8A0(long *value);
    long __stdcall func_0016C550(long value);

    char unknown_04[0xc];
    SoundBuffer *buffer;
    char unknown_14[0x228];
    long level;
    long value;
    char unknown_244[0x18];
    long minimum;
    long maximum;
};

// Sets the level at +0x23c from a position from 0 to 10000 between the bounds at +0x25c and +0x260 and passes
// it on to the buffer (0x19F0D4); 0x800401F0 (not initialised) without a buffer. Called by 0x16C580, 0x16CFF0
// and 0x16D300.
long __stdcall Object_001E3B90::func_0016C4F0(long position)
{
    if (buffer) {
        level = minimum + (maximum - minimum) * position / 10000;
        return buffer->setLevel(level);
    }
    return 0x800401F0;
}
