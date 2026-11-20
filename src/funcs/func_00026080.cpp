struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000265A0;

extern void (Object_000265A0::*data_001EC288[])(int argument);

// Object 7.
struct Object_000265A0 {
    char unknown_00[0x44];
    int pending;
    unsigned int handler;
    int argument;

    void func_000255C0();
};

// When object 7 has a call pending (+0x44), runs func_000255C0 and the pending handler (+0x48, table 0x1EC288) with
// its argument (+0x4c), then clears the request.
void func_00026080()
{
    Object_000265A0 *object = (Object_000265A0 *)data_0022FCE0->func_000128C0(7);
    if (object->pending == 1) {
        object->func_000255C0();
        if (object->handler < 0x21) {
            if (data_001EC288[object->handler]) {
                (object->*data_001EC288[object->handler])(object->argument);
            }
            object->pending = 0;
        }
    }
}
