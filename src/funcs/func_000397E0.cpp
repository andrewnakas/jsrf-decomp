struct Object_0006E130 {
    int func_0006E1C0(void *data);
};

extern Object_0006E130 data_00252790;

// An entry of a sound bank: its data and the next entry as offsets from the bank, and its size.
struct Entry_000397E0 {
    unsigned int data;
    unsigned int next;
    unsigned int size;
};

// A sound bank: `count` entries, the first at +0x10.
struct Bank_000397E0 {
    char unknown_00[4];
    unsigned int count;
    char unknown_08[8];
    Entry_000397E0 first;
};

struct Object_000265A0 {
    char unknown_0000[0x17e0];
    int sounds[2];
    int soundCount;

    void func_000397E0(Bank_000397E0 *bank);
};

// Called by 0x39850 (handler 22 of the loader table 0x1EC0F0) with the title bank at +0x17f0: registers each entry
// with func_0006E1C0 of 0x252790 (-1 for an empty one) into the words from +0x17e0 and counts them at +0x17e8.
void Object_000265A0::func_000397E0(Bank_000397E0 *bank)
{
    Entry_000397E0 *entry = &bank->first;
    for (unsigned int i = 0; i < bank->count; i++) {
        if (entry->size > 0) {
            sounds[i] = data_00252790.func_0006E1C0((char *)bank + entry->data);
        } else {
            sounds[i] = -1;
        }
        entry = (Entry_000397E0 *)((char *)bank + entry->next);
        soundCount++;
    }
}
