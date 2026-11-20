/* sym: ??0Object_00043950@@QAE@PAUNode@@HIH@Z = 0x00044660 */
struct Node;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The node class whose table is at 0x1CA708 (constructor 0x44660, destructor 0x43950; 0xa8 bytes).
struct Object_00043950 {
    Object_00043950(Node *owner, int id, unsigned int flags, int value);

    char unknown_00[0xa8];
};

// Called by the player (0x8E5A0): when object 9 exists, creates an Object_00043950 under it with no id, flags 1 and
// the value (kept at +0xa4).
void func_00044840(int value)
{
    Node *owner = (Node *)data_0022FCE0->func_000128C0(9);
    if (owner)
        new Object_00043950(owner, -1, 1, value);
}
