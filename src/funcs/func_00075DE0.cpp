/* const: 0x10003 */
struct Node;

struct Game {
    void func_000127C0(int id, int value);
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

void func_00024620(unsigned int colour, float time);

/* sym: ??0Object_00074D60@@QAE@PAUNode@@HI@Z = 0x00075A30 */

// The node 0x128a (table 0x1CCCD8, destructor 0x74D60), 0x17c bytes.
struct Object_00074D60 {
    Object_00074D60(Node *owner, int id, unsigned int flags);

    char unknown_000[0x17c];
};

// Without a value, fades to black first (func_00024620). Unless node 0x128a exists: stores the value as setting 0x1a9
// and makes the node under node 0 (flags 0x10003).
void func_00075DE0(Node *node, int value)
{
    if (!value) {
        func_00024620(0xff000000, 1.0f / 12.0f);
    }
    if (!data_0022FCE0->func_000128C0(0x128a)) {
        data_0022FCE0->func_000127C0(0x1a9, value);
        new Object_00074D60((Node *)data_0022FCE0->func_000128C0(0), 0x128a, 0x10003);
    }
}
