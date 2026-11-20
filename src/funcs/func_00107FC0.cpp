struct Game {
    void *func_000128C0(int id);
};

// The object func_00108870 creates for an Object_00107FE0 and whose id it keeps at that object's 0x50 (constructor
// func_00109900, table 0x1D2060; the constructor sets 0x74-0x7c and -1 at 0x80).
struct Object_00109B60 {
    void func_00109FA0(int mode);
};

struct Object_00107FE0 {
    char unknown_00[0x50];
    int targetId;

    void func_00107FC0(int mode);
};

extern Game *data_0022FCE0;

// Passes the mode on to func_00109FA0 of the object whose id is at 0x50, when it exists.
void Object_00107FE0::func_00107FC0(int mode)
{
    Object_00109B60 *target = (Object_00109B60 *)data_0022FCE0->func_000128C0(targetId);
    if (target) {
        target->func_00109FA0(mode);
    }
}
