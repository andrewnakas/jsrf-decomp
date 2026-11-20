struct Object_0006E130 {
    int func_0006E1C0(void *data);
};

extern Object_0006E130 data_00252790;

// An entry of a sound bank: its data and the next entry as offsets from the bank, and its size.
struct Entry_000278F0 {
    unsigned int data;
    unsigned int next;
    unsigned int size;
};

// A sound bank: `count` entries, the first at +0x10.
struct Bank_000278F0 {
    char unknown_00[4];
    unsigned int count;
    char unknown_08[8];
    Entry_000278F0 first;
};

struct Object_000265A0 {
    char unknown_0000[0x17a0];
    int sounds[5];

    void func_000278F0(Bank_000278F0 *bank);
};

// Called by 0x27B00 (handler 21 of the loader table 0x1EC0F0) with the bank at +0x179c: registers each entry that has
// data with func_0006E1C0 of 0x252790 and keeps its id in the matching word at +0x17a0.
void Object_000265A0::func_000278F0(Bank_000278F0 *bank)
{
    Entry_000278F0 *entry = &bank->first;
    for (unsigned int i = 0; i < bank->count; i++) {
        Entry_000278F0 *current = entry;
        entry = (Entry_000278F0 *)((char *)bank + current->next);
        if (current->size > 0) {
            sounds[i] = data_00252790.func_0006E1C0((char *)bank + current->data);
        }
    }
}
