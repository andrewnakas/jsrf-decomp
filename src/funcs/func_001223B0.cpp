struct Point_001223B0 {
    float x;
    float y;
};

// One of the 15 pieces of a player (0x30 bytes).
struct Piece_001223B0 {
    int id;
    unsigned char flag;
    char unknown_05;
    unsigned short value_06;
    unsigned short value_08;
    char unknown_0a[2];
    float x;
    float y;
    float scale;
    int value_18;
    int value_1c;
    int value_20;
    unsigned int colors[3];
};

struct Count_001223B0 {
    int value_00;
    int value_04;
    int value_08;
    int state;
};

struct Object_00120420 {
    char unknown_0000[0x1dc];
    int layout;
    char unknown_01e0[0xea8];
    Count_001223B0 counts[5];
    char unknown_10d8[0x21a0];
    Piece_001223B0 pieces[5][15];

    void func_001223B0();
};

extern Point_001223B0 data_00225DE8[][15];
extern unsigned int data_00226040[];

// Resets the five players' 15 pieces to the start positions of the layout at +0x1DC (data_00225DE8), scale 10
// and the layout's colour (data_00226040), and their counters to state 3.
void Object_00120420::func_001223B0()
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 15; j++) {
            pieces[i][j].id = -1;
            pieces[i][j].x = data_00225DE8[layout][j].x;
            pieces[i][j].y = data_00225DE8[layout][j].y;
            pieces[i][j].scale = 10.0f;
            pieces[i][j].value_18 = 0;
            pieces[i][j].value_1c = 0;
            pieces[i][j].value_20 = 0;
            pieces[i][j].colors[0] = data_00226040[layout];
            pieces[i][j].colors[1] = data_00226040[layout];
            pieces[i][j].colors[2] = data_00226040[layout];
            pieces[i][j].value_06 = 0;
            pieces[i][j].value_08 = 0;
            pieces[i][j].flag = 0;
        }
        counts[i].value_00 = 0;
        counts[i].value_04 = 0;
        counts[i].value_08 = 0;
        counts[i].state = 3;
    }
}
