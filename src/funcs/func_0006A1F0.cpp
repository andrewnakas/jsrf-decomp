void __cdecl operator delete(void *memory);

// A list of ids: the count and the ids after it.
struct Ids_0006E860 {
    unsigned int count;
    int ids[1];
};

struct Object_0006E130 {
    void func_0006E8D0(Ids_0006E860 *list);
};

extern Object_0006E130 data_00252790;

// The table at +0xc48: from +0x1c, where the slots of each part begin.
struct Parts_0006A1B0 {
    char unknown_00[0x1c];
    unsigned int first[1];
};

// The records of a slot's data: their count and the record indices.
struct Refs_0006A1F0 {
    unsigned int count;
    int records[1];
};

struct Slot_0006A1B0 {
    Refs_0006A1F0 *data;
    Ids_0006E860 *ids;
};

struct Model_0006A1F0 {
    virtual ~Model_0006A1F0();
};

// A shared record of the table at +0x14 (0x14 bytes): a buffer and a model, freed with the last reference.
struct Record_0006A1F0 {
    char unknown_00[4];
    void *buffer;
    char unknown_08[4];
    Model_0006A1F0 *model;
    int references;
};

struct Object_0006A1B0 {
    char unknown_000[0x14];
    Record_0006A1F0 *records;
    Slot_0006A1B0 *slots;
    char unknown_01c[0xc2c];
    Parts_0006A1B0 *parts;

    void func_0006A1F0(int part);
};

// Releases the slots of a part: drops a reference to each record of a slot's data (freeing the record's buffer and
// deleting its model with the last one), deletes the data, and hands the slot's ids back to object 0x252790
// (func_0006E8D0).
void Object_0006A1B0::func_0006A1F0(int part)
{
    for (unsigned int i = parts->first[part]; i < parts->first[part + 1]; i++) {
        if (slots[i].data) {
            for (unsigned int j = 0; j < slots[i].data->count; j++) {
                int index = slots[i].data->records[j];
                records[index].references--;
                if (records[index].references <= 0) {
                    if (records[index].buffer) {
                        operator delete(records[index].buffer);
                    }
                    records[index].buffer = 0;
                    delete records[index].model;
                    records[index].model = 0;
                }
            }
            delete slots[i].data;
            slots[i].data = 0;
        }
        if (slots[i].ids) {
            data_00252790.func_0006E8D0(slots[i].ids);
            slots[i].ids = 0;
        }
    }
}
