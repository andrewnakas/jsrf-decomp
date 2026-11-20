struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000265A0 {
};

extern void *(Object_000265A0::*data_001EC200[0x21])(int first, int second, int third);

// Asks object 7 through its third handler table; 0 when the action has no handler there.
void *func_00025700(unsigned int index, int first, int second, int third)
{
    Object_000265A0 *object = (Object_000265A0 *)data_0022FCE0->func_000128C0(7);
    if (index < 0x21 && data_001EC200[index]) {
        return (object->*data_001EC200[index])(first, second, third);
    }
    return 0;
}
