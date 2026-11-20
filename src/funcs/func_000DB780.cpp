/* sym: ??0Object_000DB3E0@@QAE@PAUNode@@HIPAUEntry_000DB3E0@@@Z = 0x000DB3E0 */
struct Node;

struct Game {
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

// One placement: 0x1c bytes, positions first.
struct Entry_000DB3E0 {
    char unknown_00[0x1c];
};

// The description func_000C0B30 hands the factory: a count at 0xc and the placements at 0x10.
struct Params_000DB3E0 {
    int kind;
    char unknown_04[8];
    unsigned int count;
    Entry_000DB3E0 *entries;
};

// The Node child func_000DB3E0 builds (0x80 bytes).
struct Object_000DB3E0 {
    Object_000DB3E0(Node *owner, int id, unsigned int flags, Entry_000DB3E0 *entry);
    virtual ~Object_000DB3E0();

    char unknown_04[0x7c];
};

// One of the factories of the table at 0x215D68: builds an Object_000DB3E0 under the object for each placement of
// the description, with the first free id in [0x12B2, 0x13B2] and the flags 0x9010.
void func_000DB780(Node *owner, Params_000DB3E0 *params)
{
    Entry_000DB3E0 *entry = params->entries;
    for (unsigned int i = 0; i < params->count; i++, entry++) {
        new Object_000DB3E0(owner, data_0022FCE0->func_000128E0(0x12b2, 0x13b2), 0x9010, entry);
    }
}
