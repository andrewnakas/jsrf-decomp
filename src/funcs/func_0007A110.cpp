int func_00119540(int group, int index, void *position);

// Built by 0x7A8B0 (state at +0xf0, cursor at +0xd4).
struct Object_00079B50 {
    char unknown_000[0xd4];
    int cursor;
    int target;
    char unknown_0dc[4];
    int colour[3];
    int fade;
    int state;

    void func_0007A110();
};

// Called by 0x7A170 and 0x7A4E0. In state 3: moves the target to the entry after the cursor (wrapping to 0), sets the
// colour at +0xe0 to white, clears +0xec, goes to state 4 and plays sound 8 / 3.
void Object_00079B50::func_0007A110()
{
    if (state == 3) {
        target = cursor + 1;
        if (target > 2) {
            target = 0;
        }
        for (int i = 0; i < 3; i++) {
            colour[i] = 0xff;
        }
        fade = 0;
        state = 4;
        func_00119540(8, 3, 0);
    }
}
