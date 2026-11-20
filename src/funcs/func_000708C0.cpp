// The class whose table is at 0x1CCA80 (constructor 0x70E30, destructor 0x71040).
struct Object_00071040 {
    char unknown_000[0xa0];
    int states[4];
    char unknown_0b0[0x450];
    int used[4];
    int joined[4];

    int func_000708C0();
};

// Called by slot 1 (0x71CB0): whether as many ports are in state 1 (+0xa0) as are in use or joined (+0x500,
// +0x510).
int Object_00071040::func_000708C0()
{
    int result = 0;
    int active = 0;
    for (int i = 0; i < 4; i++) {
        if (used[i] || joined[i]) {
            active++;
        }
    }
    int ready = 0;
    for (int j = 0; j < 4; j++) {
        if (states[j] == 1) {
            ready++;
        }
    }
    if (ready == active) {
        result = 1;
    }
    return result;
}
