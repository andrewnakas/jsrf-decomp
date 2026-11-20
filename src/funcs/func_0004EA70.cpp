struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Info_0004EA70 {
    char unknown_00[0x14];
    int unknown_14;
};

struct Object_0004EA70 {
    char unknown_0000[0x1040];
    Info_0004EA70 *info;
};

// The complement of the word at +0x14 of object 9's block at +0x1040, or -1 when object 9 does not exist.
int func_0004EA70()
{
    Object_0004EA70 *object = (Object_0004EA70 *)data_0022FCE0->func_000128C0(9);
    int result = -1;
    if (object) {
        result = ~object->info->unknown_14;
    }
    return result;
}
