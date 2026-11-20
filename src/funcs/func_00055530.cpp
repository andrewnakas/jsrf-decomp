struct Game {
    void *func_000128C0(int index);
    void func_00012930(int index, int value);
};

extern Game *data_0022FCE0;

// Object 9 (Object_0004ABA0: 0x51780 sets the state at +0x5c and runs func_0004C960 as state handler 31 does);
// func_00051780 starts it (1) or carries on (0) once its word at +0x48 is at least 2.
struct Object_0004ABA0 {
    char unknown_00[0x48];
    unsigned int unknown_48;

    void func_00051780(int restart);
};

// Starts object 9 again when `restart` is set, or carries it on when its word at +0x48 is at least 2; says whether it
// did either.
int func_00055530(int restart)
{
    Object_0004ABA0 *stage = (Object_0004ABA0 *)data_0022FCE0->func_000128C0(9);
    if (stage) {
        if (restart) {
            stage->func_00051780(1);
            return 1;
        }
        if (stage->unknown_48 >= 2) {
            stage->func_00051780(0);
            return 1;
        }
    }
    return 0;
}
