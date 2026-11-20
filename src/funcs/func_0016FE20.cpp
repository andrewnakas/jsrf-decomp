struct Guid;

// The DirectSound library's calls that take the level at +0xe8 (0x19F0D4) and the value
// at +0xec (0x19FE40).
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

// The class whose table is at 0x1E3C08.
struct Object_001E3C08 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    long __stdcall func_0016FE20(long *position);
    long __stdcall func_00170890(long position);
    long __stdcall func_0016FE80(long *value);
    long __stdcall func_001708F0(long value);

    char unknown_04[0xc];
    SoundBuffer *buffer;
    char unknown_14[0xd4];
    long level;
    long value;
    char unknown_f0[0x18];
    long minimum;
    long maximum;
};

// Gives the level at +0xe8 as a position from 0 to 10000 between the bounds at +0x108 and +0x10c; 0x800401F0 (not
// initialised) without a buffer. On success the result is never set (retail returns whatever the argument slot
// holds). Called by 0x170920 (slot 13) and 0x170200.
long __stdcall Object_001E3C08::func_0016FE20(long *position)
{
    long result;
    if (buffer) {
        long scaled;
        if (level <= minimum)
            scaled = 0;
        else if (level >= maximum)
            scaled = 10000;
        else
            scaled = (level - minimum) * 10000 / (maximum - minimum);
        if (position)
            *position = scaled;
    } else {
        result = 0x800401F0;
    }
    return result;
}
