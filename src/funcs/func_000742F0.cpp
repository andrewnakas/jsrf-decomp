int func_00119540(int group, int index, void *position);

// The node class whose table is at 0x1CCC58 (slot 1 0x74680).
struct Object_00074260 {
    char unknown_00[0x98];
    int timer;
    char unknown_9c[0x1c];
    int enabled[3];
    char unknown_c4[0x1c];
    int choice;

    void func_000742F0();
};

// Called by 0x74460: clears +0x98 and moves the choice (+0xe0) back to the previous enabled one of three (+0xb8),
// jumping to the second when it runs off the start; plays sound 8 / 3.
void Object_00074260::func_000742F0()
{
    timer = 0;
    choice--;
    if (choice < 0) {
        choice = 1;
    }
    while (!enabled[choice]) {
        if (choice < 0) {
            choice = 1;
        } else {
            choice--;
        }
    }
    func_00119540(8, 3, 0);
}
