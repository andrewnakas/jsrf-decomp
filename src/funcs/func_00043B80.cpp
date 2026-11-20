/* sym: ??0Object_00043860@@QAE@PAUNode@@HIPAUInfo_00043710@@@Z = 0x00043710 */
struct Node;

struct Game {
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

// What the constructor is given: its first 0x10 bytes are copied to +0x44.
struct Info_00043710;

// The node class whose table is at 0x1CA6C8 (constructor 0x43710, destructor 0x43860; 0x98 bytes).
struct Object_00043860 {
    Object_00043860(Node *owner, int id, unsigned int flags, Info_00043710 *info);

    char unknown_00[0x98];
};

// Takes a free id from 0x15b4-0x19b4 (func_000128E0) and, when there is one, creates an Object_00043860 under
// `owner` with it (flags 0). Returns the id, negative when none was free.
int func_00043B80(Node *owner, Info_00043710 *info)
{
    int id = data_0022FCE0->func_000128E0(0x15b4, 0x19b4);
    if (id >= 0)
        new Object_00043860(owner, id, 0, info);
    return id;
}
