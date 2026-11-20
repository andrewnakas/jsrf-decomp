/* sym: ??0Object_0004ABA0@@QAE@PAUNode@@HIHHH@Z = 0x0004A910 */

struct Node;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Owner_0004E930 {
    char unknown_00[0x50];
    int child;
};

// The state object of the table at 0x1F9888 (0x1070 bytes; table 0x1CAAB0).
struct Object_0004ABA0 {
    Object_0004ABA0(Node *owner, int id, unsigned int flags, int first, int second, int third);

    char unknown_0000[0x1070];
};

// Creates state object 0x9 under object 8 with three values, and notes it there (+0x50).
void func_0004E930(int first, int second, int third)
{
    Owner_0004E930 *owner = (Owner_0004E930 *)data_0022FCE0->func_000128C0(8);
    if (owner) {
        new Object_0004ABA0((Node *)owner, 0x9, 0, first, second, third);
        owner->child = 0x9;
    }
}
