extern "C" char *strcpy(char *destination, const char *source);
extern "C" char *strcat(char *destination, const char *source);

int __stdcall func_00145585(void *handle);
int __stdcall func_00145D84(const char *path);

// Object 7: the cache file it writes.
struct Object_000265A0 {
    char unknown_00[0x50];
    int open;
    int written;
    char unknown_58[8];
    void *file;
    char unknown_64[0x14];
    char path[0x104];

    void func_000255C0();
};

// When a file is open (+0x50): closes it (+0x60) and, when it was being written (+0x54), deletes the file named at
// +0x78 and the same name with "~" appended (func_00145D84), then clears both flags.
void Object_000265A0::func_000255C0()
{
    if (open) {
        func_00145585(file);
        if (written) {
            char name[0x104];
            strcpy(name, path);
            strcat(name, "~");
            func_00145D84(path);
            func_00145D84(name);
            written = 0;
        }
        open = 0;
    }
}
