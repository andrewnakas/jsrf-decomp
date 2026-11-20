/* sym: ??0Object_000F98B0@@QAE@PAUNode@@HIPAH1HPBDH@Z = 0x000F98B0 */
struct Node;

struct Game {
    void *func_000128C0(int id);
};

// The child that func_000F98B0 constructs (destructor func_000F9A80): it clears *first and sets *second to 1, keeps
// a copy of the text (or of a default one when it is null) and picks its resources by `kind`.
struct Object_000F98B0 {
    Object_000F98B0(Node *owner, int id, unsigned int flags, int *first, int *second, int value, const char *text,
                    int kind);

    char unknown_00[0xd8];
};

extern Game *data_0022FCE0;

// Creates an Object_000F98B0 under object 0x1165 (id -1, flags 0x100) with the two pointers and no text.
void func_000FE6C0(int *first, int *second)
{
    new Object_000F98B0((Node *)data_0022FCE0->func_000128C0(0x1165), -1, 0x100, first, second, 0, 0, 0);
}
