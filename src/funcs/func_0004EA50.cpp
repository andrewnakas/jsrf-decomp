struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Info_0004D460;

struct Object_0004D460 {
    void func_0004D460(Info_0004D460 *info);
};

// Has object 9 fill in an info block (func_0004D460), when it exists.
void func_0004EA50(Info_0004D460 *info)
{
    Object_0004D460 *object = (Object_0004D460 *)data_0022FCE0->func_000128C0(9);
    if (object) {
        object->func_0004D460(info);
    }
}
