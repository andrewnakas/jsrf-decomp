/* const: 0x100000 */
int func_00145CCB(char *buffer, const char *format, ...);
void *__stdcall func_001455A3(const char *name, unsigned long access, unsigned long share, void *security,
                              unsigned long creation, unsigned long flags, void *pattern);
int __stdcall func_00145585(void *handle);
int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);
int __stdcall func_00146078(void *file, const void *buffer, unsigned long size, unsigned long *written,
                            void *overlapped);

// The texture cache files again, in the order S0, S1, M0, M1.
extern const char *data_001EE520[4];

// Object 7.
struct Object_000265A0 {
    char unknown_0000[0x1888];
    void *block;

    int func_0002D9D0(int index);
};

// Called by the loader 0x2DBE0: writes the 1 MB block at +0x1888 to texture cache file `index` of the table at
// 0x1EE520, closes it and frees the block. 0 when the file cannot be opened, otherwise 1.
int Object_000265A0::func_0002D9D0(int index)
{
    char path[0x100];
    func_00145CCB(path, data_001EE520[index]);
    void *file = func_001455A3(path, 0x40000000, 2, 0, 4, 0x80, 0);
    if (file == (void *)-1)
        return 0;
    unsigned long written;
    func_00146078(file, block, 0x100000, &written, 0);
    func_00145585(file);
    func_00145A5D(block, 0, 0x8000);
    return 1;
}
