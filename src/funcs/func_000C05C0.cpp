struct Game {
    void *func_000128C0(int id);
};

struct Target_000C05C0 {
    char unknown_00[0xa4];
    unsigned int flags;
};

struct Object_000C0650 {
    void func_000C05C0(int id);
};

extern Game *data_0022FCE0;

// Sets flag 0x800 on the object with the given id. Does not read `this` (`ret 4`).
void Object_000C0650::func_000C05C0(int id)
{
    Target_000C05C0 *target = (Target_000C05C0 *)data_0022FCE0->func_000128C0(id);
    if (target) {
        target->flags |= 0x800;
    }
}
