int func_00145CCB(char *buffer, const char *format, ...);
int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);
char *func_00118650(int index);
int func_00119670(int first, int second);
void func_000243B0(void *address);

// The names of the people files (D:\Media\People\<name>.dat / .bin).
extern const char *data_001EE5F0[];

// A model of a slot: its value at +0x60.
struct Part_00031160 {
    char unknown_00[0x60];
    int value;
};

// A loaded slot (0x30 bytes, from +0x708).
struct Slot_00031160 {
    Part_00031160 **parts;
    unsigned int partCount;
    void **items;
    unsigned int itemCount;
    char unknown_10[0x18];
    void *block;
    int loaded;
};

// Object 7.
struct Object_000265A0 {
    char unknown_000[0x708];
    Slot_00031160 slots[1];
    int current;
    int step;
    void *file;
    void *data;

    int func_00025400();
    int func_00025DD0(const char *path, void **data);
    void func_00030D70(void *data);
    void func_00030F20(void *data);
    int func_00031160();
};

// Entry 12 of the table at 0x1EC0F0: loads the current person's slot a step at a time (+0x73c): "<name>.dat"
// (func_00030F20, then freed), "<name>.bin" into the slot's +0x28 (func_00030D70), then file 0x32 of func_00118650
// into +0x744 (handed to func_00119670 and func_000243B0); then gives every part of the slot its value from +0x8 and
// marks the slot loaded. Returns 1 once loaded (at once when slot 0 is), else 0. (func_00030F20 is open; declared
// `void (void *)` from this call.)
int Object_000265A0::func_00031160()
{
    char path[0x100];
    Slot_00031160 *slot = &slots[current];
    switch (step) {
    case 0:
        if (!slots[0].loaded) {
            func_00145CCB(path, "D:\\Media\\People\\%s.dat", data_001EE5F0[current]);
            if (!func_00025DD0(path, &file))
                break;
            step = 1;
        } else {
            return 1;
        }
    case 1:
        if (!func_00025400())
            break;
        func_00030F20(file);
        func_00145A5D(file, 0, 0x8000);
        file = 0;
        step = 2;
    case 2:
        func_00145CCB(path, "D:\\Media\\People\\%s.bin", data_001EE5F0[current]);
        if (!func_00025DD0(path, &slot->block))
            break;
        step = 3;
    case 3:
        if (!func_00025400())
            break;
        func_00030D70(slot->block);
        step = 4;
    case 4:
        if (!func_00025DD0(func_00118650(0x32), &data))
            break;
        step = 5;
        break;
    case 5:
        if (!func_00025400())
            break;
        func_00119670(0x32, (int)data);
        func_000243B0(data);
        step = 6;
        return 0;
    case 6:
        for (unsigned int i = 0; i < slot->partCount; i++) {
            if (i < slot->itemCount)
                slot->parts[i]->value = (int)slot->items[i];
            else
                slot->parts[i]->value = 0;
        }
        slot->loaded = 1;
        return 1;
    }
    return 0;
}
