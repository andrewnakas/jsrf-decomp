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

// The two-cell page at 0x20D200 and the four-cell page at 0x20D1A0 that the first page is copied from.
struct Page2_000777A0 {
    Cell_000791C0 cells[2];
};

struct Page4_000777A0 {
    Cell_000791C0 cells[4];
};

extern Page2_000777A0 data_0020D200;
extern Page4_000777A0 data_0020D1A0;

// What +0x1c4 points at (func_0004EA50): its kind first.
struct Profile_000777A0 {
    int kind;
};

void *operator new(unsigned int size);

struct Object_000780F0 {
    char unknown_000[0xa0];
    Cursor_00079360 *cursors;
    Cell_000791C0 *pages[4];
    char unknown_0b4[0x110];
    Profile_000777A0 *profile;
    char unknown_1c8[0x28c];
    int mode;
    int page;

    void func_000777A0();
};

// Builds the first menu page for the mode at +0x454: mode 2 copies the two cells at 0x20D200 (the second one disabled
// for profile kinds 2 and 8) and chooses the first; modes 1 and 0 copy the four cells at 0x20D1A0 (mode 0 disabling
// the first two) and choose the fourth.
void Object_000780F0::func_000777A0()
{
    switch (mode) {
    case 2:
        cursors->count = 2;
        pages[0] = (Cell_000791C0 *)operator new(0x40);
        *(Page2_000777A0 *)pages[0] = data_0020D200;
        switch (profile->kind) {
        case 2:
        case 8:
            pages[0][1].enabled = 0;
        }
        cursors[page].index = 0;
        break;
    case 1:
        cursors->count = 4;
        pages[0] = (Cell_000791C0 *)operator new(0x80);
        *(Page4_000777A0 *)pages[0] = data_0020D1A0;
        cursors[page].index = 3;
        break;
    case 0:
        cursors->count = 4;
        pages[0] = (Cell_000791C0 *)operator new(0x80);
        *(Page4_000777A0 *)pages[0] = data_0020D1A0;
        pages[0][0].enabled = 0;
        pages[0][1].enabled = 0;
        cursors[page].index = 3;
        break;
    }
}
