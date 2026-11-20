struct Track_000D5E20 {
    short unknown_00;
    short frames;
};

struct Object_000D27F0 {
    char unknown_000[0xf04];
    Track_000D5E20 *track;
    char unknown_f08[0x14];
    float length;
    char unknown_f20[0x18];
    int started;

    void func_000D5E20();
};

// A handler of the table at 0x216DC8 (entry 23): the first time, the length is the track's frame count less one.
void Object_000D27F0::func_000D5E20()
{
    if (!started) {
        length = track->frames - 1.0f;
        started = 1;
    }
}
