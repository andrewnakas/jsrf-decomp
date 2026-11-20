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

    int func_000792F0(int page, int start, int stop);
    void func_00079440();
};

// Called by 0x79740. In mode 0 (+0x458) moves the chosen cell of page 0 on to the next one that can be chosen (wrapping
// to the first); in mode 1 follows links[3] from the chosen cell of page 1 (func_000792F0 takes over when the walk
// comes back). Plays sound 8 / 3 in every mode.
void Object_000780F0::func_00079440()
{
    switch (mode) {
    case 1: {
        Cell_000791C0 *cells = pages[1];
        Cursor_00079360 *c = cursors;
        int start = c[1].index;
        int i = cells[start].links[3];
        Cell_000791C0 *cell;
        while (!(cell = &cells[i])->enabled) {
            i = cell->links[3];
            if (i == start) {
                i = func_000792F0(1, cells[start].links[3], start);
                break;
            }
        }
        c[1].index = i;
        break;
    }
    case 0: {
        Cursor_00079360 *c = cursors;
        int i = c->index + 1;
        if (i >= c->count) {
            i = 0;
        }
        Cell_000791C0 *cells = pages[0];
        while (!cells[i].enabled) {
            if (++i >= c->count) {
                i = 0;
            }
        }
        c->index = i;
        break;
    }
    }
    func_00119540(8, 3, 0);
}
