struct Game {
    void *func_000128C0(int id);
};

struct Object_00107B20 {
    char unknown_0000[0x90];
    int target_id;
    char unknown_0094[0x166c];
    unsigned int flags;
    int value_1704;

    int func_00107B50();
};

extern Game *data_0022FCE0;

// The field at 0x1704 when the object whose id is at 0x90 does not exist and one of the flags 0x50000000 at
// 0x1700 is set; -1 otherwise.
int Object_00107B20::func_00107B50()
{
    if (!data_0022FCE0->func_000128C0(target_id) && (flags & 0x50000000)) {
        return value_1704;
    }
    return -1;
}
