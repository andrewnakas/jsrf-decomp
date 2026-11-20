struct Game {
    void *func_000128C0(int id);
};

struct Target_000C0650 {
    char unknown_00[0xa4];
    unsigned int flags;
};

struct Object_000C0650 {
    void func_000C0650(int id);
};

extern Game *data_0022FCE0;

// Sets flag 0x10 on the object with the given id. func_000585E0 calls this with an object in ecx, which is
// not used.
void Object_000C0650::func_000C0650(int id)
{
    Target_000C0650 *target = (Target_000C0650 *)data_0022FCE0->func_000128C0(id);
    if (target) {
        target->flags |= 0x10;
    }
}
