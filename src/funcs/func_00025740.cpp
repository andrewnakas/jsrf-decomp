struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000265A0 {
};

extern void (Object_000265A0::*data_001EC288[0x21])(int argument);

// Runs the handler of action `index` in object 7's fourth table, when it has one.
void func_00025740(unsigned int index, int argument)
{
    Object_000265A0 *object = (Object_000265A0 *)data_0022FCE0->func_000128C0(7);
    if (index < 0x21 && data_001EC288[index]) {
        (object->*data_001EC288[index])(argument);
    }
}
