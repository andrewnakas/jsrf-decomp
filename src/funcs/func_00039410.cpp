int func_00145CCB(char *buffer, const char *format, ...);
int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

struct Game {
    int func_000127E0(int id);
};

extern Game *data_0022FCE0;

struct Object_00043700 {
    int func_00043700();
};

extern Object_00043700 data_001FC724;

// The names of the title files (A:\Media\Title\<name>.dat / .bin).
extern const char *data_001EFC44[];

struct File_0002EC50;
struct Play_00039260;

// A model of the list at +0x174c: its value at +0x60.
struct Model_00039410 {
    char unknown_00[0x60];
    int value;
};

// Object 7.
struct Object_000265A0 {
    char unknown_0000[0x174c];
    Model_00039410 **models;
    unsigned int modelCount;
    int *values;
    char unknown_1758[0x14];
    File_0002EC50 *title;
    int loaded;
    int step;
    void *file;
    char unknown_177c[0x1c];
    Play_00039260 *play;

    int func_00025400();
    int func_00025DD0(const char *path, void **data);
    void func_00038F10(File_0002EC50 *file);
    void func_00039070(void *data);
    void func_00039260(Play_00039260 *play);
    int func_00039410();
};

// Entry 20 of the table at 0x1EC0F0: loads the title a step at a time (+0x1774): "<name>.dat" of the title
// data_001FC724 picks (func_00039070, then freed), "<name>.bin" into +0x176c (func_00038F10) and
// "playdemo<nn>.dat" (nn from func_000127E0 (8)) into +0x1798 (func_00039260); then gives every model its value
// from +0x1754 and sets +0x1770. Returns 1 once loaded, else 0. (func_00038F10 is open; declared from this call.)
int Object_000265A0::func_00039410()
{
    char path[0x100];
    switch (step) {
    case 0:
        if (loaded)
            return 1;
        func_00145CCB(path, "A:\\Media\\Title\\%s.dat", data_001EFC44[data_001FC724.func_00043700()]);
        if (!func_00025DD0(path, &file))
            break;
        step = 1;
    case 1:
        if (!func_00025400())
            break;
        func_00039070(file);
        func_00145A5D(file, 0, 0x8000);
        file = 0;
        step = 2;
    case 2:
        func_00145CCB(path, "A:\\Media\\Title\\%s.bin", data_001EFC44[data_001FC724.func_00043700()]);
        if (!func_00025DD0(path, (void **)&title))
            break;
        step = 3;
    case 3:
        if (!func_00025400())
            break;
        func_00038F10(title);
        step = 4;
    case 4:
        func_00145CCB(path, "A:\\Media\\Title\\playdemo%02d.dat", data_0022FCE0->func_000127E0(8));
        if (!func_00025DD0(path, (void **)&play))
            break;
        step = 5;
    case 5:
        if (!func_00025400())
            break;
        func_00039260(play);
        step = 6;
    case 6:
        for (unsigned int i = 0; i < modelCount; i++) {
            if (models[i])
                models[i]->value = values[i];
        }
        loaded = 1;
        return 1;
    }
    return 0;
}
