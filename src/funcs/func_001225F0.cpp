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

    void func_001225F0(int player);
};

extern Piece_001225F0 data_00258C88[15];
extern Count_001225F0 data_00258F58;

// Restores a player's 15 pieces and counter from the copies at data_00258C88 and data_00258F58.
void Object_00120420::func_001225F0(int player)
{
    for (int j = 0; j < 15; j++) {
        pieces[player][j].id = data_00258C88[j].id;
        pieces[player][j].x = data_00258C88[j].x;
        pieces[player][j].y = data_00258C88[j].y;
        pieces[player][j].scale = data_00258C88[j].scale;
        pieces[player][j].value_18 = data_00258C88[j].value_18;
        pieces[player][j].value_1c = data_00258C88[j].value_1c;
        pieces[player][j].value_20 = data_00258C88[j].value_20;
        pieces[player][j].colors[0] = data_00258C88[j].colors[0];
        pieces[player][j].colors[1] = data_00258C88[j].colors[1];
        pieces[player][j].colors[2] = data_00258C88[j].colors[2];
        pieces[player][j].value_06 = data_00258C88[j].value_06;
        pieces[player][j].value_08 = data_00258C88[j].value_08;
        pieces[player][j].flag = data_00258C88[j].flag;
    }
    counts[player].value_00 = data_00258F58.value_00;
    counts[player].value_04 = data_00258F58.value_04;
    counts[player].value_08 = data_00258F58.value_08;
    counts[player].state = data_00258F58.state;
}
