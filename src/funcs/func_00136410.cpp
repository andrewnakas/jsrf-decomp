/* const: 0x80000 */
struct Game {
    int func_000127E0(int index);
};

struct Object_00039BE0 {
    void func_0003A7F0(int row, int column, int value, int page);
    void func_0003A840(int row, int column, int value, int page);
};

// Member slot of the 0x1DE828 class (0x38 bytes); the port's id at +0x10.
struct Slot_00136410 {
    char unknown_00[0x10];
    int id;
    char unknown_14[0x24];
};

// Two rows of five per slot (0x30 bytes).
struct Link_00136410 {
    int first[6];
    int second[6];
};

struct Object_00134880 {
    char unknown_000[0x54c];
    Slot_00136410 slots[4];
    Link_00136410 links[4];

    int func_00136410();
};

extern Game *data_0022FCE0;
extern Object_00039BE0 data_001EFFB0;
extern void *data_0025E358;

// Member of the 0x1DE828 class (its slot 1 ends here): allocates the 512 KB buffer data_0025E358; with game value
// 0x1b5 at 1, swaps the rows of the first port that game values 0x1c0-0x1c3 mark with those of port 0; then hands
// every slot's five entries to data_001EFFB0 (func_0003A7F0 with the second row's value, offset by 0x1c per entry
// when the first row's is negative, and func_0003A840 with 1 or 0), frees the buffer and returns 1.
int Object_00134880::func_00136410()
{
    data_0025E358 = operator new(0x80000);
    if (data_0022FCE0->func_000127E0(0x1b5) == 1) {
        for (unsigned int i = 0; i < 4; i++) {
            if (data_0022FCE0->func_000127E0(i + 0x1c0)) {
                if (i) {
                    Link_00136410 temp;
                    for (unsigned int k = 0; k < 5; k++) {
                        temp.first[k] = links[i].first[k];
                        temp.second[k] = links[i].second[k];
                        links[i].first[k] = links[0].first[k];
                        links[i].second[k] = links[0].second[k];
                        links[0].first[k] = temp.first[k];
                        links[0].second[k] = temp.second[k];
                    }
                }
                break;
            }
        }
    }
    for (unsigned int j = 0; j < 4; j++) {
        for (unsigned int k = 0; k < 5; k++) {
            if (links[j].first[k] >= 0) {
                data_001EFFB0.func_0003A7F0(j, k, links[j].second[k], 1);
                data_001EFFB0.func_0003A840(j, k, 1, 1);
            } else {
                data_001EFFB0.func_0003A7F0(j, k, links[j].second[k] + k * 0x1c, 1);
                data_001EFFB0.func_0003A840(j, k, 0, 1);
            }
        }
    }
    if (data_0025E358) {
        operator delete(data_0025E358);
        data_0025E358 = 0;
    }
    return 1;
}
