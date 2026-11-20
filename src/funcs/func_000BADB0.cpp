struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000B4150 {
    char unknown_00[0xd0];
    unsigned int flags;

    int func_000B4150(int first, int second, int third, int fourth);
};

struct Object_000BADB0 {
    int func_000BADB0(int id, int first, int second, int third, int fourth);
};

// Forwards the four arguments to func_000B4150 of the object with the id, when it exists and bit 31 of its flags at
// 0xd0 is clear; else 0. Does not read this.
int Object_000BADB0::func_000BADB0(int id, int first, int second, int third, int fourth)
{
    int result = 0;
    Object_000B4150 *object = (Object_000B4150 *)data_0022FCE0->func_000128C0(id);
    if (object && (object->flags & 0x80000000) == 0) {
        result = object->func_000B4150(first, second, third, fourth);
    }
    return result;
}
