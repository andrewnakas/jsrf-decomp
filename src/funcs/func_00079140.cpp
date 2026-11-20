int func_00119540(int group, int index, void *position);

struct Object_000780F0 {
    char unknown_000[0x144];
    int active;
    int selection;
    char unknown_14c[0x308];
    int mode;
    int busy;

    void func_00077C30(int index, int selected);
    void func_00079140();
};

// Not referenced. When the object is active, not busy (+0x458) and in mode 0 or 1: deselects the choice at +0x148
// (func_00077C30), moves to the next of the two choices (wrapping), plays sound 8 / 8 and selects it.
void Object_000780F0::func_00079140()
{
    if (busy == 0 && active != 0 && (mode == 0 || mode == 1)) {
        func_00077C30(selection, 0);
        if (++selection > 1) {
            selection = 0;
        }
        func_00119540(8, 8, 0);
        func_00077C30(selection, 1);
    }
}
