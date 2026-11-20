int func_00145CCB(char *buffer, const char *format, ...);

// The file names of the 0xaf entries.
extern const char *data_001EF988[0xaf];

// Object 7 (whose handler tables are at 0x1EC068, 0x1EC178, 0x1EC200 and 0x1EC288): 0x25310 runs entry +0x48 of its
// member-pointer table at 0x1EC0F0 while +0x44 is 1.
struct Object_000265A0 {
    char unknown_0000[0x1874];
    void *data;
    int done;
    unsigned int index;
    int step;

    int func_00025400();
    int func_00025DD0(const char *path, void **data);
    int func_00038DF0();
};

// Entry 24 of the table at 0x1EC0F0: for an index (+0x187c) below 0xaf, step 0 starts loading its file (names at
// 0x1EF988) into +0x1874 (func_00025DD0) and step 1 waits for func_00025400; then (or for any other index) marks
// +0x1878 done and returns 1. 0 while waiting or when the load fails.
int Object_000265A0::func_00038DF0()
{
    char path[256];
    if (index < 0xaf) {
        switch (step) {
        case 0:
            func_00145CCB(path, data_001EF988[index]);
            if (!func_00025DD0(path, &data))
                return 0;
            step = 1;
        case 1:
            if (!func_00025400())
                return 0;
            step = 2;
        case 2:
            break;
        default:
            return 0;
        }
    }
    done = 1;
    return 1;
}
