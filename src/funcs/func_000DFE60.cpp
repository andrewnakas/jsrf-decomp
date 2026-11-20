struct Track_000DFE60 {
    short unknown_00;
    short frames;
};

struct Object_000DCBC0 {
    char unknown_000[0x194];
    Track_000DFE60 *track;
    char unknown_198[0x14];
    float length;
    char unknown_1b0[0x18];
    int started;

    void func_000DFE60();
};

// A handler of the table at 0x217AB8 (entry 23): the first time, the length is the track's frame count less one.
void Object_000DCBC0::func_000DFE60()
{
    if (!started) {
        length = track->frames - 1.0f;
        started = 1;
    }
}
