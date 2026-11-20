int func_00145CCB(char *buffer, const char *format, ...);
char *func_00118650(int index);
int func_00119670(int first, int second);
void func_000243B0(void *address);
char *func_00036BB0(int index, int part);
void func_00036C20(int index, char **data);
void func_00036E60(int index, char **data);

// Per enemy: the file of func_00118650, the loaded file index (-1: none) and the name (D:\Media\Enemy\<name>.dat).
extern int data_001EC3D0[];
extern int data_001EC430[];
extern const char *data_001EC310[];

// A model of a slot: its value at +0x60.
struct Part_00028500 {
    char unknown_00[0x60];
    int value;
};

// A loaded slot (0x30 bytes, from +0x278).
struct Slot_00028500 {
    Part_00028500 **parts;
    unsigned int partCount;
    void **items;
    unsigned int itemCount;
    char unknown_10[0x18];
    void *block;
    int loaded;
};

// Object 7.
struct Object_000265A0 {
    char unknown_000[0x278];
    Slot_00028500 slots[0x18];
    int current;
    int step;
    char *file;

    int func_00025400();
    int func_00025DD0(const char *path, void **data);
    void func_00027DC0(void *data);
    void func_00027F70(void *data);
    void func_00028A80();
    int func_00028500();
};

// Entry 5 of the table at 0x1EC0F0: loads the current enemy's slot a step at a time (+0x6fc): its file of
// func_00118650 (handed to func_00119670 and func_000243B0), its two parts of func_00036BB0 (set up by
// func_00036C20 / func_00036E60) when it has a loaded file, "<name>.dat" (func_00027F70, then freed) and "<name>.bin"
// into the slot's +0x28 (func_00027DC0); then gives every part of the slot its value from +0x8, runs func_00028A80
// for enemy 12 and marks the slot loaded. Returns 1 once loaded, else 0. (func_00036C20 and func_00027F70 are open;
// declared from these calls.)
int Object_000265A0::func_00028500()
{
    char path[0x100];
    Slot_00028500 *slot = slots + current;
    switch (step) {
    case 0:
        if (!func_00025DD0(func_00118650(data_001EC3D0[current]), (void **)&file))
            break;
        step = 1;
        break;
    case 1:
        if (!func_00025400())
            break;
        func_00119670(data_001EC3D0[current], (int)file);
        func_000243B0(file);
        step = 2;
        return 0;
    case 2:
        if (data_001EC430[current] == -1) {
            step = 6;
            return 0;
        }
        if (!func_00025DD0(func_00036BB0(data_001EC430[current], 0), (void **)&file))
            break;
        step = 3;
        return 0;
    case 3:
        if (!func_00025400())
            break;
        func_00036C20(data_001EC430[current], &file);
        step = 4;
        return 0;
    case 4:
        if (!func_00025DD0(func_00036BB0(data_001EC430[current], 1), (void **)&file))
            break;
        step = 5;
        return 0;
    case 5:
        if (!func_00025400())
            break;
        func_00036E60(data_001EC430[current], &file);
        step = 6;
        return 0;
    case 6:
        if (!slots[current].loaded) {
            func_00145CCB(path, "D:\\Media\\Enemy\\%s.dat", data_001EC310[current]);
            if (!func_00025DD0(path, (void **)&file))
                break;
            step = 7;
        } else {
            return 1;
        }
    case 7:
        if (!func_00025400())
            break;
        func_00027F70(file);
        func_000243B0(file);
        file = 0;
        step = 8;
    case 8:
        func_00145CCB(path, "D:\\Media\\Enemy\\%s.bin", data_001EC310[current]);
        if (!func_00025DD0(path, &slot->block))
            break;
        step = 9;
    case 9:
        if (!func_00025400())
            break;
        func_00027DC0(slot->block);
        step = 10;
    case 10:
        for (unsigned int i = 0; i < slot->partCount; i++) {
            if (i < slot->itemCount)
                slot->parts[i]->value = (int)slot->items[i];
            else
                slot->parts[i]->value = 0;
        }
        if (current == 0xc)
            func_00028A80();
        slot->loaded = 1;
        return 1;
    }
    return 0;
}
