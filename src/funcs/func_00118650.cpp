struct Object_00043700 {
    int func_00043700();
};

extern Object_00043700 data_001FC724;
extern char *data_00224FE0;
extern char *data_002227D0[][0x39];
extern char data_002589F8[];
int func_00145CCB(char *buffer, const char *format, ...);

// Builds data_00224FE0 followed by the name of an entry, from the first or the second set of 57 names by
// func_00043700 of data_001FC724, in data_002589F8, and returns it.
char *func_00118650(int index)
{
    int set = 0;
    if (!data_001FC724.func_00043700()) {
        set = 1;
    }
    func_00145CCB(data_002589F8, "%s%s", data_00224FE0, data_002227D0[set][index]);
    return data_002589F8;
}
