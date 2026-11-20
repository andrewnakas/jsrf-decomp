/* sym: ??0Object_001112A0@@QAE@PAUNode@@HIHH@Z = 0x00110EE0 */
struct Node;

struct Game {
    void *func_000128C0(int id);
    void func_000126D0(int value);
};

struct Object_001112A0 {
    Object_001112A0(Node *owner, int id, unsigned int flags, int value, int mode);

    char unknown_00[0xa4];
};

extern Game *data_0022FCE0;

// When object 0x1163 exists: func_000126D0(1) of the game, then an Object_001112A0 under it (id 0x1168, flags
// 0x100) with the value and mode 0.
void func_000FEB90(int value)
{
    Node *object = (Node *)data_0022FCE0->func_000128C0(0x1163);
    if (object) {
        data_0022FCE0->func_000126D0(1);
        new Object_001112A0(object, 0x1168, 0x100, value, 0);
    }
}
