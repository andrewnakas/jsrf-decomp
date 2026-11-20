// A 32-byte cell of one of Object_000780F0's menu pages: +8 is non-zero for a cell that can be chosen, +0x10..+0x1c
// hold the indices of four neighbouring cells.
struct Cell_000791C0 {
    char unknown_00[8];
    int enabled;
    char unknown_0c[4];
    int links[4];
};

struct Object_000780F0 {
    char unknown_000[0xa4];
    Cell_000791C0 *pages[2];

    int func_000791C0(int page, int start, int stop);
};

// Called by 0x79210, 0x79280, 0x792F0 and 0x79520. From the cell `start` of the page, follows links[3] to the first
// cell that can be chosen; when the walk comes back to `start`, starts again from its links[0]. Gives up with `stop`
// when the walk reaches it.
int Object_000780F0::func_000791C0(int page, int start, int stop)
{
    Cell_000791C0 *cells = pages[page];
    for (;;) {
        int i = start;
        do {
            if (cells[i].enabled) {
                return i;
            }
            i = cells[i].links[3];
            if (i == stop) {
                return stop;
            }
        } while (i != start);
        start = cells[start].links[0];
    }
}
