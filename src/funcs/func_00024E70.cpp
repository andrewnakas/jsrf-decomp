extern "C" char *strcpy(char *destination, const char *source);

int func_00145CCB(char *buffer, const char *format, ...);
void *__stdcall func_001455A3(const char *name, unsigned long access, unsigned long share, void *security,
                              unsigned long creation, unsigned long flags, void *pattern);
int __stdcall func_00145585(void *handle);

// Node child (constructor 0x24C90, destructor 0x24CF0): a page index at +0x48.
struct Object_00024CF0 {
    char unknown_00[0x48];
    int page;

    int func_00024E70();
};

// Creates the empty cache marker of the current page (JSRF_CACHE_COMPLETE%02d.CMP, or JSRF_CACHE_COMPLETE.CMP for
// page 9) with CreateFile / CloseHandle; 1 when it could.
int Object_00024CF0::func_00024E70()
{
    char path[260];
    if (page != 9)
        func_00145CCB(path, "Z:\\Media\\Cache\\JSRF_CACHE_COMPLETE%02d.CMP", page);
    else
        strcpy(path, "Z:\\Media\\Cache\\JSRF_CACHE_COMPLETE.CMP");
    void *file = func_001455A3(path, 0x40000000, 0, 0, 2, 0x20000000, 0);
    if (file != (void *)-1) {
        func_00145585(file);
        return 1;
    }
    return 0;
}
