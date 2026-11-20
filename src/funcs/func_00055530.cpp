struct Game {
    void *func_000128C0(int index);
    void func_00012930(int index, int value);
};

extern Game *data_0022FCE0;

// Object 9; func_00051780 starts it (1) or carries on (0) once its word at +0x48 is at least 2.
struct Stage_00051780 {
    char unknown_00[0x48];
    unsigned int unknown_48;

    void func_00051780(int restart);
};

// Starts object 9 again when `restart` is set, or carries it on when its word at +0x48 is at least 2; says whether it
// did either.
int func_00055530(int restart)
{
    Stage_00051780 *stage = (Stage_00051780 *)data_0022FCE0->func_000128C0(9);
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
