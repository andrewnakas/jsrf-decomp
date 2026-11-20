/* fuzzy: 78.3 */
struct Game {
    void *func_000128C0(int id);
};

struct Target_000C05F0 {
    char unknown_00[0xa4];
    unsigned int flags;
};

struct Object_000C05F0 {
    int func_000C06D0(int id);
};

extern Game *data_0022FCE0;

// Flag 0x10000 of the object with the given id; true when it does not exist. Does not read `this`:
// func_00056990 loads `ecx` before each call (`ret 4`).
// Not matching yet: retail reads the whole word at 0xa4 and shifts it right by 16 (0xc06e4-0xc06ea);
// every form tried so far compiles to a byte load of 0xa6.
int Object_000C05F0::func_000C06D0(int id)
{
    Target_000C05F0 *target = (Target_000C05F0 *)data_0022FCE0->func_000128C0(id);
    if (target) {
        return (target->flags >> 16) & 1;
    }
    return 1;
}
