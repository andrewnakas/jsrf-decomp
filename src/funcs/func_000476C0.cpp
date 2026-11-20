struct Object_0006E130 {
    int func_0006E130(int id);
};

extern Object_0006E130 data_00252790;

// A count of ids and the ids.
struct Table_000476C0 {
    unsigned int count;
    int ids[1];
};

struct Object_00047470 {
    virtual ~Object_00047470();

    char unknown_04[0x5c];
    Table_000476C0 *table;

    int func_000476C0(unsigned int index);
};

// What func_0006E130 of the object at 0x252790 says for id number `index` of the table at +0x60; -1 without one.
int Object_00047470::func_000476C0(unsigned int index)
{
    if (table && index < table->count) {
        return data_00252790.func_0006E130(table->ids[index]);
    }
    return -1;
}
