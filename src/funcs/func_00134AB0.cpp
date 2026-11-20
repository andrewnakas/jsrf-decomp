struct Slot_00134AB0 {
    int value_00;
    char unknown_04[0xc];
    int id;
    char unknown_14[0x24];
};

struct Game {
    int func_000127E0(int index);
};

struct Object_00134880 {
    char unknown_000[0x54c];
    Slot_00134AB0 slots[4];

    void func_00134970();
    void func_00134AB0();
    void func_00135B40(int index);
    void func_001365F0();
    void func_00136720();
};

extern Game *data_0022FCE0;

// Member of the 0x1DE828 class: takes the ids of its four slots from game values 0x1bc to 0x1bf (-1 for 0 and for
// values from 0xff000000 on), clears and sets up each slot (func_00135B40), then runs func_001365F0,
// func_00136720 and func_00134970.
void Object_00134880::func_00134AB0()
{
    int i;
    for (i = 0; i < 4; i++) {
        unsigned int value = data_0022FCE0->func_000127E0(i + 0x1bc);
        if (value >= 0xff000000) {
            slots[i].id = -1;
        } else if (value == 0) {
            slots[i].id = -1;
        } else {
            slots[i].id = value;
        }
    }
    for (i = 0; i < 4; i++) {
        slots[i].value_00 = 0;
        func_00135B40(i);
    }
    func_001365F0();
    func_00136720();
    func_00134970();
}
