/* sym: ??0Object_00086060@@QAE@PAUNode@@HI@Z = 0x00085280 */

struct Node;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The class whose table is at 0x1CD0C0 (0x170 bytes).
struct Object_00086060 {
    Object_00086060(Node *owner, int id, unsigned int flags);

    char unknown_000[0x170];
};

// Creates an object of the class at 0x1CD0C0 under an owner (object 9 when none is given).
void func_00086110(void *owner, int id)
{
    if (!owner) {
        owner = data_0022FCE0->func_000128C0(9);
    }
    new Object_00086060((Node *)owner, id, 0);
}
