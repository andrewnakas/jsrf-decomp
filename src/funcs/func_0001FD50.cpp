/* sym: ??0Object_00015D50@@QAE@PAX@Z = 0x00015420 */
// An effect (constructor 0x15420, size 0x118).
struct Object_00015D50 {
    Object_00015D50(void *owner);
    virtual ~Object_00015D50();

    int unknown_04;
    float unknown_08;
    float unknown_0c;
    float unknown_10;
    int unknown_14;
    char unknown_18[0x100];

    void func_00015D90();
};

struct Owner_0001FD50 {
    char unknown_00[0x30];
    void *first;
    void *second;
};

struct Info_0001FED0 {
    char unknown_00[4];
    int slot;
};

struct Entry_0001FED0 {
    char unknown_00[8];
    Info_0001FED0 *info;
    char unknown_0c[0x68];
    Object_00015D50 *first;
    Object_00015D50 *second;
};

struct State_0001FED0 {
    char unknown_00[0x9c];
    Owner_0001FD50 **owners;
};

// Node child with the table at 0x1C4BA8 (destructor 0x22990); 0x233A0 runs the member-pointer table at 0x1EBC84 by
// each entry's kind at +0x68 (from 1).
struct Object_00022990 {
    char unknown_00[0xdc];
    State_0001FED0 *state;
    Entry_0001FED0 **entries;

    void func_0001FD50(unsigned int index);
};

// Kinds 20 and 24 of the table at 0x1EBC84: gives the entry two effects (+0x74 and +0x78) made for the slot's owners
// at +0x30 and +0x34, each set up by func_00015D90 with 0.6 at +8 and 0.08 (0.04 for the second) at +0xc.
void Object_00022990::func_0001FD50(unsigned int index)
{
    Entry_0001FED0 *entry = entries[index];
    State_0001FED0 *state = this->state;
    entry->first = new Object_00015D50(state->owners[entry->info->slot]->first);
    entry->first->func_00015D90();
    entry->first->unknown_04 = 0;
    entry->first->unknown_08 = 0.6f;
    entry->first->unknown_0c = 0.08f;
    entry->first->unknown_14 = 0;
    entry->first->unknown_10 = 0;
    entry->second = new Object_00015D50(state->owners[entry->info->slot]->second);
    entry->second->func_00015D90();
    entry->second->unknown_04 = 0;
    entry->second->unknown_08 = 0.6f;
    entry->second->unknown_0c = 0.04f;
    entry->second->unknown_14 = 0;
    entry->second->unknown_10 = 0;
}
