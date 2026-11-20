/* sym: ??0Object_0003BB10@@QAE@PAUNode@@HIPAUInfo_0003B940@@@Z = 0x0003B940 */
struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);

    char unknown_00[0x28];
    Node *child;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// What the constructor is given: a list with its count at +0x4.
struct Info_0003B940;

// The node class whose table is at 0x1CA3E8 (constructor 0x3B940, destructor 0x3BB10; 0x5c bytes).
struct Object_0003BB10 {
    Object_0003BB10(Node *owner, int id, unsigned int flags, Info_0003B940 *info);

    char unknown_00[0x5c];
};

// Takes object 0x19b5 out with everything below it, when it exists, and creates a new one (an Object_0003BB10 under
// `owner`, flags 0) from `info`.
void func_0003BDD0(Node *owner, Info_0003B940 *info)
{
    Node *node = (Node *)data_0022FCE0->func_000128C0(0x19b5);
    if (node) {
        node->func_00011BE0(node);
        node->func_00011C20(node->child);
    }
    new Object_0003BB10(owner, 0x19b5, 0, info);
}
