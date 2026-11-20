struct Game {
    void *func_000128C0(int index);
    void func_00012930(int index, int value);
};

extern Game *data_0022FCE0;

// Object 9; func_00051780 starts it (1) or carries on (0) once its word at +0x48 is at least 2.
struct Stage_00051780 {
    char unknown_00[0x48];
    unsigned int unknown_48;

    void func_00051780(int restart);
};

void func_0004EAF0();

struct Object_000667D0 {
    void func_000667D0();
};

extern Object_000667D0 *data_00251F24;

inline Stage_00051780 *stage_00055590()
{
    return (Stage_00051780 *)data_0022FCE0->func_000128C0(9);
}

// As func_0004EA30: object 9 exists and its word at +0x48 is at least 2.
inline int ready_00055590()
{
    Stage_00051780 *stage = stage_00055590();
    return stage && stage->unknown_48 >= 2;
}

// As func_00055530.
inline int start_00055590(int restart)
{
    Stage_00051780 *stage = stage_00055590();
    if (stage) {
        if (restart) {
            stage->func_00051780(1);
            return 1;
        }
        if (stage->unknown_48 >= 2) {
            stage->func_00051780(0);
            return 1;
        }
    }
    return 0;
}

struct Object_0004EF90 {
    char unknown_00[0x44];
    int next;
    int unknown_48;
    int reset;
    int unknown_50;

    void func_00055600();
};

// A state handler (table 0x1FA008): sets game value 9 to 10, resets the game's values if asked, carries object 9 on and
// goes to state 7.
void Object_0004EF90::func_00055600()
{
    data_0022FCE0->func_00012930(9, 10);
    if (reset) {
        func_0004EAF0();
        reset = 0;
    }
    if (start_00055590(0)) {
        unknown_50 = 9;
        next = 7;
        data_00251F24->func_000667D0();
    }
}
