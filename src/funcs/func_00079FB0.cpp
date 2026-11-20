// One of the four controller slots at data_00251E1C (0x40 bytes each).
struct Slot_001116E0 {
    int busy;
    char unknown_04[0x3c];
};

struct Game {
    int func_000127E0(int index);
};

extern Game *data_0022FCE0;
extern Slot_001116E0 data_00251E1C[4];
extern int data_00251F20;

void func_0006F650(int slot);

// Built by 0x7A8B0 (state at +0xf0).
struct Object_00079B50 {
    char unknown_000[0xf0];
    int state;

    int func_00079FB0();
};

// Called by slot 13 (0x7AB40). Finds the first controller slot whose game value 0x1bc + i is positive and that is not
// busy: opens it (func_0006F650), makes it the current slot (data_00251F20), goes to state 7 and returns 1; 0 when
// there is none.
int Object_00079B50::func_00079FB0()
{
    for (int i = 0; i < 4; i++) {
        if (data_0022FCE0->func_000127E0(i + 0x1bc) > 0 && data_00251E1C[i].busy == 0) {
            func_0006F650(i);
            data_00251F20 = i;
            state = 7;
            return 1;
        }
    }
    return 0;
}
