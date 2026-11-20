struct Game {
    void *func_000128C0(int id);
};

// A child that object 0x1165 keeps by id (flags at 0x80).
struct Child_000FE480 {
    char unknown_00[0x80];
    unsigned int flags;
};

// Object 0x1165 (constructor func_000FE740, destructor func_000FDF30).
struct Object_000FDF30 {
    char unknown_000[0xa4];
    int ids[7];

    int func_000FE480(int index);
};

extern Game *data_0022FCE0;

// The state of the child whose id is entry `index` of the list at 0xa4: 0 when there is none (a stale id is
// cleared), 2 without flag bit 25, else 3 or 1 by bit 24.
int Object_000FDF30::func_000FE480(int index)
{
    int id = ids[index];
    if (id != -1) {
        Child_000FE480 *child = (Child_000FE480 *)data_0022FCE0->func_000128C0(id);
        if (child) {
            unsigned int flags = child->flags;
            if (flags & 0x2000000) {
                return (flags & 0x1000000) ? 3 : 1;
            }
            return 2;
        }
        ids[index] = -1;
    }
    return 0;
}
