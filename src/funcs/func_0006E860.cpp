// A list of ids: the count and the ids after it.
struct Ids_0006E860 {
    unsigned int count;
    int ids[1];
};

struct Object_0006E130 {
    int func_0006E1C0(void *record);
    void func_0006E7B0(int id);
    Ids_0006E860 *func_0006E860(int *records);
    void func_0006E8D0(Ids_0006E860 *list);
};

// Registers each record of a block (func_0006E1C0; each record starts with its size, a size of 0 ends the block) and
// returns the list of their ids.
Ids_0006E860 *Object_0006E130::func_0006E860(int *records)
{
    int ids[100];
    unsigned int count = 0;
    int size = *records;
    while (size) {
        records++;
        ids[count] = func_0006E1C0(records);
        records = (int *)((char *)records + size);
        size = *records;
        count++;
    }
    Ids_0006E860 *list = (Ids_0006E860 *)operator new(count * 4 + 4);
    list->count = count;
    for (unsigned int i = 0; i < count; i++) {
        list->ids[i] = ids[i];
    }
    return list;
}
