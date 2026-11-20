int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

// A loaded talk event of the list at +0x1584 (next at +0xd0, previous at +0xd4).
struct Talk_00038B90 {
    int key;
    int kind;
    char unknown_08[4];
    unsigned int counts[5];
    void *first[5];
    void *second[5];
    void *third[5];
    void *fourth[5];
    void *fifth[5];
    void **tables[5];
    char unknown_98[0xc];
    void **entries;
    char unknown_a8[0x28];
    Talk_00038B90 *next;
    Talk_00038B90 *previous;
    void *buffer;
};

struct Object_000265A0 {
    char unknown_0000[0x1584];
    Talk_00038B90 *talks;

    void func_00038B90(int key);
};

// Handler 8 of the table at 0x1EC288: finds the talk event with `key` in the list at +0x1584, frees its buffer
// (func_00145A5D with 0x8000), deletes the entries of its kind's table (+0xa4), its five tables (+0x84, each of its
// count) and its five groups of blocks, takes it out of the list and deletes it.
void Object_000265A0::func_00038B90(int key)
{
    Talk_00038B90 **link = &talks;
    while (*link && (*link)->key != key)
        link = &(*link)->next;
    Talk_00038B90 *talk = *link;
    if (!talk)
        return;
    if (talk->buffer) {
        func_00145A5D(talk->buffer, 0, 0x8000);
        talk->buffer = 0;
    }
    if (talk->entries) {
        for (unsigned int i = 0; i < talk->counts[talk->kind]; i++) {
            if (talk->entries[i])
                delete talk->entries[i];
        }
        delete talk->entries;
    }
    int k;
    for (k = 0; k < 5; k++) {
        if (talk->tables[k]) {
            for (unsigned int i = 0; i < talk->counts[k]; i++) {
                if (talk->tables[k][i])
                    delete talk->tables[k][i];
            }
            delete talk->tables[k];
        }
    }
    for (k = 0; k < 5; k++) {
        if (talk->fifth[k])
            delete talk->fifth[k];
    }
    for (k = 0; k < 5; k++) {
        if (talk->third[k])
            delete talk->third[k];
    }
    for (k = 0; k < 5; k++) {
        if (talk->second[k])
            delete talk->second[k];
    }
    for (k = 0; k < 5; k++) {
        if (talk->first[k])
            delete talk->first[k];
    }
    for (k = 0; k < 5; k++) {
        if (talk->fourth[k])
            delete talk->fourth[k];
    }
    if (talk->next)
        talk->next->previous = talk->previous;
    if (talk->previous)
        talk->previous->next = talk->next;
    if (talks->next && talk == talks) {
        Talk_00038B90 *next = talk->next;
        delete talk;
        talks = next;
    } else if (!talks->next && talk == talks) {
        delete talk;
        talks = 0;
    } else {
        delete talk;
    }
}
