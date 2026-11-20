struct Game {
    void *func_000128C0(int id);
};

struct Target_000C05F0 {
    char unknown_00[0xa4];
    unsigned int flags;
};

struct Object_000C05F0 {
    int func_000C0620(int id);
};

extern Game *data_0022FCE0;

// True unless the object with the given id exists without flag 0x20. Does not read `this`: func_00056990
// loads `ecx` before each call (`ret 4`).
int Object_000C05F0::func_000C0620(int id)
{
    Target_000C05F0 *target = (Target_000C05F0 *)data_0022FCE0->func_000128C0(id);
    if (target && !(target->flags & 0x20)) {
        return 0;
    }
    return 1;
}
