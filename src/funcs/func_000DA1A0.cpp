struct Track_000DA1A0 {
    short unknown_00;
    short frames;
};

struct Object_000D8A40 {
    char unknown_000[0xb4];
    Track_000DA1A0 *track;
    char unknown_0b8[0x14];
    float length;
    char unknown_0d0[0x18];
    int started;

    void func_000DA1A0();
};

// A handler of the table at 0x2173C0 (entry 12): the first time, the length is the track's frame count less one.
void Object_000D8A40::func_000DA1A0()
{
    if (!started) {
        length = track->frames - 1.0f;
        started = 1;
    }
}
