struct Source {
    unsigned char unknown_00;
    unsigned char kind;
    unsigned short flags;
    void *data;
};

extern void *data_00264BA4;

// Keeps the source's data at 0x264BA4: E_UNEXPECTED if the flags at +2 are set, E_FAIL unless the kind at +1 is 2,
// E_INVALIDARG without data.
long __stdcall func_0014CB20(Source *source)
{
    if (source->flags == 0) {
        if (source->kind == 2) {
            if (source->data) {
                data_00264BA4 = source->data;
                return 0;
            }
            return 0x80070057;
        }
        return 0x80004005;
    }
    return 0x8000FFFF;
}
