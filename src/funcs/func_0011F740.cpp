struct Object_00074E50 {
    int func_00074E50(int index);
};

struct Object_0011F740 {
    char unknown_00[0x48];
    int current;
    int shown;
    int pending;
    int previous;
    char unknown_58[0x40];
    int state;

    void func_0011F740();
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
int func_00119540(int group, int index, void *position);

// While an update is pending, reads entry 5 of object 0x128a; when it changed, plays entry 0 of group 8, shows
// the new value, goes to state 2 and clears the pending flag.
void Object_0011F740::func_0011F740()
{
    Object_00074E50 *object = (Object_00074E50 *)data_0022FCE0->func_000128C0(0x128a);
    if (pending) {
        current = object->func_00074E50(5);
        if (previous != current) {
            func_00119540(8, 0, 0);
            shown = current;
            state = 2;
            pending = 0;
        }
    }
}
