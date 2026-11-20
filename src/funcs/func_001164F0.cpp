struct Entry_001160D0 {
    int id;
    const char *name;
};

struct Object_00043700 {
    int func_00043700();
};

// Object 5, the sound player.
struct Object_00116A10 {
    const char *func_001164F0(int index);
};

extern const Entry_001160D0 data_001D3A38[];
extern Object_00043700 data_001FC724;
extern const char *data_002226CC[];
extern const char *data_002226B4[];
extern const char *data_0022269C[];
extern char data_002588F0[];

int func_00145CCB(char *buffer, const char *format, ...);

// The path of sound `index` of the table at data_001D3A38, built in data_002588F0 from a directory for the
// language (func_00043700) and the entry's name: entries before id 200 use the first directory table, those before
// id 400 the second, the rest the third (the searches are func_001160D0's kind 2, inlined). Never reads this.
const char *Object_00116A10::func_001164F0(int index)
{
    int end = 0;
    do {
        if (data_001D3A38[end++].id == -1) {
            end = -1;
            break;
        }
    } while (data_001D3A38[end].id != 200);
    if (index < end) {
        func_00145CCB(data_002588F0, "%s%s", data_002226CC[data_001FC724.func_00043700()],
                      data_001D3A38[index].name);
        return data_002588F0;
    }
    end = 0;
    do {
        if (data_001D3A38[end++].id == -1) {
            end = -1;
            break;
        }
    } while (data_001D3A38[end].id != 400);
    if (index < end) {
        func_00145CCB(data_002588F0, "%s%s", data_002226B4[data_001FC724.func_00043700()],
                      data_001D3A38[index].name);
    } else {
        func_00145CCB(data_002588F0, "%s%s", data_0022269C[data_001FC724.func_00043700()],
                      data_001D3A38[index].name);
    }
    return data_002588F0;
}
