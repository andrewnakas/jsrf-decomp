struct Game {
    void *func_000128C0(int id);
};

struct Target_000C05F0 {
    char unknown_00[0xa4];
    unsigned int flags;
};

struct Object_000C05F0 {
    int func_000C06A0(int id);
};

extern Game *data_0022FCE0;

/* const: 0x10000 */
// True when the object with the given id exists and has flag 0x10000. Does not read `this`: func_00056990
// loads `ecx` before each call (`ret 4`).
int Object_000C05F0::func_000C06A0(int id)
{
    Target_000C05F0 *target = (Target_000C05F0 *)data_0022FCE0->func_000128C0(id);
    if (target && (target->flags & 0x10000)) {
        return 1;
    }
    return 0;
}
