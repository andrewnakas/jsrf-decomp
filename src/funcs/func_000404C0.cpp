/* sym: ??0Object_0003ED40@@QAE@PAUNode@@HIHHPAUInfo_00040330@@@Z = 0x00040330 */
struct Node;

struct Game {
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

// What the constructor is given last: a list of entries (+0x0) and its count (+0x4).
struct Info_00040330;

// The node class whose table is at 0x1CA510 (constructor 0x40330, destructor 0x3ED40; 0x58 bytes).
struct Object_0003ED40 {
    Object_0003ED40(Node *owner, int id, unsigned int flags, int first, int second, Info_00040330 *info);

    char unknown_00[0x58];
};

// Takes an id from 0x19b6-0x1db6 (func_000128E0) and creates an Object_0003ED40 under `owner` with it (flags 0) and
// the other arguments. Returns the id.
int func_000404C0(Node *owner, int first, int second, Info_00040330 *info)
{
    int id = data_0022FCE0->func_000128E0(0x19b6, 0x1db6);
    new Object_0003ED40(owner, id, 0, first, second, info);
    return id;
}
