/* sym: ??0Object_0006CE00@@QAE@PAUNode@@HIPAUDesc_0006C540@@HH@Z = 0x0006C840 */
struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();

    char unknown_04[0x40];
};

struct Game {
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

// What an entry of 0x20C750 is made from (0x170 bytes).
struct Desc_0006C540;

// The node class whose table is at 0x1CC158 (constructor 0x6C840, destructor 0x6CE00; 0x68 bytes).
struct Object_0006CE00 : Node {
    Object_0006CE00(Node *owner, int id, unsigned int flags, Desc_0006C540 *desc, int first, int second);

    char unknown_44[0x24];
};

// Makes an Object_0006CE00 under the owner with a free id in 0x1db7-0x1dd7 and returns the id (negative when none is
// free, then nothing is made).
int func_0006CD00(Node *owner, Desc_0006C540 *desc, int first, int second)
{
    int id = data_0022FCE0->func_000128E0(0x1db7, 0x1dd7);
    if (id >= 0) {
        new Object_0006CE00(owner, id, 0, desc, first, second);
    }
    return id;
}
