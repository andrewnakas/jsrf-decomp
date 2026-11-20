struct Game {
    void *func_000128C0(int id);
};

struct Object_00107B20 {
    char unknown_0000[0x8c];
    int target_id;
    char unknown_0090[0x1670];
    unsigned int flags;

    int func_00107B20();
};

extern Game *data_0022FCE0;

// True when the object whose id is at 0x8c does not exist and the top flag bit at 0x1700 is set.
int Object_00107B20::func_00107B20()
{
    if (!data_0022FCE0->func_000128C0(target_id) && (flags & 0x80000000)) {
        return 1;
    }
    return 0;
}
