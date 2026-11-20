int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);
char *func_00118650(int index);
int func_00119670(int first, int second);
void func_000243B0(void *address);

struct Object_0006E130 {
    int func_0006E1C0(void *data);
};

extern Object_0006E130 data_00252790;

// The paths of the files func_0002C040 loads first.
extern const char *data_001EDE3C[];

struct Entry_000252E0;

struct Block_000252E0;

void func_000252E0(Block_000252E0 *block);

// A texture entry of the loaded file (from +0x10): its data, then the next entry.
struct Texture_0002C040 {
    void *data;
    Texture_0002C040 *next;
};

// Object 7.
struct Object_000265A0 {
    char unknown_0000[0x1598];
    int textures[6];
    int step;
    int index;
    char *file;
    int loaded;
    char unknown_15c0[4];
    int ready;

    int func_00025400();
    int func_00025DD0(const char *path, void **data);
    int func_0002C040();
};

// Loads a step at a time (+0x15b0): the file of the index at +0x15b4 (its block set up by func_000252E0 and six
// textures registered with 0x252790 into +0x1598, then freed), then file 8 of func_00118650 (handed to func_00119670
// and func_000243B0, +0x15c4 set). Returns 1 once everything is loaded (+0x15bc set), else 0.
int Object_000265A0::func_0002C040()
{
    switch (step) {
    case 0:
        index = 0;
        step = 1;
    case 1:
        if (!func_00025DD0(data_001EDE3C[index], (void **)&file))
            break;
        step = 2;
    case 2: {
        if (!func_00025400())
            break;
        func_000252E0((Block_000252E0 *)file);
        Texture_0002C040 *texture = (Texture_0002C040 *)(file + 0x10);
        for (int i = 0; i < 6; i++) {
            textures[i] = data_00252790.func_0006E1C0(texture->data);
            texture = texture->next;
        }
        func_00145A5D(file, 0, 0x8000);
        file = 0;
        index++;
        step = 3;
        break;
    }
    case 3:
        step = 4;
    case 4:
        if (!func_00025DD0(func_00118650(8), (void **)&file))
            break;
        step = 5;
        break;
    case 5:
        if (!func_00025400())
            break;
        func_00119670(8, (int)file);
        func_000243B0(file);
        step = 6;
        file = 0;
        ready = 1;
        break;
    case 6:
        loaded = 1;
        return 1;
    }
    return 0;
}
