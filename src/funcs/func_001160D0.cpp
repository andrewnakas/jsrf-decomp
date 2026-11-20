struct Entry_001160D0 {
    int id;
    const char *name;
};

struct Object_00116A10 {
    int func_001160D0(int kind, int id);
};

extern const Entry_001160D0 data_001D3878[];
extern const Entry_001160D0 data_001D3A38[];
extern const Entry_001160D0 data_001D4DB0[];

// The index of an id in the table of a kind (kinds 0 and 1 share one), counted from the entry after the first;
// -1 when the table's -1 end comes first. 0 for the kind's empty id (1 for kind 2, else 0) and for other kinds.
// Never reads this.
int Object_00116A10::func_001160D0(int kind, int id)
{
    int i = 0;
    switch (kind) {
    case 0:
    case 1:
        if (id != 0) {
            do {
                if (data_001D3878[i++].id == -1) {
                    return -1;
                }
            } while (data_001D3878[i].id != id);
        }
        break;
    case 2:
        if (id != 1) {
            do {
                if (data_001D3A38[i++].id == -1) {
                    return -1;
                }
            } while (data_001D3A38[i].id != id);
        }
        break;
    case 3:
        if (id != 0) {
            do {
                if (data_001D4DB0[i++].id == -1) {
                    return -1;
                }
            } while (data_001D4DB0[i].id != id);
        }
        break;
    }
    return i;
}
