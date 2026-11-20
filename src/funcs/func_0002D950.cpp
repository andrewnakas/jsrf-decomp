/* const: 0x100000 */
void *__stdcall func_001455A3(const char *name, unsigned long access, unsigned long share, void *security,
                              unsigned long creation, unsigned long flags, void *pattern);
int __stdcall func_00145585(void *handle);
int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);
int __stdcall func_00146078(void *file, const void *buffer, unsigned long size, unsigned long *written,
                            void *overlapped);

// The texture cache files: Z:\Media\Mark\DEFAULT\JSRF_TEXS0.JTX, ..._TEXM0.JTX, ..._TEXS1.JTX, ..._TEXM1.JTX.
extern const char *data_001EE510[4];

// The 1 MB buffer the texture cache is written from.
extern void *data_00230DBC;

// Object 7.
struct Object_000265A0 {
    char unknown_0000[0x1888];
    void *block;
    char unknown_188c[0x4];
    int large;

    int func_0002D950();
};

// Writes the 1 MB texture buffer to cache file S1 (or M1 when +0x1890 is set), closes it and frees the
// block at +0x1888. 0 when the file cannot be opened, otherwise 1.
int Object_000265A0::func_0002D950()
{
    void *file;
    if (!large)
        file = func_001455A3(data_001EE510[2], 0x40000000, 2, 0, 4, 0x80, 0);
    else
        file = func_001455A3(data_001EE510[3], 0x40000000, 2, 0, 4, 0x80, 0);
    if (file == (void *)-1)
        return 0;
    unsigned long written;
    func_00146078(file, data_00230DBC, 0x100000, &written, 0);
    func_00145585(file);
    func_00145A5D(block, 0, 0x8000);
    return 1;
}
