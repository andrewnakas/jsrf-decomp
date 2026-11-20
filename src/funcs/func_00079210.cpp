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
    int func_00079210(int page, int start, int stop);
};

// Called by 0x79630. The cell `start` of the page when it can be chosen; else follows links[3] to the first cell
// that can, or gives up with `stop` when the walk reaches it; when the walk comes back to `start`, func_000791C0
// carries on from its links[1].
int Object_000780F0::func_00079210(int page, int start, int stop)
{
    int i = start;
    while (!pages[page][i].enabled) {
        i = pages[page][i].links[3];
        if (i == stop) {
            return stop;
        }
        if (i == start) {
            return func_000791C0(page, pages[page][start].links[1], stop);
        }
    }
    return i;
}
