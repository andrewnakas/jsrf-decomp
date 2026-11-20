extern "C" char *strcpy(char *destination, const char *source);

int func_00145CCB(char *buffer, const char *format, ...);
int func_00025770(const char *path);

struct Object_00024CF0 {
    int func_00024EF0(int page);
};

// 1 when the cache marker of `page` exists (JSRF_CACHE_COMPLETE%02d.CMP, or JSRF_CACHE_COMPLETE.CMP for page 9);
// called from slot 1 (0x25040), ignores `this`.
int Object_00024CF0::func_00024EF0(int page)
{
    char path[260];
    if (page != 9)
        func_00145CCB(path, "Z:\\Media\\Cache\\JSRF_CACHE_COMPLETE%02d.CMP", page);
    else
        strcpy(path, "Z:\\Media\\Cache\\JSRF_CACHE_COMPLETE.CMP");
    return func_00025770(path) != 0;
}
