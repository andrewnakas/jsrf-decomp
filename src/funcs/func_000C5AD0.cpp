struct Game {
    void *func_000128C0(int id);
};

struct Object_000C0690 {
    void func_000C0690(int amount);
};

extern Game *data_0022FCE0;

// The owner at 0x4 of the Object_000CC600 family.
struct Object_000C5B50 {
    char unknown_00[0x98];
    int value_98;

    void func_000C5AD0(int amount);
};

// Adds the amount to object 0x12b1's total (func_000C0690) and takes it from the field at 0x98, which stops at 0.
void Object_000C5B50::func_000C5AD0(int amount)
{
    Object_000C0690 *total = (Object_000C0690 *)data_0022FCE0->func_000128C0(0x12b1);
    if (total) {
        total->func_000C0690(amount);
    }
    if ((value_98 -= amount) < 0) {
        value_98 = 0;
    }
}
