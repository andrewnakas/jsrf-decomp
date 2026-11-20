// One of the 28 cells at +0x68 (0x14 bytes): its corners and kind.
struct Cell_00138100 {
    int left;
    int top;
    int right;
    int bottom;
    int kind;
};

struct Object_001379E0 {
    char unknown_000[0x68];
    Cell_00138100 cells[28];

    void func_00138100();
};

// Lays out the 28 cells at +0x68 (left, top, right, bottom; the kind is left alone): rows of 2 and 5 cells 37
// pixels apart from x 67, three rows of 3 cells 41 apart from x 272 and 394, two rows of 4 cells from x 67 and a
// last row of 4 cells 85 wide, 94 apart from x 68.
void Object_001379E0::func_00138100()
{
    unsigned int i;
    for (i = 0; i < 2; i++) {
        cells[i].left = 67 + i * 37;
        cells[i].top = 74;
        cells[i].right = 104 + i * 37;
        cells[i].bottom = 111;
    }
    for (i = 0; i < 5; i++) {
        cells[2 + i].left = 67 + i * 37;
        cells[2 + i].top = 175;
        cells[2 + i].right = 104 + i * 37;
        cells[2 + i].bottom = 212;
    }
    for (i = 0; i < 3; i++) {
        cells[7 + i].left = 272 + i * 41;
        cells[7 + i].top = 264;
        cells[7 + i].right = 309 + i * 41;
        cells[7 + i].bottom = 301;
    }
    for (i = 0; i < 3; i++) {
        cells[10 + i].left = 272 + i * 41;
        cells[10 + i].top = 304;
        cells[10 + i].right = 309 + i * 41;
        cells[10 + i].bottom = 341;
    }
    for (i = 0; i < 3; i++) {
        cells[13 + i].left = 394 + i * 41;
        cells[13 + i].top = 304;
        cells[13 + i].right = 431 + i * 41;
        cells[13 + i].bottom = 341;
    }
    for (i = 0; i < 4; i++) {
        cells[16 + i].left = 67 + i * 37;
        cells[16 + i].top = 277;
        cells[16 + i].right = 104 + i * 37;
        cells[16 + i].bottom = 314;
    }
    for (i = 0; i < 4; i++) {
        cells[20 + i].left = 67 + i * 37;
        cells[20 + i].top = 277;
        cells[20 + i].right = 104 + i * 37;
        cells[20 + i].bottom = 314;
    }
    for (i = 0; i < 4; i++) {
        cells[24 + i].left = 68 + i * 94;
        cells[24 + i].top = 352;
        cells[24 + i].right = 153 + i * 94;
        cells[24 + i].bottom = 434;
    }
}
