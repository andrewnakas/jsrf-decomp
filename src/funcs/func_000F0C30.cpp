/* sym: ??0Object_000F08E0@@QAE@PAUNode@@HIPAUEntry_000F08E0@@@Z = 0x000F08E0 */
struct Node;

struct Game {
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

// What func_000F08E0 reads: two points (0x1c bytes).
struct Entry_000F08E0 {
    float position[3];
    float second[3];
    int value;
};

struct Params_000F08E0 {
    char unknown_00[0xc];
    unsigned int count;
    Entry_000F08E0 *entries;
};

// The direct child of Node with the table at 0x1CEFE8 (0x78 bytes).
struct Object_000F08E0 {
    Object_000F08E0(Node *owner, int id, unsigned int flags, Entry_000F08E0 *entry);
    virtual ~Object_000F08E0();

    char unknown_04[0x74];
};

// One of the factories of the table at 0x215D68: an Object_000F08E0 under the object for each entry of the
// description, with the first free id in [0x12B2, 0x13B2] and flags 0x8010.
void func_000F0C30(Node *owner, Params_000F08E0 *params)
{
    Entry_000F08E0 *entry = params->entries;
    unsigned int i = 0;
    while (i < params->count) {
        new Object_000F08E0(owner, data_0022FCE0->func_000128E0(0x12b2, 0x13b2), 0x8010, entry);
        i++;
        entry++;
    }
}
