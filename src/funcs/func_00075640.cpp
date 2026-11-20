// An entry of the table at +0xc8 (0x10 bytes).
struct Entry_00075640 {
    unsigned int index;
    int kind;
    int on;
    unsigned int value;
};

// What +0xb4 points at: a flag at +0x48 that says the entries changed.
struct Menu_00075640 {
    char unknown_00[0x48];
    int changed;
};

// The class whose table is at 0x1CCCD8 (constructor 0x75A30, destructor 0x74D60).
struct Object_00074D60 {
    char unknown_000[0xb4];
    Menu_00075640 *menu;
    char unknown_0b8[0x10];
    Entry_00075640 *entries;
    char unknown_0cc[0xac];
    unsigned int count;

    void func_00075640();
};

// Resets each entry of the table at +0xc8 (index, kind 0, shown, value 0), then numbers its value from 0x1e, shown; marks the menu at +0xb4 changed
// for each shown entry.
void Object_00074D60::func_00075640()
{
    if (entries) {
        for (unsigned int i = 0; i < count; i++) {
            // Retail stores both values and both flags, and tests the flag again (0x75676-0x756b8).
            entries[i].index = i;
            entries[i].kind = 0;
            entries[i].on = 1;
            entries[i].value = 0;
            entries[i].value = i + 0x1e;
            entries[i].on = 1;
            if (entries[i].on) {
                menu->changed = 1;
            }
        }
    }
}
