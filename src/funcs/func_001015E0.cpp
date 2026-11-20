// The Node child whose table is at 0x1D1D48 (constructor func_00100F40, which runs the handlers of
// data_0021FF98 by the phase at 0x44).
struct Object_00101180 {
    char unknown_00[0x48];
    int state;
    char unknown_4c[8];
    int pending;

    void func_001015E0();
};

// Entry 5 of data_0021FF98: clears the pending flag; when it was already clear, moves to state 6.
void Object_00101180::func_001015E0()
{
    if (pending != 0) {
        pending = 0;
    } else {
        pending = 0;
        state = 6;
    }
}
