struct Info_0001FED0 {
    char unknown_00[4];
    int slot;
};

struct Entry_0001FED0 {
    char unknown_00[8];
    Info_0001FED0 *info;
};

struct State_0001FED0 {
    char unknown_00[0x68];
    int *active;
    char unknown_6c[8];
    int *modes;
};

// Node child with the table at 0x1C4BA8 (destructor 0x22990); 0x233A0 runs the member-pointer table at 0x1EBC84 by
// each entry's kind at +0x68 (from 1), for the entries after the first two whose slot is active.
struct Object_00022990 {
    char unknown_00[0xdc];
    State_0001FED0 *state;
    Entry_0001FED0 **entries;

    void func_0001FD10(unsigned int index);
};

// Kind 23 of the table at 0x1EBC84: for entries after the first two whose slot is active, sets the slot's mode
// (+0x74 of the state) to 2.
void Object_00022990::func_0001FD10(unsigned int index)
{
    Entry_0001FED0 *entry = entries[index];
    State_0001FED0 *slots = state;
    if (index > 1 && slots->active[entry->info->slot])
        slots->modes[entry->info->slot] = 2;
}
