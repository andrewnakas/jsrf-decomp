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

// Releases every id of a list (func_0006E7B0) and deletes the list.
void Object_0006E130::func_0006E8D0(Ids_0006E860 *list)
{
    for (unsigned int i = 0; i < list->count; i++) {
        func_0006E7B0(list->ids[i]);
    }
    delete list;
}
