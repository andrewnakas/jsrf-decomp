struct Object_001015E0 {
    char unknown_00[0x48];
    int state;
    char unknown_4c[8];
    int pending;

    void func_001015E0();
};

// Clears the pending flag; when it was already clear, moves to state 6.
void Object_001015E0::func_001015E0()
{
    if (pending != 0) {
        pending = 0;
    } else {
        pending = 0;
        state = 6;
    }
}
