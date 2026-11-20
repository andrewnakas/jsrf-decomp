struct Game {
    void *func_000128C0(int id);
};

struct Object_000607B0 {
    void func_00060810(int handle);
};

extern Game *data_0022FCE0;

// The objects whose state handlers fill the table at 0x2165F4 to 0x216660 (func_000CE1A0, func_000CE220,
// func_000CEF60, func_000CF010, ...).
struct Object_000CE220 {
    char unknown_00[8];
    int state;
    char unknown_0c[0x128];
    int handle;

    void func_000CE260();
};

// A state handler: state 28; object 0xe8 drops the handle at 0x134 (func_00060810), which is unset.
void Object_000CE220::func_000CE260()
{
    state = 28;
    Object_000607B0 *target = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (target) {
        target->func_00060810(handle);
    }
    handle = -1;
}
