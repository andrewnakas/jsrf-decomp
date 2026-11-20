void func_00026080();

// Object 7 (whose handler tables are at 0x1EC068, 0x1EC178, 0x1EC200 and 0x1EC288): 0x25310 runs entry +0x48 of its
// member-pointer table at 0x1EC0F0 while +0x44 is 1.
struct Object_000265A0 {
    char unknown_0000[0x4c];
    const char *path;
    char unknown_0050[0x18a4];
    int done;
    int step;
    void *data;

    int func_00025400();
    int func_00025DD0(const char *path, void **data);
    int func_00026170();
};

// Entry 30 of the table at 0x1EC0F0: step 0 starts loading the file named at +0x4c into +0x18fc (func_00025DD0; step
// 1, or 3 when it fails); step 1 waits for func_00025400, then marks +0x18f4 done and moves to step 2; step 2 is done; step 3
// runs func_00026080 and marks it done. Returns 1 when done.
int Object_000265A0::func_00026170()
{
    switch (step) {
    case 0:
        step = func_00025DD0(path, &data) ? 1 : 3;
    case 1:
        if (func_00025400()) {
            done = 1;
            step = 2;
            return 1;
        }
        break;
    case 2:
        return 1;
    case 3:
        func_00026080();
        done = 1;
        return 1;
    }
    return 0;
}
