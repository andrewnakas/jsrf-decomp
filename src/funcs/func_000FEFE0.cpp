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

    void func_000FEFE0(int unused, int id);
};

extern Game *data_0022FCE0;

// Marks the entry whose first value is `id`; sets the flag at 0x9c when as many of the first four entries are marked
// as func_000127E0(12) of the game gives.
void Object_000FEDB0::func_000FEFE0(int, int id)
{
    for (unsigned int i = 0; i < 8; i++) {
        if (entries[i].first == id) {
            entries[i].value = 1;
            break;
        }
    }
    unsigned int marked = 0;
    if (entries[0].value == 1) {
        marked = 1;
    }
    if (entries[1].value == 1) {
        marked++;
    }
    if (entries[2].value == 1) {
        marked++;
    }
    if (entries[3].value == 1) {
        marked++;
    }
    if (marked >= data_0022FCE0->func_000127E0(12)) {
        done = 1;
    }
}
