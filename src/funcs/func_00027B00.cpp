int func_00145CCB(char *buffer, const char *format, ...);
int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

struct Object_00043700 {
    int func_00043700();
};

extern Object_00043700 data_001FC724;

struct Play_00027950;
struct Bank_000278F0;

// Object 7.
struct Object_000265A0 {
    char unknown_0000[0x179c];
    Bank_000278F0 *bank;
    char unknown_17a0[0x14];
    int loaded;
    int step;
    char unknown_17bc[0x20];
    Play_00027950 *play;

    int func_00025400();
    int func_00025DD0(const char *path, void **data);
    void func_000278F0(Bank_000278F0 *bank);
    void func_00027950(Play_00027950 *play);
    int func_00027B00();
};

// Loads the ending, a step at a time (+0x17b8): the demo play data (func_00027950 sets it up), then the texture bank
// of the console's language (func_000278F0; the file's memory is freed after). Returns 1 once everything is loaded
// (+0x17b4 set), 0 while a file is still loading or failed to start.
int Object_000265A0::func_00027B00()
{
    char path[0x100];
    switch (step) {
    case 0:
        func_00145CCB(path, "A:\\Media\\Ending\\playdemo01.dat");
        if (!func_00025DD0(path, (void **)&play))
            break;
        step = 1;
    case 1:
        if (!func_00025400())
            break;
        func_00027950(play);
        step = 2;
    case 2:
        switch (data_001FC724.func_00043700()) {
        case 0:
            func_00145CCB(path, "A:\\Media\\Ending\\tex_Jpn.dat");
            break;
        case 1:
            func_00145CCB(path, "A:\\Media\\Ending\\tex_Eng.dat");
            break;
        case 2:
            func_00145CCB(path, "A:\\Media\\Ending\\tex_Frn.dat");
            break;
        case 3:
            func_00145CCB(path, "A:\\Media\\Ending\\tex_Ger.dat");
            break;
        case 4:
            func_00145CCB(path, "A:\\Media\\Ending\\tex_Spa.dat");
            break;
        }
        if (!func_00025DD0(path, (void **)&bank))
            break;
        step = 3;
    case 3:
        if (!func_00025400())
            break;
        func_000278F0(bank);
        func_00145A5D(bank, 0, 0x8000);
        step = 4;
    case 4:
        loaded = 1;
        return 1;
    }
    return 0;
}
