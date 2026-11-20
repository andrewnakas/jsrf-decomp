/* sym: ??0Object_000D5E60@@QAE@PAUNode@@HIPAUEntry_000D5E60@@@Z = 0x000D5E60 */
struct Node;

struct Game {
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

// One placement: 0x1c bytes, positions first.
struct Entry_000D5E60 {
    char unknown_00[0x1c];
};

// The description func_000C0B30 hands the factory: a count at 0xc and the placements at 0x10.
struct Params_000D5E60 {
    int kind;
    char unknown_04[8];
    unsigned int count;
    Entry_000D5E60 *entries;
};

// The Node child func_000D5E60 builds (0xa0 bytes).
struct Object_000D5E60 {
    Object_000D5E60(Node *owner, int id, unsigned int flags, Entry_000D5E60 *entry);
    virtual ~Object_000D5E60();

    char unknown_04[0x9c];
};

// One of the factories of the table at 0x215D68: builds an Object_000D5E60 under the object for each placement of
// the description, with the first free id in [0x12B2, 0x13B2] and the flags 0x100.
void func_000D6200(Node *owner, Params_000D5E60 *params)
{
    Entry_000D5E60 *entry = params->entries;
    for (unsigned int i = 0; i < params->count; i++, entry++) {
        new Object_000D5E60(owner, data_0022FCE0->func_000128E0(0x12b2, 0x13b2), 0x100, entry);
    }
}
