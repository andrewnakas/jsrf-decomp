struct Info_001116E0 {
    char unknown_00[0x1c];
    int shared;
};

// Object 9.
struct Stage_001116E0 {
    char unknown_0000[0x1040];
    Info_001116E0 *info;
};

// One of the four controller slots at data_00251E1C (0x40 bytes each).
struct Slot_001116E0 {
    int busy;
    char unknown_04[0x3c];
};

struct Game {
    void *func_000128C0(int id);
    int func_000127E0(int index);
};

extern Game *data_0022FCE0;
extern Slot_001116E0 data_00251E1C[4];
extern int data_00251F20;

void func_0006F5B0(int slot);

// The class whose table is at 0x1D2788.
struct Object_001112A0 {
    char unknown_00[0x7c];
    int state;
    int previous;

    int func_001116E0();
};

// Finds a free slot (the current one, or with object 9's info shared, the first whose game value 0x1bc + i is
// positive); opens it (func_0006F5B0) and moves to state 3, returning 1. 0 when there is none.
int Object_001112A0::func_001116E0()
{
    Stage_001116E0 *stage = (Stage_001116E0 *)data_0022FCE0->func_000128C0(9);
    if (stage) {
        if (stage->info->shared == 0) {
            if (data_00251E1C[data_00251F20].busy == 0) {
                func_0006F5B0(data_00251F20);
                previous = state;
                state = 3;
                return 1;
            }
        } else {
            for (int i = 0; i < 4; i++) {
                if (data_0022FCE0->func_000127E0(i + 0x1bc) > 0 && data_00251E1C[i].busy == 0) {
                    func_0006F5B0(i);
                    previous = state;
                    state = 3;
                    return 1;
                }
            }
        }
    }
    return 0;
}
