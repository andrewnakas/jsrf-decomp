struct Game {
    void *func_000128C0(int id);
};

// The object func_00108870 creates for an Object_00107FE0 and whose id it keeps at that object's 0x50 (constructor
// func_00109900, table 0x1D2060; the constructor sets 0x74-0x7c and -1 at 0x80).
struct Object_00109B60 {
    int func_0010A040();
};

struct Object_00107FE0 {
    char unknown_00[0x50];
    int targetId;

    int func_00107FE0();
};

extern Game *data_0022FCE0;

int Object_00107FE0::func_00107FE0()
{
    Object_00109B60 *target = (Object_00109B60 *)data_0022FCE0->func_000128C0(targetId);
    if (target) {
        return target->func_0010A040();
    }
    return 1;
}
