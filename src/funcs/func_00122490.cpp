struct Point_001223B0 {
    float x;
    float y;
};

// One of the 15 pieces of a player (0x30 bytes).
struct Piece_001225F0 {
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

struct Count_001225F0 {
    int value_00;
    int value_04;
    int value_08;
    int state;
};

struct Object_00120420 {
    char unknown_0000[0x1dc];
    int layout;
    char unknown_01e0[0xea8];
    Count_001225F0 counts[5];
    char unknown_10d8[0x21a0];
    Piece_001225F0 pieces[5][15];

    void func_00122490(int player);
};

extern Point_001223B0 data_00225DE8[][15];
extern unsigned int data_00226040[];
extern Piece_001225F0 data_00258C88[15];
extern Count_001225F0 data_00258F58;

// Keeps a copy of the 15 pieces and the counter of `player` in data_00258C88 and data_00258F58, then resets them as
// func_001223B0 does (start positions of the layout at +0x1DC, scale 10, the layout's colour; counter state 3).
void Object_00120420::func_00122490(int player)
{
    for (int i = 0; i < 15; i++) {
        data_00258C88[i].id = pieces[player][i].id;
        data_00258C88[i].x = pieces[player][i].x;
        data_00258C88[i].y = pieces[player][i].y;
        data_00258C88[i].scale = pieces[player][i].scale;
        data_00258C88[i].value_18 = pieces[player][i].value_18;
        data_00258C88[i].value_1c = pieces[player][i].value_1c;
        data_00258C88[i].value_20 = pieces[player][i].value_20;
        data_00258C88[i].colors[0] = pieces[player][i].colors[0];
        data_00258C88[i].colors[1] = pieces[player][i].colors[1];
        data_00258C88[i].colors[2] = pieces[player][i].colors[2];
        data_00258C88[i].value_06 = pieces[player][i].value_06;
        data_00258C88[i].value_08 = pieces[player][i].value_08;
        data_00258C88[i].flag = pieces[player][i].flag;
        pieces[player][i].id = -1;
        pieces[player][i].x = data_00225DE8[layout][i].x;
        pieces[player][i].y = data_00225DE8[layout][i].y;
        pieces[player][i].scale = 10.0f;
        pieces[player][i].value_18 = 0;
        pieces[player][i].value_1c = 0;
        pieces[player][i].value_20 = 0;
        pieces[player][i].colors[0] = data_00226040[layout];
        pieces[player][i].colors[1] = data_00226040[layout];
        pieces[player][i].colors[2] = data_00226040[layout];
        pieces[player][i].value_06 = 0;
        pieces[player][i].value_08 = 0;
        pieces[player][i].flag = 0;
    }
    data_00258F58.value_00 = counts[player].value_00;
    data_00258F58.value_04 = counts[player].value_04;
    data_00258F58.value_08 = counts[player].value_08;
    data_00258F58.state = counts[player].state;
    counts[player].value_00 = 0;
    counts[player].value_04 = 0;
    counts[player].value_08 = 0;
    counts[player].state = 3;
}
