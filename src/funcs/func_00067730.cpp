extern "C" void *memset(void *to, int value, unsigned int size);

// The settings block at +0x33c: the entry count at +0x14.
struct Settings_000676A0 {
    char unknown_00[0x14];
    int count;
};

// An entry of the table at +0x344 (0x20 bytes).
struct Entry_00067730 {
    int index;
    int kind;
    int on;
    int value;
    char unknown_10[0x10];
};

// A value of the source at +0x678 (0x10 bytes).
struct Value_00067730 {
    int value;
    char unknown_04[0xc];
};

struct Source_00067730 {
    char unknown_00[0x1c];
    Value_00067730 values[1];
};

// The class whose table is at 0x1CB0F8 (constructor 0x67B60, destructor 0x67980).
struct Object_00067980 {
    char unknown_000[0xa4];
    int unknown_0a4;
    char unknown_0a8[0x294];
    Settings_000676A0 *settings;
    char unknown_340[4];
    Entry_00067730 *entries;
    char unknown_348[0x330];
    Source_00067730 *source;

    void func_00067730(int mode);
};

// Clears the entry table (+0x344, one per setting count) and fills each entry with its index and kind 2: mode 0
// from the source's values (on when +0xa4 is clear or the value is 1), mode 1 all on with value 0.
void Object_00067980::func_00067730(int mode)
{
    if (entries) {
        memset(entries, 0, settings->count * sizeof(Entry_00067730));
        switch (mode) {
        case 0: {
            Source_00067730 *from = source;
            if (from) {
                for (int i = 0; i < settings->count; i++) {
                    entries[i].index = i;
                    entries[i].kind = 2;
                    if (!unknown_0a4) {
                        entries[i].on = 1;
                    } else if (from->values[i].value == 1) {
                        entries[i].on = 1;
                    }
                    entries[i].value = from->values[i].value;
                }
            }
            break;
        }
        case 1:
            for (int i = 0; i < settings->count; i++) {
                entries[i].index = i;
                entries[i].kind = 2;
                entries[i].on = 1;
                entries[i].value = 0;
            }
            break;
        }
    }
}
