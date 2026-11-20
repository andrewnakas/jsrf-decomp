struct Game {
    void *func_000128C0(int id);
};

struct Object_000FC4D0 {
    void func_000FC4D0(unsigned int mask, int set);
};

struct Object_00107B20 {
    char unknown_0000[0x64];
    int partner_id;
    char unknown_0068[0x1698];
    unsigned int flags;

    void func_00108840();
};

extern Game *data_0022FCE0;

// With flag 0x20000000 at 0x1700 set, sets the same flag (func_000FC4D0) in the object whose id is at 0x64, when
// it exists.
void Object_00107B20::func_00108840()
{
    if (flags & 0x20000000) {
        Object_000FC4D0 *partner = (Object_000FC4D0 *)data_0022FCE0->func_000128C0(partner_id);
        if (partner) {
            partner->func_000FC4D0(0x20000000, 1);
        }
    }
}
