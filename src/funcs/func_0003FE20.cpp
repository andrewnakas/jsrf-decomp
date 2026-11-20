/* sym: ??0Object_0003F760@@QAE@PAUNode@@HIHHHH@Z = 0x0003F4E0 */
struct Node;

struct Game {
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

// The node class whose table is at 0x1CA558 (constructor 0x3F4E0, destructor 0x3F760; 0x190 bytes).
struct Object_0003F760 {
    Object_0003F760(Node *owner, int id, unsigned int flags, int a, int b, int c, int d);

    char unknown_000[0x190];
};

// Called by 0x40330: takes an id from 0x19b6-0x1db6 (func_000128E0) and creates an Object_0003F760 under `owner` with
// it (flags 0) and the other arguments. Returns the id.
int func_0003FE20(Node *owner, int a, int b, int c, int d)
{
    int id = data_0022FCE0->func_000128E0(0x19b6, 0x1db6);
    new Object_0003F760(owner, id, 0, a, b, c, d);
    return id;
}
