// The block func_0004EA50 fills in: two sets of four rows of eight weights at +0x14 and +0x94.
struct Info_0004D460 {
    char unknown_000[0x14];
    unsigned int weights[2][4][8];
    void *unknown_114;
};

void func_0004EA50(Info_0004D460 *info);

extern int data_0020DAFC[8];

// The player.
struct Object_000A1C50 {
    char unknown_000[0xc98];
    int unknown_c98;
    char unknown_c9c[0x328];
    int unknown_fc4;

    unsigned int func_0007F9B0(unsigned int range);
    int func_0008AE00();
};

// Picks one of the eight values at 0x20DAFC by weight: the row is chosen by +0xfc4 - 1 (kept within 0-3) from the
// second set of object 9's block when +0xc98 is negative, else the first; a roll below the row's total
// (func_0007F9B0) selects the entry. 2 when the row is empty.
int Object_000A1C50::func_0008AE00()
{
    int level = unknown_fc4 - 1;
    if (level < 0)
        level = 0;
    else if (level > 3)
        level = 3;
    Info_0004D460 info;
    func_0004EA50(&info);
    unsigned int *row;
    if (unknown_c98 < 0)
        row = info.weights[1][level];
    else
        row = info.weights[0][level];
    unsigned int total = row[7] + row[6] + row[5] + row[4] + row[3] + row[2] + row[1] + row[0];
    if (total) {
        unsigned int roll = func_0007F9B0(total);
        for (unsigned int i = 0; i < 8; i++) {
            if (roll < row[i])
                return data_0020DAFC[i];
            roll -= row[i];
        }
    }
    return 2;
}
