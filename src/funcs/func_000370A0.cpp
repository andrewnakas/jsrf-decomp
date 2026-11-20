char *func_00118650(int index);
int func_00119670(int first, int second);
void func_000243B0(void *address);
char *func_00036BB0(int index, int part);
void func_00036C20(int index, char **data);
void func_00036E60(int index, char **data);

// Per kind: the name of its second part file (none when its second character is 0).
extern char *data_001EE730[];

// Per kind (16 bytes each): set when the kind's parts are already loaded.
struct Kind_000370A0 {
    int loaded;
    char unknown_04[0xc];
};

extern Kind_000370A0 data_00230DDC[];
extern int data_00230E3C;

// Object 7.
struct Object_000265A0 {
    char unknown_0000[0x16b0];
    int step;
    char *file;
    int kind;
    char unknown_16bc[4];
    int pending[1];

    int func_00025400();
    int func_00025DD0(const char *path, void **data);
    int func_000370A0();
};

// Entry 14 of the table at 0x1EC0F0: loads a step at a time (+0x16b0): the two part files (func_00036BB0) of kind 6
// (25 for kind 5) unless data_00230E3C is set, then those of the kind at +0x16b8 unless data_00230DDC says they are
// loaded (each set up by func_00036C20 / func_00036E60; the second only when its name is not empty), then file 0x34
// of func_00118650 (handed to func_00119670 and func_000243B0); then clears the kind's entry at +0x16c0 and returns 1.
// Returns 0 until then. (func_00036C20 is open; declared `void (int, char **)` from these calls.)
int Object_000265A0::func_000370A0()
{
    switch (step) {
    case 0:
        if (data_00230E3C) {
            step = 4;
            return 0;
        }
        {
            int first = kind == 5 ? 0x19 : 6;
            if (!func_00025DD0(func_00036BB0(first, 0), (void **)&file))
                break;
        }
        step = 1;
        break;
    case 1:
        if (!func_00025400())
            break;
        func_00036C20(6, &file);
        step = 2;
        return 0;
    case 2:
        if (!data_001EE730[6][1])
            break;
        {
            int first = kind == 5 ? 0x19 : 6;
            if (!func_00025DD0(func_00036BB0(first, 1), (void **)&file))
                break;
        }
        step = 3;
        return 0;
    case 3:
        if (!func_00025400())
            break;
        func_00036E60(6, &file);
        step = 4;
        return 0;
    case 4:
        if (data_00230DDC[kind].loaded) {
            step = 8;
            return 0;
        }
        if (!func_00025DD0(func_00036BB0(kind, 0), (void **)&file))
            break;
        step = 5;
        return 0;
    case 5:
        if (!func_00025400())
            break;
        func_00036C20(kind, &file);
        step = 6;
        return 0;
    case 6:
        if (!data_001EE730[kind][1])
            break;
        if (!func_00025DD0(func_00036BB0(kind, 1), (void **)&file))
            break;
        step = 7;
        return 0;
    case 7:
        if (!func_00025400())
            break;
        func_00036E60(kind, &file);
        step = 8;
        return 0;
    case 8:
        if (!func_00025DD0(func_00118650(0x34), (void **)&file))
            break;
        step = 9;
        return 0;
    case 9:
        if (!func_00025400())
            break;
        func_00119670(0x34, (int)file);
        func_000243B0(file);
        file = 0;
        step = 14;
        return 0;
    case 14:
        pending[kind] = 0;
        return 1;
    }
    return 0;
}
