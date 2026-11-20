int func_000FE620(int index);
void func_000FE5E0(int index);

struct Object_0004ABA0 {
    char unknown_000[0x5c];
    int state;
    char unknown_060[0x20c];
    unsigned int unknown_26c;
    unsigned int unknown_270;

    void func_0004B290();
};

// State handler 39 of the table at 0x1F9888, by func_000FE620 (0): 0 moves to state 0x28; 1 counts +0x270 down and, at 0,
// runs func_000FE5E0 (0) and reloads it from +0x26c; 3 counts +0x26c down and moves to state 0x28 at 0.
void Object_0004ABA0::func_0004B290()
{
    switch (func_000FE620(0)) {
    case 0:
        state = 0x28;
        break;
    case 1:
        if (unknown_270 > 0) {
            unknown_270--;
        } else {
            func_000FE5E0(0);
            unknown_270 = unknown_26c;
        }
        break;
    case 3:
        if (unknown_26c > 0)
            unknown_26c--;
        else
            state = 0x28;
        break;
    }
}
