int func_00145CCB(char *buffer, const char *format, ...);
void func_00026080();

// A loaded cache table: `count` offsets from the table itself, at the offset in +4.
struct Table_000262B0 {
    unsigned int count;
    unsigned int *entries;
};

// Object 7 (whose handler tables are at 0x1EC068, 0x1EC178, 0x1EC200 and 0x1EC288): 0x25310 runs entry +0x48 of its
// member-pointer table at 0x1EC0F0 while +0x44 is 1.
struct Object_000265A0 {
    char unknown_0000[0x1900];
    Table_000262B0 *table;
    int step;
    int index;
    int done;

    int func_00025400();
    int func_00025DD0(const char *path, void **data);
    int func_000262B0();
};

// Entry 31 of the table at 0x1EC0F0: step 0 starts loading Cache%02d.tbl for the index at +0x1908 into +0x1900
// (func_00025DD0; step 1, or 2 when it fails); step 1 waits for func_00025400, turns the table's offsets into
// pointers and marks +0x190c done (returns 1); step 2 runs func_00026080 and marks it done.
int Object_000265A0::func_000262B0()
{
    char path[260];
    switch (step) {
    case 0:
        func_00145CCB(path, "D:\\Media\\Cache\\Cache%02d.tbl", index);
        if (func_00025DD0(path, (void **)&table)) {
            step = 1;
        } else {
            step = 2;
            break;
        }
    case 1:
        if (func_00025400()) {
            unsigned int base = (unsigned int)table;
            table->entries = (unsigned int *)((unsigned int)table->entries + base);
            for (unsigned int i = 0; i < table->count; i++)
                table->entries[i] += base;
            done = 1;
            return 1;
        }
        break;
    case 2:
        func_00026080();
        done = 1;
        break;
    }
    return 0;
}
