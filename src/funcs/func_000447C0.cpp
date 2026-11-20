/* sym: ??0Object_000448B0@@QAE@PAUNode@@HIPAUInfo_00044250@@@Z = 0x00044250 */
struct Node;

struct Game {
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

// What the constructor is given: its 0x30 bytes are copied to +0x44.
struct Info_00044250;

// The node class whose table is at 0x1CA748 (constructor 0x44250, destructor 0x448B0; 0xc8 bytes).
struct Object_000448B0 {
    Object_000448B0(Node *owner, int id, unsigned int flags, Info_00044250 *info);

    char unknown_00[0xc8];
};

// Takes a free id from 0x15b4-0x19b4 (func_000128E0) and, when there is one, creates an Object_000448B0 under
// `owner` with it (flags 0). Returns the id, negative when none was free.
int func_000447C0(Node *owner, Info_00044250 *info)
{
    int id = data_0022FCE0->func_000128E0(0x15b4, 0x19b4);
    if (id >= 0)
        new Object_000448B0(owner, id, 0, info);
    return id;
}
