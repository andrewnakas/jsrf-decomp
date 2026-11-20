struct Pair_0003EDA0 {
    int unknown_00;
    int id;
};

struct Target_0003EDA0 {
    char unknown_00[0x60];
    int value;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_0003EDA0 {
    char unknown_00[0x50];
    Pair_0003EDA0 *pairs;
    unsigned int count;

    void func_0003EDA0(int value);
};

// Hands a value (+0x60) to the object of every pair whose first word is clear.
void Object_0003EDA0::func_0003EDA0(int value)
{
    for (unsigned int i = 0; i < count; i++) {
        if (!pairs[i].unknown_00) {
            Target_0003EDA0 *target = (Target_0003EDA0 *)data_0022FCE0->func_000128C0(pairs[i].id);
            if (target) {
                target->value = value;
            }
        }
    }
}
