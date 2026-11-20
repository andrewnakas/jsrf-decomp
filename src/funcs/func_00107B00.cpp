struct Game {
    void *func_000128C0(int id);
};

struct Object_000A4C00 {
    void func_000A4C10(const void *settings);
};

// The objects with ids 0x115e to 0x1162: func_00106F70 looks one up by id and calls func_00107B20 on it, as
// func_00107190 and func_00106F10 call func_00109850 and func_00109300.
struct Object_00107FE0 {
    char unknown_0000[0x16b8];
    int view_id;

    void func_00107B00(const void *settings);
};

extern Game *data_0022FCE0;

// Passes the settings on to func_000A4C10 of the object whose id is at 0x16b8, when it exists.
void Object_00107FE0::func_00107B00(const void *settings)
{
    Object_000A4C00 *view = (Object_000A4C00 *)data_0022FCE0->func_000128C0(view_id);
    if (view) {
        view->func_000A4C10(settings);
    }
}
