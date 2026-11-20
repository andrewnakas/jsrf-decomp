extern "C" char *strcpy(char *destination, const char *source);

int func_00025770(const char *path);

// Node child (constructor 0x24C90, destructor 0x24CF0): file names at +0x178.
struct Object_00024CF0 {
    char unknown_000[0x178];
    const char **names;

    int func_00024E10(int index);
};

// 1 when name `index` exists with its first letter changed to 'Z' (func_00025770), or when there are no names.
int Object_00024CF0::func_00024E10(int index)
{
    char path[260];
    if (names) {
        strcpy(path, names[index]);
        path[0] = 'Z';
        return func_00025770(path) != 0;
    }
    return 1;
}
