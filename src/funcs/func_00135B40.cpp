// The word 4 bytes before each port of data_00251DE8: the buttons held long enough to repeat.
struct Entry_00251DE4 {
    unsigned int repeat;
    char unknown_04[0x3c];
};

// Member slot of the 0x1DE828 class (0x38 bytes).
struct Slot_00135B40 {
    int state;
    int choice;
    int value_08;
    int value_0c;
    int id;
    int value_14;
    int value_18;
    int values[4];
    int value_2c;
    char unknown_30[4];
    int value_34;
};

// Two rows of five per slot (0x30 bytes).
struct Link_00135B40 {
    int first[6];
    int second[6];
};

// The repeat counts of a port's buttons 0x1000, 0x2000, 0x4000 and 0x8000.
struct Counts_00135B40 {
    unsigned int counts[4];
};

struct Object_00134880 {
    char unknown_000[0x54c];
    Slot_00135B40 slots[4];
    Link_00135B40 links[4];
    Counts_00135B40 repeats[4];

    void func_001354C0(int port);
    void func_00135640(int player);
    void func_001358B0(int port);
    void func_00135B40(int index);
};

extern Entry_00251DE4 data_00251DE4[];
extern int data_0022C6E4[];
extern int data_0022C718[4][5];

// Member of the 0x1DE828 class: counts how long the port has held buttons 0x1000-0x8000 (+0x6EC) when its slot has an
// id (+0x10), then runs the slot by its state: 0 sets it up (state 2, or 5 without an id; the rows at +0x62C from
// data_0022C718, -1 without a positive id), 1 runs func_00135640, 2 func_001354C0 and 4 func_001358B0.
void Object_00134880::func_00135B40(int index)
{
    int id = slots[index].id;
    if (id >= 0) {
        if (data_00251DE4[data_0022C6E4[index]].repeat & 0x1000) {
            repeats[index].counts[0]++;
        } else {
            repeats[index].counts[0] = 0;
        }
        if (data_00251DE4[data_0022C6E4[index]].repeat & 0x2000) {
            repeats[index].counts[1]++;
        } else {
            repeats[index].counts[1] = 0;
        }
        if (data_00251DE4[data_0022C6E4[index]].repeat & 0x4000) {
            repeats[index].counts[2]++;
        } else {
            repeats[index].counts[2] = 0;
        }
        if (data_00251DE4[data_0022C6E4[index]].repeat & 0x8000) {
            repeats[index].counts[3]++;
        } else {
            repeats[index].counts[3] = 0;
        }
    }
    switch (slots[index].state) {
    case 0:
        slots[index].state = id < 0 ? 5 : 2;
        slots[index].value_08 = 8;
        slots[index].value_2c = -1;
        slots[index].value_34 = 8;
        slots[index].value_14 = 0;
        slots[index].value_18 = 0;
        slots[index].choice = 0;
        slots[index].value_0c = -1;
        slots[index].values[0] = -1;
        slots[index].values[1] = -1;
        slots[index].values[2] = -1;
        slots[index].values[3] = -1;
        for (int i = 0; i < 5; i++) {
            links[index].first[i] = -1;
            links[index].second[i] = data_0022C718[index][i];
            if (slots[index].id <= 0) {
                links[index].second[i] = -1;
            }
        }
        break;
    case 1:
        func_00135640(index);
        break;
    case 2:
        func_001354C0(index);
        break;
    case 4:
        func_001358B0(index);
        break;
    }
}
