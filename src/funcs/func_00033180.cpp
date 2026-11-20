// A record of the list at +0x1e4.
struct Record_00033180 {
    int busy;
    char unknown_004[4];
    int id;
    char unknown_00c[4];
    int key;
    char unknown_014[8];
    void *value_1c;
    char unknown_020[0x64];
    void *first[14];
    void *value_bc;
    char unknown_0c0[4];
    void *value_c4;
    char unknown_0c8[0x28];
    void *second[11];
    void *third[0x149];
    void *value_640;
    void *value_644;
    void *fourth[5];
    Record_00033180 *next;
};

// A shared set of the list at +0x1f0, found by a record's key.
struct Shared_00033180 {
    int key;
    char unknown_004[8];
    void *third[0x149];
    void *value_530;
    void *value_534;
    void *fourth[5];
    Shared_00033180 *next;
};

// The shared set with this key, or 0.
inline Shared_00033180 *find_00033180(Shared_00033180 *shared, int key)
{
    for (; shared; shared = shared->next) {
        if (shared->key == key)
            return shared;
    }
    return 0;
}

// Object 7.
struct Object_000265A0 {
    char unknown_0000[0x1e4];
    Record_00033180 *records;
    char unknown_01e8[8];
    Shared_00033180 *shared;

    void *func_00033180(int id, int what, int index);
};

// Handler in the table at 0x1EC200: finds the free record (+0) with this id (or else with this id in its low byte)
// and gives one of its values by `what` (0 and 3 indexed, 9 is the constant 10); for 4, 6, 7 and 8 a missing value
// comes from the shared set (+0x1f0) with the record's key. 0 when there is none.
void *Object_000265A0::func_00033180(int id, int what, int index)
{
    Record_00033180 *record;
    for (record = records; record; record = record->next) {
        if (record->id == id && record->busy == 0)
            break;
    }
    if (!record) {
        for (record = records; record; record = record->next) {
            if ((record->id & 0xff) == id && record->busy == 0)
                break;
        }
        if (!record)
            return 0;
    }
    Shared_00033180 *shared = find_00033180(this->shared, record->key);
    switch (what) {
    case 0:
        return record->first[index];
    case 1:
        return record->value_c4;
    case 2:
        return record->value_bc;
    case 3:
        return record->second[index];
    case 4:
        if (record->third[index])
            return record->third[index];
        if (!shared)
            return 0;
        return shared->third[index];
    case 6:
        if (record->value_640)
            return record->value_640;
        if (!shared)
            return 0;
        return shared->value_530;
    case 7:
        if (record->value_644)
            return record->value_644;
        if (!shared)
            return 0;
        return shared->value_534;
    case 8:
        if (record->fourth[index])
            return record->fourth[index];
        if (!shared)
            return 0;
        return shared->fourth[index];
    case 9:
        return (void *)10;
    case 10:
        return record->value_1c;
    }
    return 0;
}
