extern "C" void *memset(void *destination, int value, unsigned int size);

struct Object_00043700 {
    int func_00043700();
};

extern Object_00043700 data_001FC724;

// A record of the list at +0x1584 (0xdc bytes): its id, a flag at +0xcc and the links.
struct Record_00038460 {
    int id;
    char unknown_04[0xc8];
    int changed;
    Record_00038460 *next;
    Record_00038460 *previous;
    int unknown_d8;
};

// Object 7.
struct Object_000265A0 {
    char unknown_0000[0x74c];
    int unknown_74c;
    char unknown_0750[0xe1c];
    int step;
    char unknown_1570[0x8];
    int current;
    int unknown_157c;
    char unknown_1580[0x4];
    Record_00038460 *records;

    int func_00038460(int id);
};

// Entry 8 of the table at 0x1EC068: finds the record for the id in the list at +0x1584 (appending a cleared one, id
// -1, when there is none) and makes the id current (+0x1578). A record that held another id takes this one, is
// marked changed (+0xcc), and +0x74c takes data_001FC724's func_00043700 (+0x157c and +0x156c cleared); otherwise
// +0x156c becomes 9. Returns 1.
int Object_000265A0::func_00038460(int id)
{
    Record_00038460 *previous = 0;
    Record_00038460 **link = &records;
    while (*link) {
        if ((*link)->id == id)
            goto found;
        previous = *link;
        link = &(*link)->next;
    }
    *link = new Record_00038460;
    memset(*link, 0, sizeof(Record_00038460));
    (*link)->id = -1;
    if (previous) {
        previous->next = *link;
        (*link)->previous = previous;
    }
found:
    current = id;
    if ((*link)->id != id) {
        (*link)->changed = 1;
        (*link)->id = id;
        current = id;
        unknown_74c = data_001FC724.func_00043700();
        unknown_157c = 0;
        step = 0;
        return 1;
    }
    step = 9;
    return 1;
}
