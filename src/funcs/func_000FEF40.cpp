struct Game {
    int func_000127E0(int index);
};

// An entry of the list at 0xa4.
struct Entry_000FEDB0 {
    int first;
    int second;
    int value;
    int unknown_c;
};

// Object 0x1163 (constructor func_000FF230, destructor func_000FEC60).
struct Object_000FEDB0 {
    char unknown_000[0x9c];
    int done;
    unsigned int count;
    Entry_000FEDB0 entries[8];

    void func_000FEF40(int value, int id);
};

extern Game *data_0022FCE0;

// Sets the value of the entry whose first value is `id` and clears its mark, or adds such an entry.
void Object_000FEDB0::func_000FEF40(int value, int id)
{
    data_0022FCE0->func_000127E0(12);
    for (unsigned int i = 0; i < count; i++) {
        if (entries[i].first == id) {
            entries[i].value = 0;
            entries[i].second = value;
            return;
        }
    }
    entries[count].first = id;
    entries[count].second = value;
    entries[count].value = 0;
    count++;
}
