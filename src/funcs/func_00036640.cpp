int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);
int func_00145CCB(char *buffer, const char *format, ...);

extern char data_001C78EF[];

struct Object_0006B390 {
    void func_0006B390(unsigned int index, void *data);
};

// What +0x1cc points at: the object that takes the loaded files at +4.
struct Holder_00036640 {
    char unknown_00[4];
    Object_0006B390 *target;
};

struct Object_000265A0 {
    char unknown_0000[0x1cc];
    Holder_00036640 *holder;
    int state;
    char unknown_1d4[4];
    void *data;
    unsigned int index;
    unsigned int count;

    int func_00025400();
    int func_00025DD0(const char *path, void **data);
    void func_00036210(char *path, const char *suffix);
    int func_00036640();
};

// Handler 4 of the table at 0x1EC0F0: loads the stage's files "<stage path>NN.dat" one by one (index +0x1dc up to
// +0x1e0; func_00025DD0, then func_00025400 until it is read), hands each to func_0006B390 of the holder's target and
// frees it. Returns 1 once all are done (the holder is cleared and the state set to 2), 0 while working.
int Object_000265A0::func_00036640()
{
    char path[0x104];
    switch (state) {
    case 0:
        if (index < count) {
            func_00036210(path, data_001C78EF);
            func_00145CCB(path, "%s%02d.dat", path, index);
            if (!func_00025DD0(path, &data))
                return 0;
            state = 1;
        } else {
            holder = 0;
            state = 2;
            return 1;
        }
    case 1:
        if (!func_00025400())
            return 0;
        holder->target->func_0006B390(index, data);
        func_00145A5D(data, 0, 0x8000);
        data = 0;
        index++;
        state = 0;
        break;
    case 2:
        return 1;
    }
    return 0;
}
