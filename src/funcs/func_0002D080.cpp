int func_00145CCB(char *buffer, const char *format, ...);
int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

struct Game {
    void func_000127C0(int id, int value);
};

extern Game *data_0022FCE0;

struct Object_0006E130 {
    int func_0006E660(int index, void *data);
};

extern Object_0006E130 data_00252790;

// The paths of the files object 7 loads.
extern const char *data_001EDE3C[];

// Object 7.
struct Object_000265A0 {
    char unknown_0000[0x18ac];
    void *file;
    int done;
    int alternate;
    int step;

    int func_00025400();
    int func_00025DD0(const char *path, void **data);
    void func_000255C0();
    int func_0002D080();
};

// Entry 26 of the table at 0x1EC0F0: loads a step at a time (+0x18b8) the two files 1 and 2 of data_001EDE3C (3 and
// 4 with +0x18b4 set) and hands each to data_00252790's func_0006E660 (as 0 and 1), freeing it; then runs
// func_000127C0 (0x1c5, 1). Sets +0x18b0 and returns 1 when done or when a file fails to load (then running
// func_000255C0), else 0. (func_0006E660 is open; declared `int (int, void *)` from these calls.)
int Object_000265A0::func_0002D080()
{
    char path[0x100];
    switch (step) {
    case 0:
        if (!alternate)
            func_00145CCB(path, data_001EDE3C[1]);
        else
            func_00145CCB(path, data_001EDE3C[3]);
        if (func_00025DD0(path, &file)) {
            step = 1;
        } else {
            func_000255C0();
            done = 1;
            return 1;
        }
    case 1:
        if (!func_00025400())
            break;
        data_00252790.func_0006E660(0, file);
        func_00145A5D(file, 0, 0x8000);
        file = 0;
        step = 2;
        break;
    case 2:
        if (!alternate)
            func_00145CCB(path, data_001EDE3C[2]);
        else
            func_00145CCB(path, data_001EDE3C[4]);
        if (func_00025DD0(path, &file)) {
            step = 3;
        } else {
            func_000255C0();
            done = 1;
            return 1;
        }
    case 3:
        if (!func_00025400())
            break;
        data_00252790.func_0006E660(1, file);
        func_00145A5D(file, 0, 0x8000);
        file = 0;
        step = 4;
        return 0;
    case 4:
        data_0022FCE0->func_000127C0(0x1c5, 1);
        done = 1;
        return 1;
    }
    return 0;
}
