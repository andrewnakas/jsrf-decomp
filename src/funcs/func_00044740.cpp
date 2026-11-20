/* sym: ??0Object_000432E0@@QAE@PAUNode@@HIPAUInfo_00043C00@@@Z = 0x00043C00 */
struct Node;

struct Game {
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

// What the constructor is given: its word at +0x4 is the entry count at +0x48.
struct Info_00043C00;

// The node class whose table is at 0x1CA678 (constructor 0x43C00, destructor 0x432E0; 0x4c bytes).
struct Object_000432E0 {
    Object_000432E0(Node *owner, int id, unsigned int flags, Info_00043C00 *info);

    char unknown_00[0x4c];
};

// Takes a free id from 0x15b4-0x19b4 (func_000128E0) and, when there is one, creates an Object_000432E0 under
// `owner` with it (flags 0). Returns the id, negative when none was free.
int func_00044740(Node *owner, Info_00043C00 *info)
{
    int id = data_0022FCE0->func_000128E0(0x15b4, 0x19b4);
    if (id >= 0)
        new Object_000432E0(owner, id, 0, info);
    return id;
}
