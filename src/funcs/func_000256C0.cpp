struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000265A0 {
};

extern int (Object_000265A0::*data_001EC178[0x21])(int argument);

// Asks object 7 through its second handler table; 1 when the action has no handler there, 0 when there is no such action.
int func_000256C0(unsigned int index, int argument)
{
    Object_000265A0 *object = (Object_000265A0 *)data_0022FCE0->func_000128C0(7);
    if (index < 0x21) {
        return data_001EC178[index] ? (object->*data_001EC178[index])(argument) : 1;
    }
    return 0;
}
