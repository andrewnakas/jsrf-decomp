int func_000FE620(int index);
void func_000FE5E0(int index);

struct Object_0004ABA0 {
    char unknown_000[0x5c];
    int state;
    char unknown_060[0x228];
    unsigned int unknown_288;
    unsigned int unknown_28c;

    void func_0004B3E0();
};

// State handler 43 of the table at 0x1F9888, by func_000FE620 (2): 0 moves to state 0x2c; 1 counts +0x28c down and, at 0,
// runs func_000FE5E0 (2) and reloads it from +0x288; 3 counts +0x288 down and moves to state 0x2c at 0.
void Object_0004ABA0::func_0004B3E0()
{
    switch (func_000FE620(2)) {
    case 0:
        state = 0x2c;
        break;
    case 1:
        if (unknown_28c > 0) {
            unknown_28c--;
        } else {
            func_000FE5E0(2);
            unknown_28c = unknown_288;
        }
        break;
    case 3:
        if (unknown_288 > 0)
            unknown_288--;
        else
            state = 0x2c;
        break;
    }
}
