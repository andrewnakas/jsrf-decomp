struct Found_00025770 {
    char bytes[0x140];
};

void *__stdcall func_00145E7E(const char *path, Found_00025770 *found);
int __stdcall func_00145585(void *handle);

// Says whether a path exists: opens a search for it (func_00145E7E) and closes the handle again.
int func_00025770(const char *path)
{
    Found_00025770 found;
    void *handle = func_00145E7E(path, &found);
    if (handle != (void *)-1) {
        func_00145585(handle);
        return 1;
    }
    return 0;
}
