int func_000FE620(int index);
void func_000FE5E0(int index);

struct Object_0004ABA0 {
    char unknown_000[0x5c];
    int state;
    char unknown_060[0x1f0];
    unsigned int unknown_250;
    unsigned int unknown_254;

    void func_0004B140();
};

// State handler 35 of the table at 0x1F9888, by func_000FE620 (1): 0 moves to state 0x24; 1 counts +0x254 down and, at 0,
// runs func_000FE5E0 (1) and reloads it from +0x250; 3 counts +0x250 down and moves to state 0x24 at 0.
void Object_0004ABA0::func_0004B140()
{
    switch (func_000FE620(1)) {
    case 0:
        state = 0x24;
        break;
    case 1:
        if (unknown_254 > 0) {
            unknown_254--;
        } else {
            func_000FE5E0(1);
            unknown_254 = unknown_250;
        }
        break;
    case 3:
        if (unknown_250 > 0)
            unknown_250--;
        else
            state = 0x24;
        break;
    }
}
