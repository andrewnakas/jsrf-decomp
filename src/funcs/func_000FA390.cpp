struct Info_000FA390 {
    char unknown_00[0x1c];
    int shared;
};

// Object 9.
struct Stage_000FA390 {
    char unknown_0000[0x1040];
    Info_000FA390 *info;
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

// The child of Node whose table is at 0x1D08A0 (constructor func_000F98B0); its phase is at 0x7c.
struct Object_000F98B0 {
    char unknown_00[0x7c];
    int phase;

    int func_000FA390();
};

// Called by slot 1 (func_000FA460) in phase 1: finds a free controller slot (the current one, or with object 9's
// info shared, the first whose game value 0x1bc + i is positive), opens it (func_0006F5B0) and moves to phase 2,
// returning 1. 0 when there is none.
int Object_000F98B0::func_000FA390()
{
    Stage_000FA390 *stage = (Stage_000FA390 *)data_0022FCE0->func_000128C0(9);
    if (stage) {
        if (stage->info->shared == 0) {
            if (data_00251E1C[data_00251F20].busy == 0) {
                func_0006F5B0(data_00251F20);
                phase = 2;
                return 1;
            }
        } else {
            for (int i = 0; i < 4; i++) {
                if (data_0022FCE0->func_000127E0(i + 0x1bc) > 0 && data_00251E1C[i].busy == 0) {
                    func_0006F5B0(i);
                    phase = 2;
                    return 1;
                }
            }
        }
    }
    return 0;
}
