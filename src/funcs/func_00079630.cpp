int func_00119540(int group, int index, void *position);

// A 32-byte cell of one of Object_000780F0's menu pages: +8 is non-zero for a cell that can be chosen, +0x10..+0x1c
// hold the indices of four neighbouring cells.
struct Cell_000791C0 {
    int id;
    char unknown_04[4];
    int enabled;
    int value;
    int links[4];
};

// One record per menu page in the array +0xa0 of Object_000780F0 points at: the number of cells (+4) and the chosen
// one (+8).
struct Cursor_00079360 {
    char unknown_00[4];
    int count;
    int index;
    char unknown_0c[4];
};

struct Object_000780F0 {
    char unknown_000[0xa0];
    Cursor_00079360 *cursors;
    Cell_000791C0 *pages[4];
    char unknown_0b4[0x3a4];
    int mode;

    void func_00077E40(int id, int value, int selected);
    int func_00079210(int page, int start, int stop);
    void func_00079630();
};

// Called by 0x79740. In mode 1 (+0x458) follows links[1] from the chosen cell of page 1 (func_00079210 takes over when
// the walk comes back); in mode 3 clears the highlight (func_00077E40), moves the chosen cell of page 3 on to the next
// one that can be chosen (wrapping to the first) and highlights it. Plays sound 8 / 8 in every mode.
void Object_000780F0::func_00079630()
{
    switch (mode) {
    case 1: {
        Cursor_00079360 *c = cursors;
        Cell_000791C0 *cells = pages[1];
        int start = c[1].index;
        int i = cells[start].links[1];
        Cell_000791C0 *cell;
        while (!(cell = &cells[i])->enabled) {
            i = cell->links[1];
            if (i == start) {
                i = func_00079210(1, cells[start].links[1], start);
                break;
            }
        }
        c[1].index = i;
        break;
    }
    case 3: {
        func_00077E40(0, 0, 0);
        int i = cursors[mode].index + 1;
        if (i >= cursors[mode].count) {
            i = 0;
        }
        Cell_000791C0 *cells = pages[mode];
        while (!cells[i].enabled) {
            if (++i >= cursors[mode].count) {
                i = 0;
            }
        }
        cursors[mode].index = i;
        func_00077E40(pages[mode][i].id, pages[mode][i].value, 1);
        func_00119540(8, 8, 0);
        return;
    }
    }
    func_00119540(8, 8, 0);
}
