// A loaded record of the list at +0x15c8: its id and eight tables of entries (+0x8 to +0x48), linked through +0x5c.
// Tables 2, 3, 4, 6 and 7 are indexed from the id times 0x400.
struct Record_00037480 {
    int id;
    int unknown_04;
    void **first;
    int unknown_0c;
    void **second;
    char unknown_14[0xc];
    void **third;
    int unknown_24;
    void **fourth;
    int unknown_2c;
    void **fifth;
    int unknown_34;
    void **sixth;
    int unknown_3c;
    void **seventh;
    int unknown_44;
    void **eighth;
    char unknown_4c[0x10];
    Record_00037480 *next;
};

// Object 7.
struct Object_000265A0 {
    char unknown_0000[0x15c8];
    Record_00037480 *records;

    void *func_00037480(int id, int kind, int index);
};

// Entry 6 of the table at 0x1EC200: entry `index` of table `kind` (0-7) of the record with the id, or 0.
void *Object_000265A0::func_00037480(int id, int kind, int index)
{
    for (Record_00037480 *record = records; record; record = record->next) {
        if (record->id == id) {
            switch (kind) {
            case 0:
                return record->first[index];
            case 1:
                return record->second[index];
            case 2:
                return record->third[index - (id << 10)];
            case 3:
                return record->fourth[index - (id << 10)];
            case 4:
                return record->fifth[index - (id << 10)];
            case 5:
                return record->sixth[index];
            case 6:
                return record->seventh[index - (id << 10)];
            case 7:
                return record->eighth[index - (id << 10)];
            }
        }
    }
    return 0;
}
