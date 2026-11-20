struct Object_000F20D0 {
    char unknown_00[8];
    int state;
    int timer;
    int unknown_10;
    int nextState;

    void func_000F20D0();
};

// Counts the timer down and switches to the next state when it runs out.
void Object_000F20D0::func_000F20D0()
{
    if (--timer <= 0) {
        state = nextState;
    }
}
